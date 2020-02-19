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
#ifndef TRAFFICSIMLIB_ERRORTRACKER_HPP
#define TRAFFICSIMLIB_ERRORTRACKER_HPP

#include "QQmlError"

void addError(const QString& description, const int line, const QUrl& uri, QList<QQmlError>& errorList);
void addErrors(const QList<QQmlError>& errors, QList<QQmlError>& errorList);
void clearErrorList(QList<QQmlError>& errorList);
bool hasError(const QList<QQmlError>& errorList);

#endif // TRAFFICSIMLIB_ERRORTRACKER_HPP
