#include <stdio.h>
#include "CharStream.h"

void init_CharStream(struct CharStream *cs, char *filename)
{
    cs->current = cs->_buffer;
    cs->forward = cs->_buffer + 1;
    cs->end     = cs->_buffer;

    FILE* f = fopen(filename, "r");
    char symbol = '\0';
    if(f != NULL) {
        while((symbol = getc(f)) != EOF) {
            *cs->end = symbol;
            ++cs->end; 
        }
        *cs->end = '\0';
        fclose(f);
    } else {
        // exception
    }
}