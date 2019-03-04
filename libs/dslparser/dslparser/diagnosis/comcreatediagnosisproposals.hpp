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
