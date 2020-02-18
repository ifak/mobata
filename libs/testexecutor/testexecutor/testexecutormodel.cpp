#include "testexecutormodel.hpp"
#include "mobata/model/ts/ts.hpp"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

#include <QFileInfo>
#include <QDebug>
#include <QHash>

namespace testexecutor {

class TestexecutorModel::Private
{
  friend class TestexecutorModel;

  QHash<TestexecutorTestCase*, QString> _prioTCList;

  model::ts::TestSuite*  _testSuite = nullptr;
  QString _filePathSut;
  QString _filePathTs;
  QHash<QString, model::ts::TestCaseItem*> _filePathTestcases;

  Private()
  {}
};

TestexecutorModel::TestexecutorModel(QObject* parent)
  : QStandardItemModel(parent), _d(new Private)
{
  qDebug()<<"TestexecutorModel class created";
  this->setColumnCount(1);
  this->setHeaderData(0, Qt::Horizontal,
                      tr("Test Execution Settings"),
                      Qt::DisplayRole);

  connect(this, &TestexecutorModel::itemChanged,
          this, &TestexecutorModel::handleItemChange);
}

TestexecutorModel::~TestexecutorModel()
{
  qDebug()<<"TestexecutorModel class deleted";
  delete this->_d;
}

void TestexecutorModel::reset()
{
  qDebug()<<"TestexecutorModel::reset()";
  this->_d->_prioTCList.clear();

  this->_d->_filePathTs = "";
  this->_d->_filePathSut = "";
  this->_d->_filePathTestcases.clear();

  if(this->_d->_testSuite != nullptr){
    delete this->_d->_testSuite;
  }
  this->_d->_testSuite=nullptr;

  this->clear();

  this->invisibleRootItem()->clearData();
  this->invisibleRootItem()->removeRows(0, this->invisibleRootItem()->rowCount());
  return;
}

void TestexecutorModel::addPrioTC(const QString& tcPath, TestexecutorTestCase* tc)
{
  qDebug()<<"TestexecutorModel::addPrioTC()";
  this->_d->_prioTCList.insert(tc, tcPath);
}

bool TestexecutorModel::setPrio(const QString& prioFilePath, QString* errorString)
{
  qDebug()<<"TestexecutorModel::setPrio()";

  QFile prioFile(prioFilePath);
  bool open = prioFile.open(QIODevice::ReadOnly);
  if(!open){
    utils::AddPtrString(errorString)<<"Prio File could not be loaded";
    return false;
  }
  QString prioContent = prioFile.readAll();
  prioFile.close();

  QHash<int, TestexecutorTestCase*> tcMap;

  QJsonDocument jsonDoc;
  jsonDoc = QJsonDocument::fromJson(prioContent.toUtf8());
  QJsonObject jsonObj = jsonDoc.object();
  QJsonArray cases = jsonObj["testcases"].toArray();
  for (QJsonValue value : cases){
    QJsonObject obj = value.toObject();
    QString id = obj.value("id").toString("");
    int pos = obj.value("pos").toInt(-1);
    bool enabled = obj.value("enabled").toBool(true);
    if(id != "" && pos != -1){
      if(!tcMap.contains(pos)){
        if(QUuid::fromString(id) != nullptr){
          QUuid thisUuid = QUuid::fromString(id);
          for(TestexecutorTestCase* tcItem : this->_d->_prioTCList.keys()){
            if(tcItem->uuid() == thisUuid){
              tcMap.insert(pos, tcItem);
              tcItem->setEnabled(enabled);
              continue;
            }
          }
          utils::AddPtrString(errorString)<<"TestCase with unknown name in prio file:"<<id;
          continue;
        }else{
          for(TestexecutorTestCase* tcItem : this->_d->_prioTCList.keys()){
            if(tcItem->name() == id){
              tcMap.insert(pos, tcItem);
              tcItem->setEnabled(enabled);
              continue;
            }
          }
          utils::AddPtrString(errorString)<<"TestCase with unknown name in prio file:"<<id;
          continue;
        }
      }else{
        utils::AddPtrString(errorString)<<"TestCases with same pos in prio file";
        return false;
      }
    }else{
      utils::AddPtrString(errorString)<<"TestCase with missing information in prio file";
      return false;
    }
  }

  QList<int> keyList = tcMap.keys();
  qSort(keyList.begin(), keyList.end(), qLess<int>());
  for(int key : keyList){
    this->addTestCase(this->_d->_prioTCList.value(tcMap.value(key)), tcMap.value(key), errorString);
  }
  this->updateTestSuite();
  return true;
}

void TestexecutorModel::setTestSuite(model::ts::TestSuite* testsuite)
{
  qDebug()<<"TestexecutorModel::setTestSuite()";
  if(!testsuite){
    return;
  }
  this->reset();
  this->_d->_testSuite = testsuite;

  this->updateTestSuite();

  return;
}

model::ts::TestSuite* TestexecutorModel::testSuite()
{
  qDebug()<<"TestexecutorModel::testSuite()";
  return this->_d->_testSuite;
}

void TestexecutorModel::updateTestSuite()
{
  qDebug()<<"TestexecutorModel::updateTestSuite()";
  if(!this->_d->_testSuite){
    return;
  }
  this->invisibleRootItem()->clearData();
  this->invisibleRootItem()->removeRows(0, this->invisibleRootItem()->rowCount());

  for(model::ts::TestCaseItem* testCaseModel : this->_d->_testSuite->testCases()){
    QStandardItem* newTestCaseItem = new QStandardItem(testCaseModel->name());
    newTestCaseItem->setIcon(QIcon(QStringLiteral(":/mobata/images/ts/testcase.png")));
    newTestCaseItem->setFlags(newTestCaseItem->flags() & ~Qt::ItemIsEditable);

    if(!this->_d->_prioTCList.isEmpty()){
      newTestCaseItem->setCheckable(false);
      if(testCaseModel->isEnabled()){
        newTestCaseItem->setIcon(QIcon(QStringLiteral(":/mobata/images/ts/testcase.png")));
      }else{
        newTestCaseItem->setIcon(QIcon(QStringLiteral(":/mobata/images/ts/testcase2.png")));
      }
    }else{
      newTestCaseItem->setCheckable(true);
      if(testCaseModel->isEnabled()){
        newTestCaseItem->setCheckState(Qt::CheckState::Checked);
      }else{
        newTestCaseItem->setCheckState(Qt::CheckState::Unchecked);
      }
    }
    newTestCaseItem->setData(3, 258);
    this->invisibleRootItem()->appendRow(newTestCaseItem);
  }
  return;
}

void TestexecutorModel::setSutFilePath(const QString& sutFilePath)
{
  qDebug()<<"TestexecutorModel::setSutFilePath()";
  this->_d->_filePathSut=sutFilePath;

  return;
}

void TestexecutorModel::setTestSystemFilePath(const QString& testSystemFilePath)
{
  qDebug()<<"TestexecutorModel::setTestSystemFilePath()";
  this->_d->_filePathTs=testSystemFilePath;

  return;
}

const QString& TestexecutorModel::sutFilePath() const
{
  qDebug()<<"TestexecutorModel::sutFilePath()";
  return this->_d->_filePathSut;
}

const QString& TestexecutorModel::testSystemFilePath() const
{
  qDebug()<<"TestexecutorModel::testSystemFilePath()";
  return this->_d->_filePathTs;
}

bool TestexecutorModel::addTestCase(const QString& testCaseFilePath,
                                    model::ts::TestCaseItem* testCase,
                                    QString* errorString)
{
  qDebug()<<"TestexecutorModel::addTestCase()";
  Q_ASSERT(testCase);

  if(!QFileInfo(testCaseFilePath).exists()){
    utils::AddPtrString(errorString)<<tr("test case file '%1' does not exist!")
                                      .arg(testCaseFilePath);
    return false;
  }


  if(!this->_d->_filePathTestcases.isEmpty() && this->_d->_filePathTestcases.contains(testCaseFilePath)){
    utils::AddPtrString(errorString)<<tr("there is already a test case file '%1' available!")
                                      .arg(testCaseFilePath);
    return false;
  }

  if(!this->_d->_testSuite->addTestCase(testCase, errorString)){
    return false;
  }

  this->_d->_filePathTestcases.insert(testCaseFilePath, testCase);

  return true;
}

void TestexecutorModel::removeTestCase(const QString& testCaseFilePath)
{
  qDebug()<<"TestexecutorModel::removeTestCase()";
  model::ts::TestCaseItem* removeTestCase = this->_d->_filePathTestcases.value(testCaseFilePath);
  if(!removeTestCase){
    return;
  }

  this->_d->_testSuite->removeTestCase(removeTestCase);
  this->_d->_filePathTestcases.remove(testCaseFilePath);

  return;
}

QList<QString> TestexecutorModel::testCaseFiles() const
{
  qDebug()<<"TestexecutorModel::testCaseFiles()";
  return this->_d->_filePathTestcases.keys();
}

model::ts::TestCaseItem* TestexecutorModel::testCaseModel(const QString& testCaseFile)
{
  qDebug()<<"TestexecutorModel::testCaseModel()";
  return this->_d->_filePathTestcases.value(testCaseFile, nullptr);
}

QString TestexecutorModel::testCaseFile(model::ts::TestCaseItem* testCaseModel) const
{
  qDebug()<<"TestexecutorModel::testCaseFile()";
  for(QString file : this->_d->_filePathTestcases.keys()){
    if(this->_d->_filePathTestcases.value(file) == testCaseModel){
      return file;
    }
  }

  return QStringLiteral("");
}

Qt::DropActions TestexecutorModel::supportedDropActions() const
{
  return Qt::MoveAction;
}

void TestexecutorModel::handleItemChange(QStandardItem* item)
{
  qDebug()<<"TestexecutorModel::handleItemChange()";
  if(!item){
    return;
  }

  if(item->data(258) == 0){
    int rowCount = item->rowCount();
    for(int i = 0; i<rowCount; ++i){
      QStandardItem* childItem = item->child(i);
      if(!childItem->isCheckable()){
        continue;
      }

      if(item->checkState()==Qt::Checked){
        childItem->setCheckState(Qt::Checked);
      }else if(item->checkState()==Qt::Unchecked){
        childItem->setCheckState(Qt::Unchecked);
      }
    }
  }else if(item->isCheckable() && item->data(258) == 3){
    for(QString filename : this->_d->_filePathTestcases.keys()){
      model::ts::TestCaseItem* tc = this->_d->_filePathTestcases.value(filename);
      if(tc->name() == item->text()){
        QFile file(filename);
        file.open(QIODevice::ReadWrite);
        QString data = file.readAll();
        file.close();
        file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text);
        QStringList dataList = data.split("\n");
        data = "";
        for(QString line : dataList){
          if(line.contains("enabled:")){
            if(item->checkState()==Qt::Checked){
              tc->setEnabled(true);
              line = "    enabled: true;";
            }else if(item->checkState()==Qt::Unchecked){
              tc->setEnabled(false);
              line = "    enabled: false;";
            }
          }
          data += line + "\n";
        }
        file.write(data.toUtf8());
        file.close();
      }
    }
  }
  return;
}

}
