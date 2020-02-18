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
    foreach(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot |
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
