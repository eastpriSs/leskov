#pragma once
#include "CharStream.h"

enum lexType {ARROW_RIGHT, NUMBER, PLUS, L_EOF};

struct Lexer
{
    struct CharStream* _inputStream;
    char currentLexemBuffer[128];
};

void init_Lexer(struct Lexer*, struct CharStream*);
enum lexType nextLexem(struct Lexer*);