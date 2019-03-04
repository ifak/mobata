/*
 * This file is part of mobata.
 *
 * Copyright (C) 2019 ifak, https://www.ifak.eu/
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

#include <limits>
#include <vector>
#include <set>

#include <QString>
#include <QVariant>
#include <QChar>

namespace std
{
/*!
Own implementation of std::abs()
*/
template<typename T> inline
T abs(T arg)
{
  return ((arg<0) ? -arg : arg);
}

}// end namespace std

namespace utils
{

/*!
Template operation returns whether \a currentValue has a next value.
*/
template<typename PodType> inline bool hasNext(const PodType currentValue);

/*!
Specialized template operation returns whether \a currentValue has a next int-value.
*/
template<> inline bool hasNext<int>(const int currentValue)
{
  return (currentValue < std::numeric_limits<int>::max());
}

/*!
Specialized template operation returns whether \a currentValue has a next double-value.
*/
template<> inline bool hasNext(const double currentValue)
{
  return (currentValue < std::numeric_limits<double>::max());
}

/*!
Template operation returns the next value of \a currentValue
*/
template<typename PodType> inline PodType next(const PodType currentValue);

/*!
Specialized template operation returns the next int-value of \a currentValue
*/
template<> inline int next(const int currentValue)
{
  return (currentValue+1);
}

/*!
Specialized template operation returns the next double-value of \a currentValue
*/
template<> inline double next(const double currentValue)
{
  return (currentValue + std::numeric_limits<double>::epsilon());
}

/*!
Template operation returns whether \a currentValue has a previous value.
*/
template<typename PodType> inline bool hasPrev(const PodType currentValue);

/*!
Specialized template operation returns whether \a currentValue has a previous int-value.
*/
template<> inline bool hasPrev<int>(const int currentValue)
{
  return (currentValue > std::numeric_limits<int>::max());
}

/*!
Specialized template operation returns whether \a currentValue has a previous double-value.
*/
template<> inline bool hasPrev(const double currentValue)
{
  return (currentValue > std::numeric_limits<double>::max());
}

/*!
Template operation returns the previous value of \a currentValue
*/
template<typename PodType> inline PodType prev(const PodType currentValue);

/*!
Specialized template operation returns the previous int-value of \a currentValue
*/
template<> inline int prev(const int currentValue)
{
  return (currentValue-1);
}

/*!
Specialized template operation returns the previous double-value of \a currentValue
*/
template<> inline double prev(const double currentValue)
{
  return (currentValue - std::numeric_limits<double>::epsilon());
}

/*!
Template based functor compares two values of equality and returns the boolean result.
*/
template<typename LeftPodType, typename RightPodType=LeftPodType>
struct EqualsTo
{
  inline bool operator()(const LeftPodType _left, const RightPodType _right)
  {
    return (_left == _right);
  }
};

/*!
Template based functor (specialized for one double value) compares two values
of equality and returns the boolean result.
*/
template<typename LeftPodType>
struct EqualsTo<LeftPodType, double>
{
  inline bool operator()(const LeftPodType _left, const double _right) const
  {
    return (std::abs(_left - _right) <= std::numeric_limits<double>::epsilon());
  }
};

/*!
Template based functor (specialized for one double value) compares two values
of equality and returns the boolean result.
*/
template<typename RightPodType>
struct EqualsTo<double, RightPodType>
{
  inline bool operator()(const double _left, const RightPodType _right) const
  {
    return (std::abs(_left - _right) <= std::numeric_limits<double>::epsilon());
  }
};

/*!
Template based functor (specialized for two double value) compares two values
of equality and returns the boolean result.
*/
template<>
struct EqualsTo<double, double>
{
  inline bool operator()(const double _left, const double _right) const
  {
    return (std::abs(_left - _right) <= std::numeric_limits<double>::epsilon());
  }
};

/*!
Template returns the string description of pod-type \a PodType.
*/
template<typename PodType> inline
QString podtype2string();

/*!
Specialized template returns 'int' for pod type \a integer.
*/
template<> inline
QString podtype2string<int>()
{
  return QStringLiteral("int");
}

/*!
Specialized template returns 'float' for pod type \a double.
*/
template<> inline
QString podtype2string<double>()
{
  return QStringLiteral("real");
}

/*!
Specialized template returns 'float' for pod type \a float.
*/
template<> inline
QString podtype2string<float>()
{
  return QStringLiteral("real");
}

/*!
Specialized template returns 'long' for pod type \a long.
*/
template<> inline
QString podtype2string<long>()
{
  return QStringLiteral("int");
}

/*!
Specialized template returns 'short' for pod type \a short.
*/
template<> inline
QString podtype2string<short>()
{
  return QStringLiteral("int");
}

/*!
Specialized template returns 'string' for pod type \a std::string.
*/
template<> inline
QString podtype2string<QString>()
{
  return QStringLiteral("string");
}

/*!
Specialized template returns 'bool' for pod type \a bool.
*/
template<> inline
QString podtype2string<bool>()
{
  return QStringLiteral("bool");
}

/*!
Template tries to read in a pod value value for a string \a valueString.
*/
template<typename PodType> inline
bool string2podvalue(const QString& valueString,
                     PodType* podValue,
                     QString* errorMessage)
{
  Q_ASSERT(podValue);
  Q_UNUSED(errorMessage);

  *podValue=PodType(valueString);

  return true;
}

/*!
Specialized template tries to read in a int value value for a string \a valueString.
*/
template<> inline
bool string2podvalue<int>(const QString& valueString,
                          int* podValue,
                          QString* errorMessage)
{
  Q_ASSERT(podValue);

  bool error=false;
  *podValue=valueString.toInt(&error);
  if(error)
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("string '%1' could not be converted to a int value!")
                     .arg(valueString);
    return false;
  }

