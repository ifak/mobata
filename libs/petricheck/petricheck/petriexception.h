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
#ifndef PETRIEXCEPTION_H
#define PETRIEXCEPTION_H

#include <QException>

class PetriException : public QException
{
public:
  PetriException(const QString &info): info(info) {}
  void raise() const { throw *this; }
  PetriException *clone() const { return new PetriException(*this); }
  const QString &whats() { return info; }

private:
  QString info;
};

#endif // PETRIEXCEPTION_H
