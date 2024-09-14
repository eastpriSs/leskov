#include <ctype.h>
#include "Lexer.h"


#define SPACE ' '
#define ENTER '\n'
#define S_EOF '\0'


void init_Lexer(struct Lexer* l, struct CharStream* cs)
{
    l->_inputStream = cs;
}

enum lexType nextLexem(struct Lexer *l)
{
    while (*l->_inputStream->current == SPACE || *l->_inputStream->current == ENTER)
    {  
        ++l->_inputStream->current;
    }
    l->_inputStream->forward = l->_inputStream->current + 1;   
 
    // NUMBER
    if (isdigit(*l->_inputStream->current))
    {
        while (isdigit(*l->_inputStream->forward))
        {
            ++l->_inputStream->forward;
        }
        char *fillPtr = l->currentLexemBuffer; 
        while (l->_inputStream->current != l->_inputStream->forward)
        {
            *fillPtr = *l->_inputStream->current;
            ++l->_inputStream->current;
            ++fillPtr;
        }
        *fillPtr = '\0';
        ++l->_inputStream->forward;
        return NUMBER;
    }        
    // KEYWORDS
    char *curChar = l->_inputStream->current;
    ++l->_inputStream->current;
    switch (*curChar)
    {
    case '+': return PLUS;
    case '>': return ARROW_RIGHT;
    case S_EOF: return L_EOF;
    default: return L_EOF;
    }
}