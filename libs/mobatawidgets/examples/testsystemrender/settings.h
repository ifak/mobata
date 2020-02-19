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
#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

#include <QSettings>
#include <QFileInfo>
#include <QCoreApplication>
#include <QStandardItem>
#include <QStandardItemModel>

#include <QDebug>

#include <mobatawidgets/graph/types.hpp>
#include <mobatawidgets/ts/comrendersut.hpp>

enum ErrorType {not_found, not_allowed};

struct ErrorReport
{
    ErrorReport(ErrorType et, QString ei) : type(et), item(ei)
    {}

    ErrorType type;
    QString   item;
};

template <typename P, typename T> void setProperty(const P& property, T& (T:: *setDelegate)(const P&), T* targetOptions);

template <typename T> inline void setPen(const QPen& pen, T* targetOptions)
{
    try
    {
        setProperty<QPen, T>(pen, &T::setPen, targetOptions);
    }
    catch (...)
    {
        throw ErrorReport(not_allowed, QString("setPen() operation is not possible."));
    }
}

template <typename T> inline void setColor(const QColor& color, T* targetOptions)
{
    try
    {
        setProperty<QColor, T>(color, &T::setColor, targetOptions);
    }
    catch (...)
    {
        throw ErrorReport(not_allowed, QString("setColor() operation is not possible."));
    }
}

template <typename T> inline void setSize(const QSizeF& size, T* targetOptions)
{
    try
    {
        setProperty<QSizeF, T>(size, &T::setSize, targetOptions);
    }
    catch (...)
    {
        throw ErrorReport(not_allowed, QString("setSize() operation is not possible."));
    }
}

template <typename T> inline void setTextColor(const QColor& color, T* targetOptions)
{
    try
    {
        setProperty<QColor, T>(color, &T::setTextColor, targetOptions);
    }
    catch (...)
    {
        throw ErrorReport(not_allowed, QString("setTextColor() operation is not possible."));
    }
}

template <typename T> inline void setTextFont(const QFont& font, T* targetOptions)
{
    try
    {
        setProperty<QFont, T>(font, &T::setTextFont, targetOptions);
    }
    catch (...)
    {
        throw ErrorReport(not_allowed, QString("setTextFont() operation is not possible."));
    }
}

void setNodeOptionsDelegate(const view::graph::NodeOptions& options, view::graph::NodeOptions* targetOptions);
void setArcOptionsDelegate(const view::graph::ArcOptions& options, view::graph::ArcOptions* targetOptions);
void setMiscOptionsDelegate(const QVariant& options, QVariant* targetOptions);

class Settings : public QObject
{
    Q_OBJECT
public:
    explicit Settings(QObject *parent = 0, QString settingPrefix = QString(""), QString appInfo = QFileInfo(QCoreApplication::applicationFilePath()).completeBaseName(), QString orgInfo = QString("ifak"));
    Settings(const Settings& source, QObject *parent = 0);
    ~Settings();

    QString settingPrefix();

    view::graph::NodeOptions* findNodeOptions(const QString categoryName) const
    {
        return findOptions<view::graph::NodeOptions>(categoryName, _nodeOptionList);
    }

    view::graph::ArcOptions* findArcOptions(const QString categoryName) const
    {
        return findOptions<view::graph::ArcOptions>(categoryName, _arcOptionList);
    }

    QVariant* findMiscOptions(const QString categoryName) const
    {
        return findOptions<QVariant>(categoryName, _miscOptionList);
    }

    void addNodeTypeSettings(const QString categoryName, const view::graph::NodeOptions& defaultOptions, const QString additionalInfo = QString(""))
    {
        addSettings<view::graph::NodeOptions>(categoryName, defaultOptions, additionalInfo, _nodeOptionList);
    }

    void addArcTypeSettings(const QString categoryName, const view::graph::ArcOptions& defaultOptions, const QString additionalInfo = QString(""))
    {
        addSettings<view::graph::ArcOptions>(categoryName, defaultOptions, additionalInfo, _arcOptionList);
    }

