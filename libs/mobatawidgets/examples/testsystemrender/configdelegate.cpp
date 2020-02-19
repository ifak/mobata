#include "configdelegate.h"

#include <QPainter>
#include <QModelIndex>
#include <QPointF>
#include <QSpinBox>
#include <QFontComboBox>
#include <QFontDatabase>
#include <QCheckBox>
#include <QLabel>

#include <QStyleOptionButton>
#include <QApplication>

ConfigDelegate::ConfigDelegate(QObject *parent) : QStyledItemDelegate(parent)
{
  // do nothing
}

ConfigDelegate::~ConfigDelegate()
{
  // do nothing
}

void ConfigDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (option.state & QStyle::State_Selected)
    {
        painter->fillRect(option.rect, option.palette.highlight());
    }

    QString str = index.data().toString();
    if (str.isEmpty())
    {
        return;
    }

    painter->save();

    QString typeStr = index.model()->data(index.sibling(index.row(), 2)).toString();
    if ((!typeStr.compare(QString("COLOR"))) || (!typeStr.compare(QString("BRUSHCOLOR"))))
    {
        painter->setBrush(QColor(str));
        painter->setPen(Qt::black);
        painter->drawRect(option.rect.x()+2, option.rect.y()+2, option.rect.width()-5, option.rect.height()-5);
    }
    else if (!typeStr.compare(QString("BOOLEANOPTION")))
    {
        QStyleOptionButton checkbox;
        checkbox.rect = option.rect;
        checkbox.rect.setLeft(option.rect.x()+2);
        bool checkState = index.data().toBool();
        checkbox.state = (checkState)?(QStyle::State_On):(QStyle::State_Off);
        checkbox.state |= QStyle::State_Enabled;
        QApplication::style()->drawControl(QStyle::CE_CheckBox, &checkbox, painter);
    }
    else
    {
        QPoint pnt(option.rect.x()+2, option.rect.y()+option.fontMetrics.height());
        painter->setPen(Qt::black);
        painter->drawText(pnt, index.data().toString());
    }

    painter->restore();

    return;
}

QSize ConfigDelegate::sizeHint(const QStyleOptionViewItem &option,
                               const QModelIndex &index) const
{
  Q_UNUSED(index);

  //return QStyledItemDelegate::sizeHint(option, index);
  return QSize(option.rect.width(), 18);
}

QWidget* ConfigDelegate::createEditor(QWidget *parent,
                                      const QStyleOptionViewItem &option,
                                      const QModelIndex &index) const
{
  Q_UNUSED(option);

  QWidget *widget;

  QString typeStr = index.model()->data(index.sibling(index.row(), 2)).toString();
  if (!typeStr.compare(QString("LENGTH")))
  {
    QSpinBox *spinbox = new QSpinBox(parent);
    spinbox->setMinimum(1);
    spinbox->setMaximum(999);
    widget = spinbox;
  }
  else if (!typeStr.compare(QString("FONT")))
  {
    QFontComboBox *combobox = new QFontComboBox(parent);
    combobox->setFontFilters(QFontComboBox::AllFonts);
    widget = combobox;
  }
  else if (!typeStr.compare(QString("FONTSIZE")))
  {
    QComboBox *comboBox = new QComboBox(parent);
    for (int i = 0; i < index.model()->rowCount(index.parent()); i++)
    {
      QString tempStr = index.model()->data(index.sibling(i, 2)).toString();
      if (!tempStr.compare(QString("FONT")))
      {
        QString fontName = index.model()->data(index.sibling(i, 1)).toString();
        QFontDatabase fdb;
        QList<int> xlist = fdb.pointSizes(fontName);
        for (int j = 0; j < xlist.count(); j++)
        {
          comboBox->addItem(QString("%1").arg(xlist.at(j)));
        }
        break;
      }
    }

    widget = comboBox;
  }
  else if (!typeStr.compare(QString("BOOLEANOPTION")))
  {
    QCheckBox *checkbox = new QCheckBox(parent);
    widget = checkbox;
  }
  else
  {
    QLabel *label = new QLabel("", parent);
    widget = label;
  }

  return widget;
}

void ConfigDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
  QString typeStr = index.model()->data(index.sibling(index.row(), 2)).toString();
  if (!typeStr.compare(QString("LENGTH")))
  {
    int val = index.data(Qt::DisplayRole).toInt();
    static_cast<QSpinBox*>(editor)->setValue(val);
  }
  else if (!typeStr.compare(QString("FONT")))
  {
    QString seriesStr(index.data(Qt::DisplayRole).toString());
    QFontComboBox *comboBox = static_cast<QFontComboBox*>(editor);
    int currFontIndex = comboBox->findText(seriesStr);
    comboBox->setCurrentIndex(currFontIndex);
  }
  else if (!typeStr.compare(QString("FONTSIZE")))
  {
    QString sizeStr(index.data(Qt::DisplayRole).toString());
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    int currIndex = comboBox->findText(sizeStr);
    comboBox->setCurrentIndex(currIndex);
  }
  else if (!typeStr.compare(QString("BOOLEANOPTION")))
  {
    static_cast<QCheckBox*>(editor)->setChecked(!index.data(Qt::DisplayRole).toBool());
  }
}

void ConfigDelegate::setModelData(QWidget *editor,
                                  QAbstractItemModel *model,
                                  const QModelIndex &index) const
{
  QString typeStr = index.model()->data(index.sibling(index.row(), 2)).toString();
  if (!typeStr.compare(QString("LENGTH")))
  {
    model->setData(index, QString("%1").arg(static_cast<QSpinBox*>(editor)->value()));
  }
  else if (!typeStr.compare(QString("FONT")))
  {
    model->setData(index, static_cast<QFontComboBox*>(editor)->currentText());
  }
  else if (!typeStr.compare(QString("FONTSIZE")))
  {
    model->setData(index, static_cast<QComboBox*>(editor)->currentText());
  }
  else if (!typeStr.compare(QString("BOOLEANOPTION")))
  {
    model->setData(index, QString("%1").arg(static_cast<QCheckBox*>(editor)->isChecked()));
  }
}

void ConfigDelegate::updateEditorGeometry(QWidget * editor, const QStyleOptionViewItem & option, const QModelIndex & index) const
{

  QString typeStr = index.model()->data(index.sibling(index.row(), 2)).toString();
  if (!typeStr.compare(QString("BOOLEANOPTION")))
  {
    QRect rect(option.rect.x()+2, option.rect.y(), option.rect.width()-2, option.rect.height());
    editor->setGeometry(rect);
  }
  else
  {
    editor->setGeometry(option.rect);
  }
}
