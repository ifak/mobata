/*
 * This file is part of mobata.
 *
 * mobata is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * mobata is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License
 * along with mobata.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MSCPRINTER_H
#define MSCPRINTER_H

/** Display msc in Qt GUI with intermediate step of saving
 *  it as .png with the help of the MscGenerator software:
 *  http://sourceforge.net/projects/msc-generator
 *  Workflow: Set path of msc gen software. Create png there.
 *  Draw content of png on desired QLabel.
 *
 *  TODOs:
 *  - Add unit tests: E.g. load a mscModel from file and
 *    check generated .txt.
 */

#include "mscsequence.hpp"

#include <QString>
#include <QProcess>

class QLabel;

namespace model {
	namespace msc {

class MscModel;



class MscPrinter
{
public:
	MscPrinter(const QString &mscDir);

	void createPNG(const MscModel &mscModel);
	QPixmap getFinalGraphic();

private:
	void processLevel(const MscSequence &currentLevel);
	void processFragment(const MscFragmentItem &fragmentItem);
	void openNewFragment(const QString &fragLabel);
	void addNextFragOperand(const QString &optCondition="");
	void closeFragment();
	void addMessage(const MscMessageItem &messageItem);
	void endMscCreation();
	void writeMscTextToTempFile();

	QString mscDir;
	QString mscText;
	QProcess pngPrinter;
};

}}	// namespace model::msc


#endif // MSCPRINTER_H
