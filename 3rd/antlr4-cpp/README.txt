when updating one function in LexerATNSimulator.cpp has to be updated like so:

void LexerATNSimulator::consume(CharStream *input) {
   size_t curChar = input->LA(1);
   if ((curChar == '\n')
       || (curChar == 0x0085)
       || (curChar == 0x2028)
       || (curChar == 0x2029))
   {
     _line++;
     _charPositionInLine = 0;
   } else {
     _charPositionInLine++;
   }
   input->consume();
}
