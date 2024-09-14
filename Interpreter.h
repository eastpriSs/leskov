#pragma once
#include "Parser.h"

struct Interpreter
{
    struct Parser *_prs;
    long long int _storageOfGlobalNumber;
};


void init_Interpreter(struct Interpreter*, struct Parser *);
void interpret(struct Interpreter*);
void _interpret_OUT(struct Interpreter*);
void _interpret_PLUS_ONE(struct Interpreter*);
void _interpret_LOOP(struct Interpreter*, enum statementType *);