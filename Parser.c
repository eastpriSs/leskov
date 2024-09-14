#include <stdlib.h>
#include "Parser.h"

void init_Parser(struct Parser* this, struct Lexer* lxr)
{
    this->_lxr = lxr;
}

enum statementType* N(struct Lexer* lxr)
{
    enum statementType *rbegin = (enum statementType*)(malloc(sizeof(enum statementType*) * 3));
    enum statementType *rforward = rbegin;
    *rforward = STMNT_NUMBER;
    ++rforward;
    switch (nextLexem(lxr))
    {
    case PLUS: *rforward = *P();
        break;
    
    case ARROW_RIGHT: *rforward = *O();
        break;
    
    default : *rbegin = END_INPUT;
    }
    ++rforward;
    *rforward = NULL_STATEMENT_TYPE;
    return rbegin;
}
enum statementType* P()
{
    enum statementType *rbegin = (enum statementType*)(malloc(sizeof(enum statementType*) * 2));
    enum statementType *rforward = rbegin;
    *rforward = STMNT_PLUS_ONE;
    ++rforward;
    *rforward = NULL_STATEMENT_TYPE;
    return rbegin;
}
enum statementType* O()
{
    enum statementType *rbegin = (enum statementType*)(malloc(sizeof(enum statementType*) * 2));
    enum statementType *rforward = rbegin;
    *rforward = STMNT_OUT;
    ++rforward;
    *rforward = NULL_STATEMENT_TYPE;
    return rbegin;
}
enum statementType* E()
{
    enum statementType *rbegin = (enum statementType*)(malloc(sizeof(enum statementType*) * 2));
    enum statementType *rforward = rbegin;
    *rforward = END_INPUT;
    ++rforward;
    *rforward = NULL_STATEMENT_TYPE;
    return rbegin;
}

/*
--------------------
Recursion grammar 
--------------------
S -> NPOE
N -> P | O
P -> '+'
O -> '>'
E -> '\0'
--------------------
*/
enum statementType* parse(struct Parser* this)
{
    switch (nextLexem(this->_lxr))
    {
    case NUMBER: return N(this->_lxr);
    case PLUS: return P();
    case ARROW_RIGHT: return O();
    case L_EOF: return E();
    }
}