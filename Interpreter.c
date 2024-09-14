#include "Interpreter.h"
#include <stdio.h>
#include <stdlib.h>

void init_Interpreter(struct Interpreter* this, struct Parser* p)
{
    this->_storageOfGlobalNumber = 0;
    this->_prs = p;
}

void _interpret_OUT(struct Interpreter* this)
{
    printf("\n%d", this->_storageOfGlobalNumber);
}

void _interpret_PLUS_ONE(struct Interpreter* this)
{
    this->_storageOfGlobalNumber += 1;
}


void _interpret_LOOP(struct Interpreter* this, enum statementType *list)
{
    int times = atoi(this->_prs->_lxr->currentLexemBuffer);
    switch (*list)
    {
    case STMNT_OUT: for (int i = 0; i < times; ++i) _interpret_OUT(this);
        break;
    
    case STMNT_PLUS_ONE: for (int i = 0; i < times; ++i) _interpret_PLUS_ONE(this);
        break;
    }
}

void interpret(struct Interpreter* this)
{
    enum statementType *listStatements = parse(this->_prs);
    while (*listStatements != END_INPUT)
    {
        while (*listStatements != NULL_STATEMENT_TYPE)
        {
            switch (*listStatements)
            {
            case STMNT_NUMBER:
                ++listStatements;
                _interpret_LOOP(this, listStatements);
                break;
            
            case STMNT_OUT:
                _interpret_OUT(this);
                break;
            
            case STMNT_PLUS_ONE:
                _interpret_PLUS_ONE(this);
                break;

            default:
                break;
            }
            ++listStatements;
        }
        listStatements = parse(this->_prs);
    }
    
}