    void addMiscSettings(const QString categoryName, const QVariant& defaultOptions, const QString additionalInfo = QString(""))
    {
        addSettings<QVariant>(categoryName, defaultOptions, additionalInfo, _miscOptionList);
    }

    void setNodeOptions(const QString categoryName, const view::graph::NodeOptions& options)
    {
        setOptions<view::graph::NodeOptions>(categoryName, options, &setNodeOptionsDelegate, _nodeOptionList);
        emit nodeOptionsModified(categoryName);
    }

    void setArcOptions(const QString categoryName, const view::graph::ArcOptions& options)
    {
        setOptions<view::graph::ArcOptions>(categoryName, options, &setArcOptionsDelegate, _arcOptionList);
        emit arcOptionsModified(categoryName);
    }

    void setMiscOptions(const QString categoryName, const QVariant& options)
    {
        setOptions<QVariant>(categoryName, options, &setMiscOptionsDelegate, _miscOptionList);
        emit miscOptionsModified(categoryName);
    }

    void replaceNodeOptions(const QString categoryName, const view::graph::NodeOptions& options)
    {
        replaceOptions<view::graph::NodeOptions>(categoryName, options, _nodeOptionList);
        emit nodeOptionsReplaced(categoryName);
    }

    void replaceArcOptions(const QString categoryName, const view::graph::ArcOptions& options)
    {
        replaceOptions<view::graph::ArcOptions>(categoryName, options, _arcOptionList);
        emit arcOptionsReplaced(categoryName);
    }

    void replaceMiscOptions(const QString categoryName, const QVariant& options)
    {
        replaceOptions<QVariant>(categoryName, options, _miscOptionList);
        emit miscOptionsReplaced(categoryName);
    }

    void removeNodeTypeSettings(const QString categoryName)
    {
        removeSettings<view::graph::NodeOptions>(categoryName, _nodeOptionList);
        emit nodeOptionsRemoved(categoryName);
    }

    void removeArcTypeSettings(const QString categoryName)
    {
        removeSettings<view::graph::ArcOptions>(categoryName, _arcOptionList);
        emit arcOptionsRemoved(categoryName);
    }

    void removeMiscSettings(const QString categoryName)
    {
        removeSettings<QVariant>(categoryName, _miscOptionList);
        emit miscOptionsRemoved(categoryName);
    }

    int readNodeSettingsFromConfigFile(const QString categoryName);
    int readArcSettingsFromConfigFile(const QString categoryName);
    int readMiscSettingsFromConfigFile(const QString categoryName);
    int readAllSettingsFromConfigFile();
    void writeNodeSettingsToConfigFile(const QString categoryName);
    void writeArcSettingsToConfigFile(const QString categoryName);
    void writeMiscSettingsToConfigFile(const QString categoryName);
    void writeAllSettingsToConfigFile();
    QStandardItem* exportNodeProperties(const QString categoryName) const;
    QStandardItem* exportArcProperties(const QString categoryName) const;
    QStandardItem* exportMiscProperties() const;
    QStandardItem* exportAllPropertiesToQStandardItem(const QString customPrefix = QString("")) const;
    QStandardItemModel* exportAllPropertiesToQStandardItemModel(QObject *parent = 0, const QString customPrefix = QString("")) const;
    void importNodeProperties(const QStandardItem* item);
    void importArcProperties(const QStandardItem* item);
    void importMiscProperties(const QStandardItem* item);
    void importAllPropertiesFromQStandardItem(QStandardItem* itemGroup, const QString customPrefix = QString(""));
    void importAllPropertiesFromQStandardItemModel(QStandardItemModel* model, const QString customPrefix = QString(""));

public slots:
    void synchronizeOptions(QStandardItem* itemGroup);
    void synchronizeOptions(QStandardItemModel* model);
    void updateNodeConfig(QString categoryName);
    void updateArcConfig(QString categoryName);
    void updateMiscConfig(QString categoryName);

signals:
    void nodeOptionsModified(QString categoryName);
    void arcOptionsModified(QString categoryName);
    void miscOptionsModified(QString categoryName);
    void nodeOptionsReplaced(QString categoryName);
    void arcOptionsReplaced(QString categoryName);
    void miscOptionsReplaced(QString categoryName);
    void nodeOptionsRemoved(QString categoryName);
    void arcOptionsRemoved(QString categoryName);
    void miscOptionsRemoved(QString categoryName);
    void optionsChanged();

private:
    template <typename T>
    struct OptionInfoSt
    {
        OptionInfoSt(QString in, T io, QString ai = QString("")) : infoName(in), infoOptions(io), additionalInfo(ai)
        {}

