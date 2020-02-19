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
#ifndef VIEW_TS_SUTSCENE_HPP
#define VIEW_TS_SUTSCENE_HPP

#include "../mobatawidgets_global.hpp"

#include "types.hpp"

#include "../base/roundrect.hpp"

#include "../graph/graphscene.hpp"

namespace view {

namespace ts {

typedef QVector<SutComponent*>  SutComponents;
typedef QVector<Link*>          SutLinks;

class MOBATAWIDGETSSHARED_EXPORT SutBox
    : public base::RoundRect
{
  friend class SutScene;

public:
  SutBox(QGraphicsItem* parent =0);
  virtual ~SutBox();

public:
  qreal marginSpace() const;

private:
  void                  addSutComponent(SutComponent* newSutComponent);
  void                  addSutLink(Link* link);
  const SutComponents&  sutComponents() const;
  const SutLinks&       sutLinks() const;

private:
  Q_DISABLE_COPY(SutBox)
  class Private;
  Private* _d;
};

class MOBATAWIDGETSSHARED_EXPORT SutScene
    : public graph::GraphScene
{
  Q_OBJECT

public:
  explicit SutScene(QObject *parent = 0);
  virtual ~SutScene();

private:
  void addSutBox();

public:
  virtual void reset();

public:
  void                  addSutComponent(SutComponent* newSutComponent);
  void                  addSutLink(Link* link);
  const SutComponents&  sutComponents() const;
  const SutLinks&       sutLinks() const;

  SutBox const*         sutBox() const;

  void                  setSutBoxBrush(const QBrush& sutBoxBrush);
  QBrush                sutBoxBrush() const;

public:
  virtual view::ts::Port* port(const QUuid& portUuid) const;

private:
  Q_DISABLE_COPY(SutScene)
  class Private;
  Private* _d;
};

} // namespace ts
} // namespace view

#endif // VIEW_TS_SUTSCENE_HPP
