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
#ifndef MODEL_MSC_MSCMODEL_HPP
#define MODEL_MSC_MSCMODEL_HPP

#include "../../mobata_global.hpp"

#include "msc_types.hpp"

#include "../base/basemodel.hpp"
#include "msccomponentsproperty.hpp"

namespace model{
namespace msc{

class MOBATASHARED_EXPORT MscModel
    : public base::BaseModel,
    public MscComponentsProperty<MscComponentItem>
{
  Q_OBJECT

private:
  typedef base::BaseModel                         BaseModelClass;
  typedef MscComponentsProperty<MscComponentItem>	BasePropClass;

public:
  typedef QList<MscSequence*>       SequenceSet;
  typedef QList<MscSequence const*> ConstSequenceSet;

public:
  explicit MscModel(QObject *parent = 0);
  explicit MscModel(const QString& name,
                    QObject *parent = 0);
  virtual ~MscModel();

public:
  virtual void reset();

public:
  MscSequence*        addSequence(const QString &sequName);
  void                addSequence(MscSequence* sequence);
  MscSequence const*  sequence(const QUuid &sequUuid) const;
  SequenceSet         sequences();
  ConstSequenceSet    sequences() const;
  void                removeSequence(const QUuid &sequUuid);

private:
  Q_DISABLE_COPY(MscModel)
  class Private;
  QScopedPointer<Private>	_d;
};

}/// end namespace msc
}/// end namespace model

#endif //MODEL_MSC_MSCMODEL_HPP
