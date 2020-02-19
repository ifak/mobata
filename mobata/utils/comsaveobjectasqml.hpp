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
#ifndef COMSAVEOBJECTASQML_HPP
#define COMSAVEOBJECTASQML_HPP

#include "../mobata_global.hpp"

class QObject;
class QStringList;
class QString;

class MOBATASHARED_EXPORT ComSaveObjectAsQml
{
public:
  ComSaveObjectAsQml(QObject* object,
                     const QStringList& importStatements,
                     const QString& qmlTypeName,
                     const QString& filePath);
  virtual ~ComSaveObjectAsQml();

public:
  bool execute(QString* errorMessage=0);

private:
  class Private;
  Private* _d;
};

#endif // COMSAVEOBJECTASQML_HPP
