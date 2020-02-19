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
#ifndef COMCHECKMSC_HPP
#define COMCHECKMSC_HPP

#include <mobata/utils/functors.hpp>
#include <mobata/model/msc/msc.hpp>
namespace graphlayout{
class comCheckMsc
{
public:
  comCheckMsc(model::msc::MscSequence* mscSeq);
  bool execute(QString* errorString);
private:
  bool checkList(const model::msc::MscSequence::ConstSequenceItems list);
  bool checkComponents(const model::msc::MscSequence::ConstComponentItems list);
  bool checkPorts(const model::msc::MscComponentItem::ConstPortSet list);

  bool checkMessage(const model::msc::MscSequenceItem* item);
  bool checkStatement(const model::msc::MscSequenceItem* item);
  bool checkTimer(const model::msc::MscSequenceItem* item);
  bool checkFragment(const model::msc::MscSequenceItem* item);
private:
  model::msc::MscSequence* _mscSeq = nullptr;
  QString* _errorString = nullptr;
  QList<const model::msc::MscComponentItem*> _componentList;
  QList<const model::msc::PortItem*> _portList;
};
}
#endif // COMCHECKMSC_HPP
