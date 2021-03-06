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

#include "modsim_global.hpp"
#include <dslparser/dslproposal.hpp>
#include <dslparser/dslparser_types.hpp>

#include <QObject>

namespace modsim {

class SimSystemModel;

class MODSIMSHARED_EXPORT ComCreateSimSystemProposals
    : public QObject
{
public:
  explicit ComCreateSimSystemProposals(const QString& simSystemDocText,
                                       const QString& prefix,
                                       SimSystemModel* simSystemModel = nullptr,
                                       bool strictErrorHandling = true,
                                       QObject *parent = nullptr);
  virtual ~ComCreateSimSystemProposals();

public:
  bool                              execute(QString* errorString);
  const dslparser::DslProposalList& simSystemProposals() const;

private:
  Q_DISABLE_COPY(ComCreateSimSystemProposals)
  class Private;
  Private* _d;
};

}// namespace modsim
