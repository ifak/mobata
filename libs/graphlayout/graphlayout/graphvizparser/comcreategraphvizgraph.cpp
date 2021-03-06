#include "comcreategraphvizgraph.hpp"



#include <mobata/utils/functors.hpp>

#undef emit
#undef SIGNAL

#include <antlr4-runtime.h>

#include "DOTLexer.h"
#include "DOTParser.h"
#include "dotmodellistener.h"
#include <QDebug>

#include <mobata/memory_leak_start.hpp>

using namespace antlr4;

namespace graphvizparser {

class ComCreateGraphvizGraph::Private
{
  friend class ComCreateGraphvizGraph;

  std::string     _graphvizOutputText;
  graphlayout::LayoutGraph*  _layoutGraph;

  Private(const std::string& graphvizOutputText,
          graphlayout::LayoutGraph* layoutGraph)
    : _graphvizOutputText(graphvizOutputText),
      _layoutGraph(layoutGraph)
  {}
};

ComCreateGraphvizGraph::ComCreateGraphvizGraph(const std::string& graphvizOutputText,
                                               graphlayout::LayoutGraph* layoutGraph,
                                               QObject* parent)
  : QObject(parent), _d(new Private(graphvizOutputText, layoutGraph))
{
  Q_ASSERT(this->_d->_layoutGraph);
}

ComCreateGraphvizGraph::~ComCreateGraphvizGraph()
{
  delete this->_d;
}

bool ComCreateGraphvizGraph::execute(QString* errorString)
{
  try
  {

    ANTLRInputStream input(this->_d->_graphvizOutputText);
    //DOTListener* listener = new DOTListener();
    DotModelListener listener;
    listener.setGraph(this->_d->_layoutGraph);
    DOTLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    DOTParser parser(&tokens);
    parser.setBuildParseTree(true);
    parser.setErrorHandler(std::make_shared<DefaultErrorStrategy>());
    parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::LL);

    tokens.fill();
    DOTParser::GraphContext* commonDeclCtx = parser.graph();

    if(commonDeclCtx)
    {
      antlr4::tree::ParseTreeWalker walker;
      walker.walk(&listener, commonDeclCtx);
    }


/*
    parser.setGraphvizGraph(this->_d->_layoutGraph);
    parser.setBuildParseTree(false);
    parser.setErrorHandler(std::make_shared<DefaultErrorStrategy>());
    parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::LL);

    parser.DOT();
*/

    //qDebug()<<"debug1"<<parser.graph()->getRuleContext;

//    if (parser.getNumberOfSyntaxErrors() > 0
//        || lexer.getNumberOfSyntaxErrors() > 0)
//    {
//      utils::AddPtrString(errorString)<< "Errors encountered: "
//                                      << parser.getNumberOfSyntaxErrors()
//                                         + lexer.getNumberOfSyntaxErrors();
//      return false;
//    }
  }
  catch (RecognitionException& re)
  {
    utils::AddPtrString(errorString)<<"RecognitionException: "<<re.what();
    return false;
  }
  catch (ParseCancellationException &pce)
  {
    utils::AddPtrString(errorString)<<"ParseCancellationException: "<<pce.what();
    return false;
  }
  catch (std::exception& exc)
  {
    utils::AddPtrString(errorString)<<"std::exception: "<<exc.what();
    return false;
  }
  catch(...)
  {
    utils::AddPtrString(errorString)<<"Unknown error during graphviz output parsing!";
    return false;
  }

  return true;
}

} // namespace graphvizparser
