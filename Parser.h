#pragma once
#include "Lexer.h"

enum statementType {STMNT_NUMBER, STMNT_OUT, STMNT_PLUS_ONE, END_INPUT, NULL_STATEMENT_TYPE};

struct Parser
{
    struct Lexer *_lxr;
};

void init_Parser(struct Parser*, struct Lexer*);
enum statementType* N(struct Lexer*);
enum statementType* P();
enum statementType* O();
enum statementType* E();
enum statementType* parse(struct Parser*);
