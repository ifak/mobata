grammar DiagnosisDecl;
import CommonDecl;

/*Responsible: rus*/

diagnosisDecl
   : importPathDecl rulesDecl
   ;

rulesDecl
   : ruleDecl rulesDecl
   |
   ;

ruleDecl
   : RuleID LBRACE ruleBody RBRACE
   ;

ruleBody
   : nameDecl
     descriptionDecl
     enabledDecl
     (DeclarationID LBRACE declarations RBRACE|)
     sequenceDecl
   ;

descriptionDecl
   : DescriptionID COLON STRING SEMI
   ;

declarations
   : attributeDecl declarations
   | diagnosisSignalDecl declarations
   | aliasDef declarations
   | componentDecl declarations
   |
   ;

componentsDecl
   : ComponentsID LBRACE componentsBody RBRACE
   ;

componentsBody
   : componentDecl componentsBody
   |
   ;

componentDecl
   : ComponentID LBRACE nameDecl componentBody RBRACE
   ;

componentBody
   : aliasDef componentBody
   | baseTypeDecl componentBody
   | checkDecl componentBody
   |
   ;

diagnosisSignalsDecl
   : SignalsID LBRACE diagnosisSignalsBody RBRACE
   ;

diagnosisSignalsBody
   : diagnosisSignalDecl diagnosisSignalsBody
   |
   ;

diagnosisSignalDecl
   : SignalID LBRACE nameDecl diagnosisSignalBody RBRACE
   ;

diagnosisSignalBody
   : aliasDef diagnosisSignalBody
   | baseTypeDecl diagnosisSignalBody
   | checkDecl diagnosisSignalBody
   |
   ;

baseTypeDecl
   : BaseTypeID COLON idPath SEMI
   ;

checkDecl
   : ConditionID COLON necExp = expression SEMI
   | CheckID COLON suffExp = expression SEMI
   ;

aliasDef
   : UseID (idPath|INT) AsID contextID SEMI
   ;

sequenceDecl
   : SequenceID LBRACE sequenceBody RBRACE
   ;

sequenceBody
   : messageDecl sequenceBody
   | loopDecl sequenceBody
   | parallelDecl sequenceBody
   |
   ;

messageDecl
   : MessageID idPath LPAREN expression RPAREN SEMI
   ;

expression
   : LPAREN expression RPAREN expressionOptional
   | NotIdSymbol expression
   | NotIdWord expression
   | atom expressionOptional
   ;

expressionOptional
   : (OrIdSymbol
      | OrIdWord
      | AndIdSymbol
      | AndIdWord
      | (ASSIGN ASSIGN)
      | (NotIdSymbol ASSIGN)
      | NotIdWord
      | (LESSTHAN (ASSIGN|))
      | (GREATERTHAN (ASSIGN|))
     ) expression
   |
   ;

atom
   : idPath (LPAREN RPAREN|)
   | ( REAL | STRING | INT | TrueID | FalseID)
   | FromID
   | ToID
   ;

loopDecl
   : LoopID LBRACKET INT RBRACKET LBRACE sequenceBody RBRACE
   ;

parallelDecl
   : ParallelID LBRACE parallelBodys RBRACE
   ;

parallelBodys
   : parallelBody parallelBodys
   |
   ;

parallelBody
   : ParallelSequenceID LBRACE sequenceBody RBRACE
   ;

enabledDecl
   : EnabledID COLON (TrueID | FalseID) SEMI
   ;

ComponentsID
   : 'Components'
   ;

RuleID
   : 'Rule'
   ;

ComponentID
   : 'Component'
   ;

BaseTypeID
   : 'basetype'
   ;

ParallelSequenceID
   : 'ParallelSequence'
   ;

SignalsID
   : 'Signals'
   ;

ParallelID
   : 'Parallel'
   ;

LoopID
   : 'Loop'
   ;

SequenceID
   : 'Sequence'
   ;

DescriptionID
   : 'description'
   ;

MessageID
   : 'Message'
   ;

UseID
   : 'use'
   ;

ConditionID
   : 'Condition'
   ;

CheckID
   : 'Check'
   ;


DiagnosisID
   : 'Diagnosis'
   ;
