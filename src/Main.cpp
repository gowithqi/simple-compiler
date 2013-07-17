#include <cassert>
#include <iostream>

#include "Token.h"

int main(int argc, char *argv[])
{
    // Token test
    Token token(TOKEN_EOF, 1, 1, "test.c");
    assert(token == TOKEN_EOF);
    assert(token != TOKEN_INT);
    token.Print();

    return 0;
}

