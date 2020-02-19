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

#include "dslparser_types.hpp"

#include <mobata/model/base/attributeitem.hpp>
#include <mobata/model/base/propattributes.hpp>
#include <mobata/model/base/signalitem.hpp>
#include <mobata/model/base/propsignals.hpp>
#include <mobata/model/base/portitem.hpp>
#include <mobata/model/base/propports.hpp>
#include <mobata/utils/functors.hpp>

#include <QList>

#include <antlr4/Token.h>
#include <antlr4/CommonTokenStream.h>
#include <antlr4/Exceptions.h>

namespace dslparser {

template<class ParserClass>
bool isCommonContextID(int token)
{
  return (token == ParserClass::ID
          || token == ParserClass::NameID
          || token == ParserClass::LabelID
          || token == ParserClass::EnabledID
          || token == ParserClass::TypeID
          || token == ParserClass::TriggerID
          || token == ParserClass::AttributeID
          || token == ParserClass::FunctionID
          || token == ParserClass::SignalID
          || token == ParserClass::PortID
          || token == ParserClass::ImportID
          || token == ParserClass::FromID
          || token == ParserClass::ToID
          || token == ParserClass::SendID
          || token == ParserClass::AsID);
}

struct DslProposal
{
  QString proposalText;
  int     proposalType;

  DslProposal(const QString& propText,
              const int propType = UnknownTokenType)
    : proposalText(propText),
      proposalType(propType)
  {}
};

inline
bool operator <(const DslProposal& left, const DslProposal& right)
{
  return left.proposalText < right.proposalText;
}

inline
bool operator ==(const DslProposal& left, const DslProposal& right)
{
  return (left.proposalText == right.proposalText) && (left.proposalType == right.proposalType);
}

typedef QList<DslProposal> DslProposalList;

class CalcRefAttributesProposals
{
  model::base::PropAttributes*  _propAttributes;
  DslProposalList*              _dslProposalList;

public:
  CalcRefAttributesProposals(model::base::PropAttributes* propAttributes,
                             DslProposalList* dslProposalList)
    : _propAttributes(propAttributes),
      _dslProposalList(dslProposalList)
  {}

  void operator()()
  {
    Q_ASSERT(this->_propAttributes);
    Q_ASSERT(this->_dslProposalList);

    for(model::base::AttributeItem const* existAttribute
        : this->_propAttributes->attributes())
      this->_dslProposalList->append(DslProposal(existAttribute->name(),
                                                 Attribute));

    return;
  }
};

class CalcRefSignalsProposals
{
  model::base::PropSignals*  _propSignals;
  DslProposalList*           _dslProposalList;

public:
  CalcRefSignalsProposals(model::base::PropSignals* propSignals,
                          DslProposalList* dslProposalList)
    : _propSignals(propSignals),
      _dslProposalList(dslProposalList)
  {}

  void operator()()
  {
    Q_ASSERT(this->_propSignals);
    Q_ASSERT(this->_dslProposalList);

    for(model::base::SignalItem const* existSignal
        : this->_propSignals->getSignals())
      this->_dslProposalList->append(DslProposal(existSignal->name(),
                                                 RefSignal));

    return;
  }
};

class CalcRefPortsProposals
{
  model::base::PropPorts* _propPorts;
  DslProposalList*        _dslProposalList;

public:
  CalcRefPortsProposals(model::base::PropPorts* propPorts,
                        DslProposalList* dslProposalList)
    : _propPorts(propPorts),
      _dslProposalList(dslProposalList)
  {}

  void operator()()
  {
    Q_ASSERT(this->_propPorts);
    Q_ASSERT(this->_dslProposalList);

    for(model::base::PortItem const* existPort
        : this->_propPorts->ports())
      this->_dslProposalList->append(DslProposal(existPort->name(),
                                                 RefPort));

    return;
  }
};

template<class LexerType>
bool isWithinComment(const QString& docText,
                     antlr4::CommonTokenStream& tokens,
                     QString* errorString)
{
  if(docText.isEmpty())
    return false;

  std::size_t pos = std::size_t(docText.size());
  if(pos<2)
    return  false;

  if(docText.midRef(pos - 2, 2) == QStringLiteral("*/"))
    return false;//end of multi line comment

  try
  {
    tokens.fill();
  } catch (antlr4::IllegalStateException &)
  {
    utils::AddPtrString(errorString)<<"Error: illegal state found, probably unfinished string.";
    return false;
  }

  for (auto token : tokens.getTokens())
  {
    if(token->getChannel() != antlr4::Token::HIDDEN_CHANNEL)
      continue;

    std::size_t tokenType = token->getType();
    if(tokenType == LexerType::LINE_COMMENT
       || tokenType == LexerType::COMMENT)
    {
      if(token->getStartIndex() <= pos
         && pos <= (token->getStopIndex()+1))
        return true;
    }
  }

  return false;
}

}// end namespace dslparser