  return true;
}

/*!
Specialized template tries to read in a double value value for a string \a valueString.
*/
template<> inline
bool string2podvalue<double>(const QString& valueString,
                             double* podValue,
                             QString* errorMessage)
{
  Q_ASSERT(podValue);

  bool error=false;
  *podValue=valueString.toDouble(&error);
  if(error)
  {
    if(errorMessage)
      *errorMessage+=QObject::tr("string '%1' could not be converted to a double value!")
                     .arg(valueString);
    return false;
  }

  return true;
}

/*!
Specialized template tries to read in a string value value for a string \a valueString.
*/
template<> inline
bool string2podvalue<QString>(const QString& valueString,
                              QString* podValue,
                              QString* errorMessage)
{
  Q_UNUSED(errorMessage);
  Q_ASSERT(podValue);

  *podValue=valueString;

  return true;
}

/*!
Specialized template tries to read in a bool value value for a string \a valueString.
*/
template<> inline
bool string2podvalue<bool>(const QString& valueString,
                           bool* podValue,
                           QString* errorMessage)
{
  Q_ASSERT(podValue);

  if(valueString.compare(QStringLiteral("true"),
                         Qt::CaseInsensitive)==0)
  {
    *podValue=true;
    return true;
  }
  else if(valueString.compare(QStringLiteral("false"),
                              Qt::CaseInsensitive)==0)
  {
    *podValue=false;
    return true;
  }
  else
  {
    bool error;
    int value=valueString.toInt(&error);
    if(error)
    {
      if(errorMessage)
        *errorMessage+=QObject::tr("string '%1' could not be converted to a boolean value!")
                       .arg(valueString);
      return false;
    }

    if(value)
    {
      *podValue=true;
      return true;
    }
    else
    {
      *podValue=false;
      return true;
    }
  }

  if(errorMessage)
    *errorMessage+=QObject::tr("string '%1' could not be converted to a boolean value!")
                   .arg(valueString);
  return false;///should never be reached...
}

/*!
Template returns a QVariant value for a string \a valueString.
*/
template<typename PodType> inline
QVariant string2variant(const QString& valueString);

/*!
Specialized template returns int-value-variant for \a valueString.
*/
template<> inline
QVariant string2variant<int>(const QString& valueString)
{
  bool error=false;
  int value=valueString.toInt(&error);
  if(error)
    return QVariant();

  return QVariant(value);
}

