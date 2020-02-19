grammar Isrdl;
import CommonDecl;

/*Responsible: mre*/

secRequirement:
  SecurityRequirementID LBRACE
   nameDecl
   (attackDescriptionDecl|)
   attackImpactDecl
  RBRACE
  ;

attackDescriptionDecl:
  AttackDescriptionID
  LBRACE
   ( attackVectorDecl |)
   ( attackPrivileges |)
  RBRACE
  ;

attackImpactDecl:
  ImpactID
  LBRACE
   ( confidentialityThreatDecl |)
   ( integrityThreatDecl       |)
   ( availabilityThreatDecl    |)
  RBRACE
  ;

attackVectorDecl:
  SourceID COLON attackVectorEnum SEMI
  ;

attackVectorEnum:
  ( PhysicalID | LocalID | InternetID )
  ;

attackPrivileges:
  PrivilegesID COLON privilegesEnum SEMI
  ;

privilegesEnum:
   ( AdministratorID
   | InstallAllowedID
   | UnInstallAllowedID
   | SaveAllowedID
   | EditAllowedID
   | NoneID
   )
  ((COMMA privilegesEnum ) | )
  ;

confidentialityThreatDecl:
  ConfidentialityThreatID COLON confidentialityEnum SEMI
  ;

confidentialityEnum:
  ( BrokenID | IntactID )
  ;

integrityThreatDecl:
  IntegrityThreatID COLON integrityEnum SEMI
  ;

integrityEnum:
  ( NoDamageID | AffectedID )
  ;

availabilityThreatDecl:
  TimeoutID COLON INT ( MSekID | SekID ) SEMI
  ;

nameDecl
    : NameID COLON ID SEMI
    ;

NoDamageID
  : 'NoDamage'
  ;

AffectedID
  : 'Affected'
  ;

IntegrityThreatID
  : 'integrity'
  ;

BrokenID
  : 'Broken'
  ;

IntactID
  : 'Intact'
  ;

ConfidentialityThreatID
  : 'confidentiality'
  ;

AdministratorID
  : 'Admin'
  ;

InstallAllowedID
  : 'Install'
  ;

UnInstallAllowedID
  : 'UnInstall'
  ;

SaveAllowedID
  : 'Save'
  ;

EditAllowedID
  : 'Edit'
  ;

NoneID
  : 'None'
  ;

PrivilegesID
  : 'privileges'
  ;

ImpactID
  : 'ImpactThreat'
  ;

AttackDescriptionID
  : 'AttackDescription'
  ;

SecurityRequirementID
  : 'SecurityRequirement'
  ;

SourceID
  : 'source'
  ;

PhysicalID
  : 'Physical'
  ;

LocalID
  : 'Local'
  ;

InternetID
  : 'Internet'
  ;

TimeoutID
  : 'timeout'
  ;

MSekID
  : 'ms'
  ;

SekID
  : 's'
  ;

INT
    : MINUS? (ZERO|DIGIT) ALL_DIGIT*
    ;

LBRACE
   : '{'
   ;

RBRACE
   : '}'
   ;

COLON
    : ':'
    ;

SEMI
    : ';'
    ;

COMMA
    : ','
    ;

UNDER
    : '_'
    ;

MINUS
    : '-'
    ;
