#pragma once
#define MAX_BUFFER_SIZE 2048

struct CharStream
{
    char _buffer[MAX_BUFFER_SIZE];
    
    char *current;
    char *forward;
    char *end;
};

void init_CharStream(struct CharStream*, char*);