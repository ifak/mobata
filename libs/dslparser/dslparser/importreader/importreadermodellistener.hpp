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

#include "ImportReaderBaseListener.h"
#include <QHash>
#include <QString>

#include "../dslerror.hpp"

namespace dslparser {
namespace importreader {


class ImportReaderModelListener : public ImportReaderBaseListener
{

public:
  ImportReaderModelListener(QHash<QString,QString>* importMap,
                            const QString& prefix,
                            DslErrorList* importErrors);
  ImportReaderModelListener(QHash<QString,QString>* importMap,
                            DslErrorList* importErrors);
  virtual ~ImportReaderModelListener();

protected:
  void exitImportPathBody(ImportReaderParser::ImportPathBodyContext *ctx);

private:
  class Private;
  Private* _d;
};

} // namespace importreader
} // namespace dslparser
