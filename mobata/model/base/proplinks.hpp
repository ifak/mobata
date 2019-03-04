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

#pragma once

#include <QList>

class QStandardItem;
class QUuid;

namespace model {
namespace base {

class LinkItem;
class PortItem;

class PropLinks
{
public:
  typedef QList<LinkItem*>        LinkSet;
  typedef QList<LinkItem const*>  ConstLinkSet;

public:
  PropLinks(QStandardItem* parentItem);
  virtual ~PropLinks();

public:
  LinkItem*       addLink(PortItem const* from,
                          PortItem const* to,
                          QString* errorString=0);
  bool            addLink(LinkItem* newLink,
                          QString* errorString=0);
  void            removeLink(const QUuid& linkUuid);
  LinkItem*       link(const QUuid& linkUuid);
  LinkItem const* link(const QUuid& linkUuid) const;
  LinkItem*       link(PortItem const* from,
                       PortItem const* to);
  LinkItem const* link(PortItem const* from,
                       PortItem const* to) const;
  LinkSet         links();
  ConstLinkSet    links() const;

protected:
  void      resetLinks();
  void      setLinksParentItem(QStandardItem* linksParentItem);

private:
  Q_DISABLE_COPY(PropLinks)
  class Private;
  Private*  _d;
};

} // namespace base
} // namespace model
