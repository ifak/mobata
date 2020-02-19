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
#ifndef CONFIGREADER_HPP
#define CONFIGREADER_HPP

#include <QMap>
#include <QQmlError>

/**
 * @brief The ConfigReader class resposnsible for reading and analysing the configuration file
 */
class ConfigReader
{
public:
    /**
     * @brief ConfigReader
     */
    ConfigReader();
    ~ConfigReader();

    /**
     * @brief mapping
     * @return the mapping of the lanes to the real model
     */
    const QMap<int, QString>& mapping() const;

    /**
     * @brief readConfig tries to read the config
     * @param fileName path to the config file
     * @param errorList container for read errors
     * @return true if succesfull read
     */
    bool readConfig(QString fileName, QList<QQmlError>& errorList);

    /**
     * @brief nameMap
     * @return the mapping of the names
     */
    const QMap<int, QString>& nameMap() const;

    /**
     * @brief numLines
     * @return
     */
    int numLines() const;

private:
    QMap<int, QString> _laneMap;
    QMap<int, QString> _nameMap;
    int _numLines;
};

#endif // CONFIGREADER_HPP
