#include "comimportrhapsodytree.hpp"
#include "importrhapsodyelementtree.hpp"
#include "importrhapsodyutils.hpp"
#include "mobata/model/base/basemodel.hpp"

#include <importrhapsody/importrhapsodypointer.hpp>

using namespace model::base;
namespace rhapsody {

class ComImportRhapsodyTree::Private
{
  friend class ComImportRhapsodyTree;
  RhapsodyPointer* _rhapsodyPointer;
  QStandardItemModel*  _standardItemModel;
  QString _projectFilePath;

  Private(RhapsodyPointer* rhapsodyPointer,
          QStandardItemModel* standardItemModel,
          const QString& projectFilePath)
    : _rhapsodyPointer(rhapsodyPointer),
      _standardItemModel(standardItemModel),
      _projectFilePath(projectFilePath)
  {}
};

ComImportRhapsodyTree::ComImportRhapsodyTree(RhapsodyPointer* rhapsodyPointer,
                                             QStandardItemModel* standardItemModel,
                                             const QString& projectFilePath)
  : ImportRhapsodyProp(),
    _d(new Private(rhapsodyPointer, standardItemModel, projectFilePath))
{}

ComImportRhapsodyTree::~ComImportRhapsodyTree()
{
  delete this->_d;
}

bool ComImportRhapsodyTree::execute(QString* errorMessage)
{
  ImportRhapsodyElementTree* elementTree = new ImportRhapsodyElementTree();

  this->_d->_standardItemModel->clear();

  if(!this->loadRhapsodyProjectMain(this->_d->_rhapsodyPointer,
                                    this->_d->_projectFilePath,
                                    errorMessage))
    return false;

  if(!elementTree->loadRhapsodyElementTree(this->_d->_rhapsodyPointer->_rhapsodyProject,
                                           this->_d->_standardItemModel,
                                           errorMessage))
    return false;

  return true;
}

} //end of namespace rhapsody
