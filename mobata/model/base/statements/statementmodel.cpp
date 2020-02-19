#include "statementmodel.hpp"
#include <QVector>
#include <QHash>

namespace model{
namespace base{
namespace statement{

class StatementModel::Private
{
  friend class StatementModel;

  StatementType _type;
  QString       _content;
  QString       _collectionNormalStatements;

  Private(StatementType type,
          const QString& content)
    : _type(type),
      _content(content)
  {}
  ~Private(){
  }
};

StatementModel::StatementModel():
  _d(new Private(baseStatement,
                 QString("")))
{

}

StatementModel::StatementModel(StatementType type, const QString& content):
  _d(new Private(type,content))
{

}

StatementModel::~StatementModel()
{
  delete this->_d;
}

void StatementModel::setContent(const QString& content)
{
  _d->_content = content;
}

void StatementModel::setType(StatementType type)
{
  _d->_type = type;
}

const QString& StatementModel::content()
{
  return _d->_content;
}

StatementType StatementModel::type()
{
  return _d->_type;
}

}// end namespace statement
}// end namespace base
}// end namespace model
