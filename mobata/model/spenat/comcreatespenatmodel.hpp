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
#ifndef MODEL_SPENAT_COMCREATESPENATMODEL_HPP
#define MODEL_SPENAT_COMCREATESPENATMODEL_HPP

#include "../../mobata_global.hpp"

#include <QSharedPointer>

namespace model{
namespace spenat{

class SpenatDeclModel;
class SpenatModel;
class Spenat2DeclMapping;
class JunctionItem;

class MOBATASHARED_EXPORT ComCreateSpenatModel
{
public:
  typedef QSharedPointer<SpenatModel>				SpenatModelPtr;
  typedef QSharedPointer<Spenat2DeclMapping>	Spenat2DeclMappingPtr;

public:
  ComCreateSpenatModel(SpenatDeclModel const* declModel);

public:
  bool                          execute(QString* errorString);
  const SpenatModelPtr&         spenatModel() const;
  const Spenat2DeclMappingPtr&  spenat2DeclMapping() const;

private:
  bool processJunction(JunctionItem const* declJunctionItem, QString* errorString);

private:
  SpenatDeclModel const*      _declModel;
  SpenatModelPtr        _spenatModel;
  Spenat2DeclMappingPtr _spenat2DeclMapping;

private:
  Q_DISABLE_COPY(ComCreateSpenatModel)
};

}/// end namepace spenat
}///end namespace model

#endif // MODEL_SPENAT_COMCREATESPENATMODEL_HPP
