#include "token.h"

const char *tokenname(const int token)
{
    switch (token) {
    case PLUS:
        return "+";
    case MINUS:
        return "-";
    case STAR:
        return "*";
    case SLASH:
        return "/";
    case EQUALS:
        return "=";
    case COLON:
        return ":";
    case SEMICOLON:
        return ";";
    case INTLIT:
        return "intlit";
    case INVALID:
    default:
        return "INVALID";
    }
}