        QString infoName;
        T infoOptions;
        QString additionalInfo;
    };

    const QString _settingPrefix;
    QSettings* _configs;
    QList<OptionInfoSt<view::ts::NodeOptions> > _nodeOptionList;
    QList<OptionInfoSt<view::ts::ArcOptions> > _arcOptionList;
    QList<OptionInfoSt<QVariant> > _miscOptionList;

protected:
    template <typename T> void* findSettings(const QString categoryName, const QList<OptionInfoSt<T> >& container) const;
    void* findMiscSetting(const QString categoryName) const
    {
        return findSettings<QVariant>(categoryName, _miscOptionList);
    }

    template <typename T> T* findOptions(const QString categoryName, const QList<OptionInfoSt<T> >& container) const
    {
        return &(static_cast<OptionInfoSt<T>* >(findSettings<T>(categoryName, container))->infoOptions);
    }

    template <typename T> void addSettings(const QString categoryName, const T& defaultOptions, const QString additionalInfo, QList<OptionInfoSt<T> >& container);
    template <typename T> int removeSettings(const QString categoryName, QList<OptionInfoSt<T> >& container);
    template <typename T> void replaceOptions(const QString categoryName, const T& options, QList<OptionInfoSt<T> >& container);
    template <typename T> void setOptions(const QString categoryName, const T& options, void (*setOptionsDelegate)(const T&, T*), QList<OptionInfoSt<T> >& container);

    template <typename T> int readPenSettingFromConfigFile(T* targetOptions, T& (T:: *setDelegate)(const QPen&));
    template <typename T> int readColorSettingFromConfigFile(T* targetOptions, T& (T:: *setDelegate)(const QColor&));
    template <typename T> int readSizeSettingFromConfigFile(T* targetOptions, T& (T:: *setDelegate)(const QSizeF&));
    template <typename T> int readFontSettingFromConfigFile(T* targetOptions, T& (T:: *setDelegate)(const QFont&));
    template <typename T> void writePenSettingsToConfigFile(T* sourceOptions, QPen (T:: *getDelegate)() const);
    template <typename T> void writeColorSettingsToConfigFile(T* sourceOptions, QColor (T:: *getDelegate)() const);
    template <typename T> void writeSizeSettingsToConfigFile(T* sourceOptions, QSizeF (T:: *getDelegate)() const);
    template <typename T> void writeFontSettingsToConfigFile(T* sourceOptions, QFont (T:: *getDelegate)() const);
    template <typename T> QList<QList<QStandardItem*> > exportPenProperty(QString title, T* sourceOptions, QPen (T:: *getDelegate)() const) const;
    template <typename T> QList<QStandardItem*> exportColorProperty(QString title, T* sourceOptions, QColor (T:: *getDelegate)() const) const;
    template <typename T> QList<QStandardItem*> exportSizeProperty(QString title, T* sourceOptions, QSizeF (T:: *getDelegate)() const) const;
    template <typename T> QList<QStandardItem*> exportFontProperty(QString title, T* sourceOptions, QFont (T:: *getDelegate)() const) const;
    template <typename T> void importPenProperty(const QPen& pen, T* targetOptions, T& (T:: *setDelegate)(const QPen&));
    template <typename T> void importColorProperty(const QStandardItem* item, T* targetOptions, T& (T:: *setDelegate)(const QColor&));
    template <typename T> void importSizeProperty(const QStandardItem* item, T* targetOptions, T& (T:: *setDelegate)(const QSizeF&));
    template <typename T> void importFontProperty(const QStandardItem* item, T* targetOptions, T& (T:: *setDelegate)(const QFont&));
};

#include "settings.hpp"

#endif // SETTINGS_H