/*!
Specialized template returns double-value-variant for \a valueString.
*/
template<> inline
QVariant string2variant<double>(const QString& valueString)
{
  bool error=false;
  int value=valueString.toDouble(&error);
  if(error)
    return QVariant();

  return QVariant(value);
}

/*!
Specialized template returns string-value-variant for \a valueString.
*/
template<> inline
QVariant string2variant<QString>(const QString& valueString)
{
  return QVariant(valueString);
}

/*!
Specialized template returns bool-value-variant for \a valueString.
*/
template<> inline
QVariant string2variant<bool>(const QString& valueString)
{
  if(valueString.compare(QStringLiteral("true"),
                         Qt::CaseInsensitive)==0)
    return QVariant(true);
  else if(valueString.compare(QStringLiteral("false"),
                              Qt::CaseInsensitive)==0)
    return QVariant(false);
  else
  {
    bool error=false;
    int value=valueString.toInt(&error);
    if(error)
      return QVariant();
    if(value)
      return QVariant(true);
    else
      return QVariant(false);
  }

  return QVariant();///should never be reached...
}

template<class Collection>
struct FindByName
{
  typedef typename Collection::value_type	ReturnType;

  template<class StringType>
  ReturnType operator() (const StringType& objectName,
                         const Collection& set)
  {
    typename Collection::const_iterator o_it;
    for(o_it=set.begin(); o_it!=set.end(); o_it++)
    {
      if((*o_it)->name()==objectName)
        return (*o_it);
    }

    return 0;
  }
};

template<class Collection>
struct FindByPlace
{
  typedef typename Collection::value_type	ReturnType;

  template<class PlacType>
  ReturnType operator() (const PlacType& place,
                         const Collection& set)
  {
    if(!place)
      return 0;

    typename Collection::const_iterator o_it;
    for(o_it=set.begin(); o_it!=set.end(); o_it++)
    {
      if((*o_it)->place()==place)
        return (*o_it);
    }

    return 0;
  }
};

template<class Collection>
struct FindByUuid
{
  typedef typename Collection::value_type	ReturnType;

  template<class UuidType>
  ReturnType operator() (const UuidType& objectUuid,
                         const Collection& set)
  {
    typename Collection::const_iterator o_it;
    for(o_it=set.begin(); o_it!=set.end(); o_it++)
    {
      if((*o_it)->uuid()==objectUuid)
        return (*o_it);
    }

    return 0;
  }
};

template<class Collection>
struct FindByID
{
  typedef typename Collection::value_type	ReturnType;

  template<typename IdType>
  ReturnType operator() (const IdType objectID,
                         const Collection& set)
  {
    typename Collection::const_iterator o_it;
    for(o_it=set.begin(); o_it!=set.end(); o_it++)
    {
      if((*o_it)->getID()==objectID)
        return (*o_it);
    }

    return 0;
  }
};

template<class Collection>
struct IsPlaceAvailable
{
  Collection _collection;

  IsPlaceAvailable(const Collection& collection)
    :	_collection(collection)
  {}

  template<class PlaceType>
  inline bool operator() (PlaceType place) const
  {
    typename Collection::const_iterator o_it;
    for(o_it=this->_collection.begin();
        o_it!=this->_collection.end();
        ++o_it)
    {
      if((*o_it)->place()==place)
        return true;
    }

    return false;
  }
};

template<class Collection>
struct IsAvailable
{
  Collection _collection;

  IsAvailable(const Collection& collection) : _collection(collection)
  {}

  template<class Object>
  inline bool operator() (Object object) const
  {
    if(std::find(this->_collection.begin(),
                 this->_collection.end(),
                 object)!=this->_collection.end())
      return true;

    return false;
  }
};

template<class ObjectType, typename Collection> inline
bool isPresent(Collection& set, ObjectType obj)
{
  if(std::find(set.begin(), set.end(), obj)!=set.end())
    return true;

  return false;
}

