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

#include <QtCore/qglobal.h>
#include <QVector>
#include <QVariant>

#if defined(MODSIM_LIBRARY)
#  define MODSIMSHARED_EXPORT Q_DECL_EXPORT
#elif(MODSIM_LIBRARY_STATIC)
#  define MODSIMSHARED_EXPORT
#else
#  define MODSIMSHARED_EXPORT Q_DECL_IMPORT
#endif
