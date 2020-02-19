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

#include "../dslparser_global.hpp"
#include "../dslparser_types.hpp"

#include <QObject>



namespace dslparser {
namespace diagnosis{

struct DiagnosisProposal
{
  QString proposalText;
  int     proposalType;

  DiagnosisProposal(const QString& propText,
                   const int propType = UnknownDiagnosisTokenType)
    : proposalText(propText),
      proposalType(propType)
  {}
};

inline
bool operator <(const DiagnosisProposal& left, const DiagnosisProposal& right)
{
  return left.proposalText < right.proposalText;
}

typedef QList<DiagnosisProposal> DiagnosisProposalList;

class DSLPARSERSHARED_EXPORT ComCreateDiagnosisProposals
    : public QObject
{
public:
  explicit ComCreateDiagnosisProposals(const QString& diagnosisDocText,
                                      const QString& praefix = "",
                                      bool strictErrorHandling = true,
                                      QObject* parent = 0);
  virtual ~ComCreateDiagnosisProposals();

public:
  bool                        execute(QString* errorString);
  const DiagnosisProposalList& diagnosisProposals() const;

private:
  Q_DISABLE_COPY(ComCreateDiagnosisProposals)
  class Private;
  Private* _d;
};

}// namespace diagnosis
} // namespace dslparser
