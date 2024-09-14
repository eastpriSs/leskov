#include "Compiler.h"

#include <stdlib.h>

int main(int argc, char* argv[])
{
    struct Compiler *comp = (struct Compiler*)(malloc(sizeof(struct Compiler)));
    if (argv[1] == NULL) return 1;
    init_Compiler(comp, argv[1]);
    compile(comp);
}


// gcc leskov.c Compiler.c CharStream.c Interpreter.c Lexer.c Parser.c