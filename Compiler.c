#include <stdlib.h>
#include "Compiler.h"

void init_Compiler(struct Compiler* this, char *filename)
{
    this->_cs = (struct CharStream*)(malloc(sizeof(struct CharStream)));
    this->_lxr = (struct Lexer*)(malloc(sizeof(struct Lexer)));
    this->_prs = (struct Parser*)(malloc(sizeof(struct Parser)));
    this->_intr = (struct Interpreter*)(malloc(sizeof(struct Interpreter)));
    init_CharStream(this->_cs, filename);
    init_Lexer(this->_lxr, this->_cs);
    init_Parser(this->_prs, this->_lxr);
    init_Interpreter(this->_intr, this->_prs);
}

void compile(struct Compiler* this)
{
    interpret(this->_intr);
}