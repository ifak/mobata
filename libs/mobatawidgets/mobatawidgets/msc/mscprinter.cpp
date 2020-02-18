#include "mscprinter.hpp"
#include <mobata/model/msc/mscmodel.hpp>
#include <mobata/model/msc/mscmessageitem.hpp>
#include <mobata/model/msc/mscfragmentitem.hpp>
#include <mobata/model/msc/mscfragmentregionitem.hpp>

#include <mobata/model/base/portitem.hpp>

#include <QPixmap>
#include <QLabel>
#include <fstream>

#include <mobata/memory_leak_start.hpp>

static const QString TEMP_TXT_FILE_NAME = "msc.txt";


namespace model {
  namespace msc {

MscPrinter::MscPrinter(const QString &mscDir)
{
  this->mscDir = mscDir;
  mscText = "msc = modern_blue;\n";
}


/** Assume that the msc model only has one sequence as top level.
 *  Get it as item list and process every level iterative.
 */
void
MscPrinter::createPNG(const MscModel &mscModel)
{
  MscSequence const* topLevel = mscModel.sequences().back();
  processLevel(*topLevel);
  endMscCreation();
}


/** Iterate through current sequence level and proceed according
 *  to message or fragment.
 */
void
MscPrinter::processLevel(const MscSequence &currentLevel)
{
  MscSequence::ConstSequenceItems seqItemList = currentLevel.sequenceItems();

  for( int iSI=0; iSI<seqItemList.size(); iSI++ )
  {
    MscSequenceItem const* currentSeqItem = seqItemList.at(iSI);

    if( MscMessageItem const* messageItem = dynamic_cast<MscMessageItem const*>(currentSeqItem) )
      addMessage(*messageItem);
    else if( MscFragmentItem const* fragmentItem = dynamic_cast<MscFragmentItem const*>(currentSeqItem) )
      processFragment(*fragmentItem);
  }
}


/** TODOs:
 *  - Read out and pass fragment headers like considered events
 *  - Read out and pass operand conditions
 */
void
MscPrinter::processFragment(const MscFragmentItem &fragmentItem)
{
  int fragType = fragmentItem.fragmentType();
  QString fragTypeText = fragmentType2string(fragType);
  openNewFragment(fragTypeText);

  MscFragmentItem::ConstMscRegionSet operands = fragmentItem.regions();
  MscFragmentItem::ConstMscRegionSet::iterator iOp;
  for( iOp=operands.begin(); iOp!=operands.end(); iOp++ )
  {
    if( iOp!=operands.begin() )
      addNextFragOperand();
    model::msc::MscFragmentRegionItem const *operand = *iOp;
    processLevel(*operand);
  }

  closeFragment();
}


QPixmap
MscPrinter::getFinalGraphic()
{
  QPixmap mscPicture(mscDir + "/msc.png");
  return mscPicture;
}


void
MscPrinter::openNewFragment(const QString &fragLabel)
{
  mscText += "--: " + fragLabel + "\n{\n";
}


void
MscPrinter::addNextFragOperand(const QString &optCondition)
{
  QString condText = optCondition;
  if( !condText.isEmpty() )
    condText = "(" + condText + ")";

  mscText += "\n}\n..: " + condText + "\n{\n";
}


void
MscPrinter::closeFragment()
{
  mscText += "\n};\n";
}


void
MscPrinter::addMessage(const MscMessageItem &messageItem)
{
  QString source = messageItem.sourcePort()->owner()->toString();
  QString dest = messageItem.targetPort()->owner()->toString();
  QString msg = messageItem.text();
  mscText += source + "->" + dest + ": " + msg + ";\n";
}


void
MscPrinter::endMscCreation()
{
  writeMscTextToTempFile();

  QString mscGenPath;
#ifdef _WIN32
  mscGenPath = mscDir + "/msc-gen.exe";
#else
  mscGenPath = mscDir + "/msc-gen";
#endif

  QStringList sourcePathArg;
  sourcePathArg << mscDir + "/" + TEMP_TXT_FILE_NAME;
  pngPrinter.start(mscGenPath, sourcePathArg);
  pngPrinter.waitForFinished();
}


void
MscPrinter::writeMscTextToTempFile()
{
  QString tempTxtPath = mscDir + "/" + TEMP_TXT_FILE_NAME;
  std::ofstream file;
  file.open(tempTxtPath.toLatin1().data());
  file << mscText.toLatin1().data();
  file.close();
}

}}	// namespace model::msc
