#include "scan.h"
#include "character.h"
#include "string.h"

int scanint(int character, ScanState *state)
{
  int k;
  int val = 0;

  while ((k = charpos("0123456789", character)) >= 0)
    {
      val = val * 10 + k;
      character = next(state);
    }
  // No digit char, put it back
  putback(state, character);
  return val;
}

int scantoken(ScanState *state)
{
  int character = skipwhite(state);

  switch (character)
    {
    case EOF:
      return EOF;

    case '+':
      state->token.type = PLUS;
      break;

    case '-':
      state->token.type = MINUS;
      break;

    case '*':
      state->token.type = STAR;
      break;

    case '/':
      state->token.type = SLASH;
      break;

    case '=':
      state->token.type = EQUALS;
      break;

    case ':':
      state->token.type = COLON;
      break;

    case ';':
      state->token.type = SEMICOLON;
      break;

    default:
      if (isdigit(character)) {
        state->token.intvalue = scanint(character, state);
        state->token.type = INTLIT;
        break;
      } else {
        state->token.type = INVALID;
      }
    }
  return state->token.type;
}


ScanState newstate(FILE *file)
{
  ScanState state = {
    .line = 0,
    .putback = False,
    .file = file,
      .token = {.type= INVALID}
  };
  return state;
}
