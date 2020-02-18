#include "errortracker.hpp"

void addError(const QString& description, const int line, const QUrl& uri, QList<QQmlError>& errorList)
{
    QQmlError newError;
    newError.setDescription(description);
    newError.setLine(line);
    newError.setUrl(uri);
    errorList.append(newError);
}

void addErrors(const QList<QQmlError>& errors, QList<QQmlError>& errorList)
{
    errorList.append(errors);
}

void clearErrorList(QList<QQmlError>& errorList)
{
    errorList.clear();
}

bool hasError(const QList<QQmlError>& errorList)
{
    return !errorList.isEmpty();
}

