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
#ifndef MODEL_BASE_CHILDRENPROPERTY_HPP
#define MODEL_BASE_CHILDRENPROPERTY_HPP

#include <QStandardItem>

#include "../../utils/functors.hpp"

namespace model{
namespace base{

template<class ChildType>
class ChildrenProperty
{
protected:
  typedef QList<ChildType const*>  ConstChildSet;
  typedef QList<ChildType*>        ChildSet;

protected:
  ChildrenProperty(QStandardItem* ownerItem,
                   const QString& childsItemName,
                   const QIcon& childsItemIcon)
    : _ownerItem(ownerItem),
      _childsItem(0),
      _childsItemName(childsItemName),
      _childsItemIcon(childsItemIcon)
  {}

  virtual ~ChildrenProperty()
  {}

protected:
  ChildType const*  childByUuid(const QUuid& childUuid) const
  {
    for(ChildType const* childItem : this->children())
      if(childItem->uuid()==childUuid)
        return childItem;

    return 0;
  }

  ChildType*  childByUuid(const QUuid& childUuid)
  {
    for(ChildType* childItem : this->children())
      if(childItem->uuid()==childUuid)
        return childItem;

    return 0;
  }

  ChildType const*  childByName(const QString& childName) const
  {
    for(ChildType const* childItem : this->children())
      if(childItem->name()==childName)
        return childItem;

    return 0;
  }

  ChildType*  childByName(const QString& childName)
  {
    for(ChildType* childItem : this->children())
      if(childItem->name()==childName)
        return childItem;

    return 0;
  }

  ConstChildSet children() const
  {
    ConstChildSet childSet;
    if(!this->_childsItem)
      return childSet;

    int childsCount=this->_childsItem->rowCount();

    for(int i =0; i < childsCount; ++i)
    {
      QStandardItem*  currChild=this->_childsItem->child(i);
      ChildType* currentChild=utils::simple_cast<ChildType*>(currChild);
      Q_ASSERT(currentChild);
      childSet.append(currentChild);
    }

    return childSet;
  }

  ChildSet  children()
  {
    ChildSet childSet;
    if(!this->_childsItem)
      return childSet;

    int childsCount=this->_childsItem->rowCount();

    for(int i =0; i < childsCount; ++i)
    {
      QStandardItem*  currChild=this->_childsItem->child(i);
      ChildType* currentChild=utils::simple_cast<ChildType*>(currChild);
      Q_ASSERT(currentChild);
      childSet.append(currentChild);
    }

    return childSet;
  }

protected:
  void  resetChildren()
  {
    if(this->_childsItem)
      this->_childsItem->removeRows(0, this->_childsItem->rowCount());

    return;
  }

  bool  addChild(ChildType* child)
  {
    Q_ASSERT(this->_ownerItem);

    if(!child)
      return false;

    if(!this->_childsItem)
    {
      this->_childsItem=new QStandardItem(this->_childsItemIcon,
                                          this->_childsItemName);
      this->_childsItem->setFlags(this->_childsItem->flags()
                                  & ~Qt::ItemIsEditable);
      this->_ownerItem->appendRow(this->_childsItem);
    }

    this->_childsItem->appendRow(child);

    return true;
  }

  bool  insertChild(int pos, ChildType* child)
  {
    Q_ASSERT(this->_ownerItem);
    Q_ASSERT(pos>=0);

    if(!child)
      return false;

    if(!this->_childsItem)
    {
      this->_childsItem=new QStandardItem(this->_childsItemIcon,
                                          this->_childsItemName);
      this->_childsItem->setFlags(this->_childsItem->flags()
                                  & ~Qt::ItemIsEditable);
      this->_ownerItem->appendRow(this->_childsItem);
    }

    this->_childsItem->insertRow(pos, child);

    return true;
  }

  void  removeChild(const QUuid& childUuid)
  {
    if(!this->_childsItem)
      return;

    foreach(ChildType* currChild, this->children())
    {
      if(currChild->uuid() == childUuid)
        this->_childsItem->removeRow(currChild->row());
    }

    if(!this->_ownerItem)
      return;

    if(this->_childsItem->rowCount() == 0)
    {
      this->_ownerItem->removeRow(this->_childsItem->row());
      this->_childsItem = 0;
    }

    return;
  }

  void  removeChild(ChildType const* child)
  {
    if(!this->_childsItem)
      return;

    foreach(ChildType* currChild, this->children())
    {
      if(currChild == child)
        this->_childsItem->removeRow(currChild->row());
    }

    if(!this->_ownerItem)
      return;

    if(this->_childsItem->rowCount() == 0)
    {
      this->_ownerItem->removeRow(this->_childsItem->row());
      this->_childsItem = 0;
    }

    return;
  }

protected:
  QStandardItem*  _ownerItem;
  QStandardItem*  _childsItem;
  QString         _childsItemName;
  QIcon           _childsItemIcon;
};

} // namespace base
} // namespace model

#endif // MODEL_BASE_CHILDRENPROPERTY_HPP

