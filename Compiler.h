#pragma once
#include "CharStream.h"
#include "Lexer.h"
#include "Parser.h"
#include "Interpreter.h"

struct Compiler
{
    struct CharStream* _cs;
    struct Lexer* _lxr;
    struct Parser* _prs;
    struct Interpreter* _intr;
};

void init_Compiler(struct Compiler*, char *filename);
void compile(struct Compiler*);