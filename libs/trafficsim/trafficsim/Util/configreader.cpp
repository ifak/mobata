#include "configreader.hpp"

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "errortracker.hpp"

ConfigReader::ConfigReader() : _numLines(0)
{
    // Do nothing
}

ConfigReader::~ConfigReader()
{
    // Do nothing
}

const QMap<int, QString> &ConfigReader::mapping() const
{
    return _laneMap;
}

bool ConfigReader::readConfig(QString fileName, QList<QQmlError> &errorList)
{
    _laneMap.clear();
    _nameMap.clear();

    QFile config(fileName);
    if (!config.open(QIODevice::ReadOnly))
    {
        //qDebug()<<"Could not open config file" << fileName;
        addError(QLatin1String("Could not open the config file"), -1, QUrl::fromLocalFile(fileName), errorList);
        return false;
    }

    QTextStream in(&config);
    QString line = in.readLine();
    QStringList tempNameList;
    QStringList splitLine;
    bool isOk;
    int count = 0;
    bool result = true;
    while (!line.isNull())
    {
        splitLine = line.split(" ");
        if (2 != splitLine.size())
        {
            QString errorMsg(QString::fromLatin1("Not enough or to many arguments in one line a line need to be a number followed by a name"));
            //qDebug()<< errorMsg;
            addError(errorMsg, count+1, QUrl::fromLocalFile(fileName), errorList);
            result = false;
        }

        int key = splitLine.at(0).toInt(&isOk);
        if (!isOk)
        {
            QString errorMsg(QString::fromLatin1("First parameter is not a number for line "));
            errorMsg.append(line);
            //qDebug()<< errorMsg;
            addError(errorMsg, count+1, QUrl::fromLocalFile(fileName), errorList);
            result = false;
        }

        if (tempNameList.contains(splitLine.at(1)))
        {
            QString errorMsg(QString::fromLatin1("Each name must be unique! "));
            errorMsg.append(splitLine.at(1))
                    .append(QString::fromLatin1(" is already define above."));
            //qDebug()<< errorMsg;
            addError(errorMsg, count+1, QUrl::fromLocalFile(fileName), errorList);
            result = false;
        }

        tempNameList.append(splitLine.at(1));
        _nameMap.insert(key, splitLine.at(1));
        _laneMap.insert(count, splitLine.at(1));

        count++;
        line = in.readLine();
    }

    _numLines = count;

    return result;
}

const QMap<int, QString> &ConfigReader::nameMap() const
{
    return _nameMap;
}

int ConfigReader::numLines() const
{
    return _numLines;
}

