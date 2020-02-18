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
#ifndef VIEW_SPENAT_SPENATSCENE_HPP
#define VIEW_SPENAT_SPENATSCENE_HPP

#include "../mobatawidgets_global.hpp"

#include "types.hpp"

#include <QUuid>

#include "../graph/graphscene.hpp"

namespace view{

namespace graph{
  class AbstractNode;
  class Edge;
}

namespace spenat{

class DeclPlace;
class DeclTransition;
class DeclArc;

class MOBATAWIDGETSSHARED_EXPORT SpenatScene
    : public graph::GraphScene
{
	Q_OBJECT
	
public:
	SpenatScene(QObject *parent = 0);
	virtual ~SpenatScene();

signals:
	void placeAdded(QUuid placeID,
									const QString& placeText);
	void transitionAdded(QUuid transitionID,
											 const QString& transitionText);
	void arcAdded(QUuid arcUuid, 
								QUuid sourceID, 
								QUuid targetID, 
								const QString& arcText);
	
	void placeChanged(QUuid placeID,
										const QString& placeText,
										bool initMarking);
	void transitionChanged(QUuid transitionID,
												 const QString& transitionText);
	void arcChanged(QUuid arcUuid, 
									QUuid sourceID, 
									QUuid targetID, 
									const QString& arcText);

	void placeRemoved(QUuid placeID);
	void transitionRemoved(QUuid transitionID);
	void arcRemoved(QUuid arcID,
									QUuid sourceID, 
									QUuid targetID);
public:
	virtual void  reset();
  virtual bool  isValidArc(graph::AbstractNode const* sourceNode, 
                           graph::AbstractNode const* targetNode, 
                           QString *errorMessage) const;
public:
  virtual graph::AbstractNode const*  node(const QUuid& nodeUuid) const;
  virtual graph::AbstractNode *       node(const QUuid& nodeUuid);
  virtual ConstNodeSet                nodes() const;
  virtual NodeSet                     nodes();
  
  virtual graph::Edge const*          edge(const QUuid& edgeUuid) const;
  virtual graph::Edge*                edge(const QUuid &edgeUuid);
  virtual ConstEdgeSet                edges() const;
  virtual EdgeSet                     edges();

	virtual void                        removeGraphItem(QGraphicsItem* graphItem);
	
public:
	DeclPlace*                    place(QUuid placeUuid);
	DeclPlace const*              place(QUuid placeUuid) const;
	DeclTransition*               transition(QUuid transitionUuid);
	DeclTransition const*         transition(QUuid transitionUuid) const;
	QList<DeclPlace const*>       places() const;
	QList<DeclPlace*>             places();
	QList<DeclTransition const*>  transitions() const;
	QList<DeclTransition*>        transitions();
	DeclArc const*                arc(graph::AbstractNode const* source,
                                    graph::AbstractNode const* target) const;
  DeclArc const*                arc(const QUuid &arcUuid) const;
  DeclArc*                      arc(const QUuid &arcUuid);
	QList<DeclArc const*>         arcs() const;
	QList<DeclArc*>               arcs();

public:
	DeclPlace*        addPlace(QPointF pos, QUuid placeUuid=QUuid::createUuid());
	DeclPlace*        addPlace(QPointF pos, const QString &placeNotation,
                             QUuid placeUuid=QUuid::createUuid());
	DeclPlace*        addPlace(QPointF pos, const QString &placeName, 
                             const PlaceOptions& placeOptions,
                             QUuid placeUuid=QUuid::createUuid());
	
	DeclTransition* addTransition(QPointF pos, QUuid transUuid=QUuid::createUuid());
	DeclTransition* addTransition(QPointF pos, const QString &transNotation,
                                QUuid transUuid=QUuid::createUuid());
	DeclTransition* addTransition(QPointF pos, const QString &transDecl,
                                QPointF transDeclPos, 
                                const TransitionOptions& transitionOptions,
                                QUuid transitionID=QUuid::createUuid());
	
	DeclArc*  addArc(graph::AbstractNode* from, graph::AbstractNode* to, 
                   const QString &arcLabel=QLatin1String(""), QUuid arcID=QUuid::createUuid());
	DeclArc*  addArc(graph::AbstractNode* from, graph::AbstractNode* to, 
                   QPainterPath path, const QString &arcLabel=QLatin1String(""),
                   QUuid arcID=QUuid::createUuid());
	DeclArc*  addArc(graph::AbstractNode* from, graph::AbstractNode* to, 
                   QPainterPath path, const QString &arcLabel,QPointF arcLabelPos, 
                   const ArcOptions& arcOptions, QUuid arcID=QUuid::createUuid());
	
	void  removePlace(const QUuid& placeUuid);
	void  removePlace(DeclPlace *place);
	void  removeTransition(const QUuid& transitionUuid);
	void  removeTransition(DeclTransition* transition);
	void  removeArc(const QUuid& arcUuid);
	void  removeArc(DeclArc* arc);
	
	void  changeInitMarking(DeclPlace *declPlace);

protected slots:
	void  nodeTextChangedSlot(graph::AbstractNode const* node);
	void  arcTextChangedSlot(graph::Edge const* edge);

private:
  Q_DISABLE_COPY(SpenatScene)
  class Private;
	QScopedPointer<Private> _d;
};

}/// namespace spenat
}/// namespace view

#endif
