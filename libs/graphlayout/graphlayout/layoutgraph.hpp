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

#include <QObject>
#include <QList>

#include "graphlayout_global.hpp"
#include "layoutglobal.hpp"

#include "layoutnode.hpp"
#include "layoutedge.hpp"

#include <mobata/prop/nameproperty.hpp>

namespace graphlayout{

class LayoutNode;
class LayoutNodePort;
class LayoutEdge;

class GRAPHLAYOUTSHARED_EXPORT LayoutGraph
    : public QObject,
    public prop::NameProperty
{
  //Q_OBJECT

public:
  LayoutGraph(const QString& name= QStringLiteral(""),
              QObject* parent = nullptr);

  virtual ~LayoutGraph();

public:
  void                clearGraph();
  const OverlapEnum&  overlap() const;
  QString             overlapString() const;
  void                setOverlap(const OverlapEnum& overlap);
  void                setOverlap(const QString& overlap);

  const SplineEnum& splines() const;
  QString           splinesString() const;
  void              setSplines(const SplineEnum& splines);
  void              setSplines(const QString& splines);

  void    setGraphSize(const QSizeF size);
  QSizeF  graphSize() const;

  const QList<LayoutNode*>&     nodes() const;
  QList<LayoutNode*>            allNodes() const;
  QList<LayoutNodePort*>        allPorts() const;
  QList<LayoutNodePort const*>  allUsedPorts() const;
  QList<LayoutNodePort const*>  allUnusedPorts() const;
  LayoutNode* portParentNode(QUuid portQUuid);
  LayoutNodePort* port(QUuid portUuid);
  QList<LayoutNode*> nodesFromList(QList<LayoutNode*> list) const;
  const QList<LayoutEdge*> edges() const;
  const QPointF UuidToGlobalPos(QUuid uuid);

  LayoutNode* nodeParentNode(QUuid nodeQUuid);

  LayoutNode* nodeByXLabel(QString xLabel);
  LayoutNode* nodeByLabel(QString Label);
  LayoutNode* nodeByAnyLabel(QString Label);

  /*!
    Operation creates and adds a node to this layout-graph.
    New node is returned.
  */
  LayoutNode* addNode();

  /*!
    If available the node with \a nodeUuid is returned.
  */
  LayoutNode const* node(const QUuid& nodeUuid) const;

  /*!
    If available node-position of node with \a nodeUuid is returned.
  */
  int nodePos(const QUuid& nodeUuid) const;

  /*!
    If available the node at \a pos is returned.
  */
  LayoutNode const* node(const std::size_t pos) const;

  /*!
    If available the node with \a nodeExternUuid is returned.
  */
  LayoutNode* nodeByExternUuid(const QUuid& nodeExternUuid);

  /*!
    If available the node with \a nodeName is returned.
  */
  LayoutNode* nodeByName(const QString& nodeName);
  /*!
    If available the nested node with \a nodePath is returned.
  */
  LayoutNode* nodeByPath(const QString& nodePath);
  LayoutNode* nodeByPathImpl(const QStringList &nodePathList,
                             const QList<LayoutNode*>& nodeList);

private:
  LayoutNode* nodeByExternUuidRec(const QUuid &nodeExternUuid, QList<LayoutNode*> list);

public:
  /*!
    New edge with \a source and \a target is created, added and returned.
  */
  LayoutEdge* addEdge(LayoutNode const* source, LayoutNode const* target);

  /*!
    If available edge at \a pos is returned.
  */
  LayoutEdge const* edge(const std::size_t pos) const;

  /*!
    If available edge with \a edgeUuid is returned.
  */
  LayoutEdge const* edge(const QUuid& edgeUuid) const;
  LayoutEdge* edgeByExternUuid(const QUuid& edgeUuid);

  /*!
    If available edge with \a edgeName is returned.
  */
  LayoutEdge* edgeByName(const QString& edgeName) const;

  /*!
    If available edge-position of edge with \a edgeUuid is returned.
  */
  int edgePos(const QUuid& edgeUuid) const;

  /*!
    If available edge with \a sourceUuid and \a targetUuid for the
    source and target node is returned.
  */
  LayoutEdge const* edge(const QUuid& sourceUuid,
                         const QUuid& targetUuid);

  /*!
    If available edge with \a sourceExternUuid and \a targetExternUuid for the
    source and target node is returned.
  */
  LayoutEdge const* edgeByExternNodeUuid(const QUuid& sourceExternUuid,
                                         const QUuid& targetExternUuid);

protected:
  class Private;
  Private* _d;
};
/*
inline
void save(LayoutGraph const* layoutGraph, const QString& path);

inline
void read(LayoutGraph* layoutGraph, const QString& path);
*/
}/////////end namespace graphlayout
