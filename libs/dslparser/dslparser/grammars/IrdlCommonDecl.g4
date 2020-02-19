grammar IrdlCommonDecl;
import Irdl;

/*Responsible: mag*/

irdlCommonDecl
   : (typeDefDecl | attributeDecl | signalDecl | actorDecl | componentDecl)* 
   ;
