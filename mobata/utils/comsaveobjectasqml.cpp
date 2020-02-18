#include "comsaveobjectasqml.hpp"

#include <QFile>
#include <QTextStream>
#include <QMetaProperty>
#include <QDebug>

#include "memory_leak_start.hpp"

class ComSaveObjectAsQml::Private
{
  friend class ComSaveObjectAsQml;

  Private(QObject* object,
          const QStringList& importStatements,
          const QString& qmlTypeName,
          const QString& filePath)
  : _object(object),
    _importStatements(importStatements),
    _qmlTypeName(qmlTypeName),
    _filePath(filePath)
  {Q_ASSERT(object);}

  QObject*    _object;
  QStringList _importStatements;
  QString     _qmlTypeName;
  QString     _filePath;
};

ComSaveObjectAsQml::ComSaveObjectAsQml(QObject* object,
                                       const QStringList& importStatements,
                                       const QString& qmlTypeName,
                                       const QString& filePath)
  : _d(new Private(object, importStatements, qmlTypeName, filePath))
{
  Q_ASSERT(object);
}

ComSaveObjectAsQml::~ComSaveObjectAsQml()
{
  delete this->_d;
}

bool ComSaveObjectAsQml::execute(QString* errorMessage)
{
  if(!this->_d->_object)
    return false;

  if(this->_d->_filePath.isEmpty())
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("no file path for saving object "
                                 "as qml-file specified!");
    return false;
  }

  QFile qmlFile(this->_d->_filePath);
  if (!qmlFile.open(QFile::WriteOnly | QFile::Truncate))
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("file %1 could not be opened for saving "
                                 "object as qml-file").arg(this->_d->_filePath);
    return false;
  }


  QTextStream qmlOutStream(&qmlFile);

  //////import statements////////
  foreach(const QString& importStatement, this->_d->_importStatements)
    qmlOutStream<<importStatement<<"\n";
  qmlOutStream<<"\n";

  //////qml-type/////////
  qmlOutStream<<this->_d->_qmlTypeName<<" {"<<"\n";

  ///object-properties except property "objectName"///////
  int cursorPos=0;
  for(int i=0; i<this->_d->_object->metaObject()->propertyCount(); ++i)
  {
    QMetaProperty metaProperty=this->_d->_object->metaObject()->property(i);
    QString propertyName(QLatin1String(metaProperty.name()));
    QVariant::Type propertyType=metaProperty.type();

    if(propertyName==QStringLiteral("objectName"))
      continue;
    qmlOutStream<<"  "<<propertyName<<": ";
    cursorPos+=2+propertyName.size()+2;

    QVariant propertyValue=this->_d->_object->property(propertyName.toLatin1());

    if(propertyType==QVariant::String)
    {
      qmlOutStream<<"\""<<propertyValue.toString()<<"\"";
      cursorPos+=1+propertyValue.toString().size()+1;
    }
    else if(propertyType==QVariant::StringList)
    {
      qmlOutStream<<"[";
      cursorPos+=1;
      QStringList propertyValueStringList=propertyValue.toStringList();

      int listPos=0;
      foreach(const QString& stringValue, propertyValueStringList)
      {
        ///white spaces for nice formatting
        if(listPos==0)
        {
          qmlOutStream<<"\""<<stringValue<<"\",\n";
        }
        else
        {
          for(int c=0; c < cursorPos; ++c)
            qmlOutStream<<" ";
          qmlOutStream<<"\""<<stringValue<<"\"";
          if(listPos < (propertyValueStringList.size()-1))
            qmlOutStream<<",\n";
        }

        ++listPos;
      }

      qmlOutStream<<"]";
    }
    else
    {
      qmlOutStream<<propertyValue.toString();
      cursorPos+=propertyValue.toString().size();
    }

    qmlOutStream<<"\n";
    cursorPos=0;
  }

  ///finishing//////
  qmlOutStream<<"}\n\n";
  qmlFile.close();

  qDebug()<<"object "<<this->_d->_object->property("objectName")<<" was saved in to file "<<this->_d->_filePath;

  return true;
}
