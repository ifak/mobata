/*
 * This file is part of mobata.
 *
 * Copyright (C) 2019 ifak, https://www.ifak.eu/
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

#include "mscmodel.hpp"

#include "mscmessageitem.hpp"
#include "msctimeritem.hpp"
#include "mscfragmentitem.hpp"
#include "mscfragmentregionitem.hpp"
#include "mscstatementitem.hpp"
#include "msccomponentitem.hpp"

#include "../../utils/functors.hpp"

#include <stdexcept>

namespace model{
namespace msc{

class MscModel::Private
{
  friend class MscModel;

  Private()
    : _sequParent(0)
  {}

public:
  ~Private()
  {}

private:
  QStandardItem*  _sequParent;
};

MscModel::MscModel(QObject *parent)
  :	BaseModelClass(parent),
    BasePropClass(this->invisibleRootItem()),
    _d(new Private())
{
  this->setName("MSCs");

  this->setHeaderData(0, Qt::Horizontal,
                      this->name(), Qt::DisplayRole);
}

MscModel::MscModel(const QString& name,
                   QObject* parent)
  :	BaseModelClass(name, parent),
    BasePropClass(this->invisibleRootItem()),
    _d(new Private())
{
  this->setHeaderData(0, Qt::Horizontal,
                      this->name(), Qt::DisplayRole);
}

MscModel::~MscModel()
{}

void MscModel::reset()
{
  BaseModelClass::reset();
  BasePropClass::resetComponents();

  this->setName("MSCs");

  if(this->_d->_sequParent)
    this->_d->_sequParent->removeRows(0, this->_d->_sequParent->rowCount());

  return;
}

MscSequence *MscModel::addSequence(const QString& sequName)
{
  if(!this->_d->_sequParent)
  {
    this->_d->_sequParent=new QStandardItem(QIcon(QLatin1String(":mobata/images/msc/manysequence.png")),
                                            QLatin1String("sequences"));
    this->_d->_sequParent->setFlags(this->_d->_sequParent->flags() & ~Qt::ItemIsEditable);
    this->appendRow(this->_d->_sequParent);
  }

  MscSequence* newSequence=new MscSequence(sequName);
  this->_d->_sequParent->appendRow(newSequence);

  return newSequence;
}

void MscModel::addSequence(MscSequence *sequence)
{
  if(!sequence)
    return;

  if(!this->_d->_sequParent)
  {
    this->_d->_sequParent=new QStandardItem(QIcon(QLatin1String(":mobata/images/msc/manysequence.png")),
                                            QLatin1String("sequences"));
    this->_d->_sequParent->setFlags(this->_d->_sequParent->flags() & ~Qt::ItemIsEditable);
    this->appendRow(this->_d->_sequParent);
  }

  this->_d->_sequParent->appendRow(sequence);

  return;
}

const MscSequence *MscModel::sequence(const QUuid &sequUuid) const
{
  for(MscSequence const* sequence: this->sequences())
    if(sequence->uuid()==sequUuid)
      return sequence;

  return 0;
}

MscModel::SequenceSet MscModel::sequences()
{
  SequenceSet sequences;
  if(!this->_d->_sequParent)
    return sequences;

  int end=this->_d->_sequParent->rowCount();
  for(int i=0; i<end; ++i)
  {
    QStandardItem* currChild=this->_d->_sequParent->child(i);
    MscSequence* sequence=utils::simple_cast<MscSequence*>(currChild);
    Q_ASSERT(sequence);
    sequences.append(sequence);
  }

  return sequences;
}

MscModel::ConstSequenceSet MscModel::sequences() const
{
  ConstSequenceSet sequences;
  if(!this->_d->_sequParent)
    return sequences;

  int end=this->_d->_sequParent->rowCount();
  for(int i=0; i<end; ++i)
  {
    QStandardItem* currChild=this->_d->_sequParent->child(i);
    MscSequence* sequence=utils::simple_cast<MscSequence*>(currChild);
    Q_ASSERT(sequence);
    sequences.append(sequence);
  }

  return sequences;
}

void MscModel::removeSequence(const QUuid &sequUuid)
{
  for(MscSequence const* sequence: this->sequences())
  {
    if(sequence->uuid()==sequUuid)
    {
      this->_d->_sequParent->removeRow(sequence->row());
      break;
    }
  }
}

//const PortItem *MscModel::port(const QUuid &portUuid) const
//{
//  for(MscCompItem const* component: this->components())
//  {
//    for(base::PortItem const* portItem: component->ports())
//    {
//      if(portItem->uuid()==portUuid)
//        return simple_cast<PortItem const*>(portItem);
//    }
//  }

//  return 0;
//}

}/// end namespace msc
}/// end namespace model