template<class FirstType, class SecondType, typename Collection>
inline bool isPresent(Collection& set, FirstType obj)
{
  typename Collection::iterator coll_it;
  for(coll_it=set.begin(); coll_it!=set.end(); coll_it++)
    if(coll_it->first==obj)
      return true;

  return false;
}

template<class FirstType, class SecondType, typename Collection>
inline bool isPresent(Collection& set, SecondType obj)
{
  typename Collection::const_iterator coll_it;
  for(coll_it=set.begin(); coll_it!=set.end(); coll_it++)
    if((*coll_it).second==obj)
      return true;

  return false;
}

/*!
Operation returns the same parent of \a left and \a right
*/
template<class ParentType>
inline ParentType const* commonParent(ParentType const* left, ParentType const* right)
{
  while(left)
  {
    ParentType const* tempRight=right;
    while(tempRight)
    {
      if(left==tempRight)
        return left;

      tempRight=tempRight->getParent();
    }

    left=left->getParent();
  }

  return 0;
}

template<class ParentType, typename Collection>
inline ParentType const* commonParent(const Collection& parentCollection)
{
  ParentType const* sameParent=0;

  bool started=false;
  typename Collection::const_iterator coll_it;
  for(coll_it=parentCollection.begin(); coll_it!=parentCollection.end(); ++coll_it)
  {
    ParentType const* currParent=*coll_it;

    if(!started)
    {
      sameParent=currParent;
      started=true;
      continue;
    }

    sameParent=commonParent<ParentType>(sameParent, currParent);
  }

  return sameParent;
}

template<typename pointerType>
struct pLess
{
  bool operator() (pointerType const* lhs, pointerType const* rhs) const
  {
    return *lhs<*rhs;
  }

  bool operator() (pointerType* lhs, pointerType* rhs) const
  {
    return *lhs<*rhs;
  }
};

/*!
Functor compares two pointer-objects (\a lhs and \a rhs) whether the
depth of \a lhs is smaller than the depth	of \a rhs.
*/
template<typename pointerType>
struct pLessDepth
{
  bool operator()(pointerType const* lhs, pointerType const* rhs) const
  {
    return lhs->getDepth() < rhs->getDepth();
  }

  bool operator()(pointerType* lhs, pointerType* rhs) const
  {
    return lhs->getDepth() < rhs->getDepth();
  }
};

template<typename pointerType>
struct deleteFunc
{
  void operator() (pointerType* pointer)
  {
    delete pointer;
  }
};

/*!
 * simple cast function based on simple_cast
 */
template <class Target, class Source>
inline Target simple_cast(Source* x)
{
  Q_ASSERT( dynamic_cast<Target>(x) == x );  // detect logic error
  return static_cast<Target>(x);
}

class AddPtrString
{
  QString* _ptrString;

public:
  AddPtrString(QString* ptrString)
    : _ptrString(ptrString)
  {}

public:
  AddPtrString& operator <<(const QString& addString)
  {
    if(this->_ptrString)
      *this->_ptrString += addString;

    return *this;
  }

public:
  template<typename NumberType>
  AddPtrString& operator <<(const NumberType number)
  {
    if(this->_ptrString)
      *this->_ptrString += QString(QStringLiteral("%1")).arg(number);

    return *this;
  }
};

struct CalcPosInLine
{
public:
  QPair<std::size_t, int> operator () (const QString& text)
  {
    std::size_t line = 1;
    int posInLine = 0;

    QChar prevChar;
    for(const QChar& curChar : text)
    {
      if (curChar == QChar::LineFeed)
      {
        if(prevChar!=QChar::CarriageReturn)
        {
          ++line;
          posInLine = 0;
        }
      }
      else if(curChar == QChar::CarriageReturn)
      {
        ++line;
        posInLine = 0;
      }
      else if(curChar == QChar::LineSeparator)
      {
        ++line;
        posInLine = 0;
      }
      else if(curChar == QChar::ParagraphSeparator)
      {
        ++line;
        posInLine = 0;
      }
      else
      {
        ++posInLine;
      }
      prevChar=curChar;
    }

    return qMakePair(line, posInLine);
  }
};
}///end namespace utils
