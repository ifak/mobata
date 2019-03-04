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

#include "fileutils.hpp"

#include "functors.hpp"

#include <QDir>

namespace utils
{

bool FileUtils::removeDirContent(const QDir& dir,
                                 bool withSubDirs)
{
  if (dir.exists(dir.absolutePath()))
  {
    for(QFileInfo info: dir.entryInfoList(QDir::NoDotAndDotDot |
                                          QDir::System |
                                          QDir::Hidden  |
                                          QDir::AllDirs |
                                          QDir::Files,
                                          QDir::DirsFirst))
    {
      if (info.isDir() && withSubDirs)
      {
        QDir subDir(info.absoluteFilePath());
        if(!removeDir(subDir, false))
          return false;
      }
      else
      {
        if(!QFile::remove(info.absoluteFilePath()))
          return false;
      }
    }

    return true;
  }

  return false;
}

bool FileUtils::removeDir(QDir& dir, bool onlyContent)
{
  if(onlyContent)
    return removeDirContent(dir);
  else
    return dir.removeRecursively();
}

bool FileUtils::removeDir(const QString& dirString, bool onlyContent)
{
  if(dirString.isEmpty())
    return true;

  QDir toRemoveDir(dirString);

  return removeDir(toRemoveDir, onlyContent);
}

bool FileUtils::textFileContent(const QString &filePath,
                                QString* contentArray,
                                QString* errorMessage)
{
  Q_ASSERT(contentArray);

  QFile docFile(filePath);
  if(!docFile.exists())
  {
    AddPtrString(errorMessage)<<QObject::tr("file '%1' does not exist!")
                                .arg(filePath);
    return false;
  }

  if(!docFile.open(QIODevice::Text | QIODevice::ReadOnly))
  {
    utils::AddPtrString(errorMessage)<<QObject::tr("model file '%1' could not be opened!")
                                       .arg(filePath);
    return false;
  }

  *contentArray = QString::fromLatin1(docFile.readAll());
  docFile.close();

  return true;
}


}//end namespace utils
