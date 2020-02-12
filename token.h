#ifndef __TOKEN_H__
#define __TOKEN_H__

typedef struct
{
  int type;
  int intvalue;
} Token;

enum Tokens
{
  INVALID,
  PLUS,
  MINUS,
  STAR,
  SLASH,
  EQUALS,
  COLON,
  SEMICOLON,
  INTLIT
};

const char *tokenname(const int token);

#endif
