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
#ifndef MODEL_SPENAT_IO_COMIMPORTXMLSPENAT_HPP
#define MODEL_SPENAT_IO_COMIMPORTXMLSPENAT_HPP

#include <QObject>

namespace model {
namespace spenat {
class SpenatDeclModel;

namespace io{

class ComImportXmlSpenat : public QObject
{
  Q_OBJECT
public:
  explicit ComImportXmlSpenat(const QString& fileName,
                              SpenatDeclModel* declModel,
                              QObject *parent = 0);
  virtual ~ComImportXmlSpenat();

public:
  bool execute(QString* errorMessage);

private:
  Q_DISABLE_COPY(ComImportXmlSpenat)
  class Private;
  Private* _d;
};

} // namespace io
} // namespace spenat
} // namespace model

#endif // MODEL_SPENAT_IO_COMIMPORTXMLSPENAT_HPP
