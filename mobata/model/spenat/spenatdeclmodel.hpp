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
#pragma once

#include "../../mobata_global.hpp"

#include "spenatbasemodel.hpp"

namespace model{
namespace spenat{

class JunctionItem;

class MOBATASHARED_EXPORT SpenatDeclModel
    : public SpenatBaseModel
{
  Q_OBJECT

private:
  typedef SpenatBaseModel       BaseClass;

public:
  typedef QList<JunctionItem*>  JunctionSet;

public:
  explicit SpenatDeclModel(QObject *parent = nullptr);
  explicit SpenatDeclModel(const QString& name, QObject *parent = nullptr);
  virtual	~SpenatDeclModel();

public:
  static
  bool isValidArc(NodeItem const* sourceNode,
                  NodeItem const* targetNode,
                  QString *errorMessage);

public:
  JunctionItem*       addJunction(const QUuid& uuid = QUuid::createUuid());
  JunctionItem const* junction(const QUuid& uuid) const;
  JunctionItem*       junction(const QUuid& uuid);
  JunctionSet         junctions() const;

public://virtual methods
  virtual void            reset();
  virtual void            resetGraphDecl();
  virtual NodeItem*       node(const QUuid& nodeId);
  virtual NodeItem const* node(const QUuid& nodeId) const;
  virtual ConstNodeSet    nodes() const;
  virtual ArcItem*        arc(const QUuid &arcUuid);
  virtual ConstArcSet     arcs() const;
  virtual JsonObjectPtr   createJson() const;

private:
  Q_DISABLE_COPY(SpenatDeclModel)
  class Private;
  Private*  _d;
};

typedef QSharedPointer<SpenatDeclModel> SpenatDeclModelPtr;

}///end namespace spenat
}///end namespace model
