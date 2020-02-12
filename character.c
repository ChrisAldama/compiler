#include "logic.h"
#include "scan.h"
#include "string.h"

int next(ScanState *state)
{
  if (state->putback) {
    int character = state->putback;
    state->putback = False;
    return character;
  }

  int character = fgetc(state->file);
  if (character == '\n') {
    state->line++;
  }
  return character;
}

void putback(ScanState *state, int character)
{
  state->putback = character;
}

bool iswhite(int character)
{
  return (character == ' ' ||
    character == '\t' ||
    character == '\r' ||
    character == '\n' ||
    character == '\f');
}

bool isdigit(int character)
{
  return (character >= '0' && character <= '9');
}

int skipwhite(ScanState *state)
{
  int character = next(state);
  while(iswhite(character)) {
    character = next(state);
  }
  return character;
}


int charpos(const char *array, const int c)
{
  const int len = strlen(array);
  for(int i = 0; i < len; i++) {
    if(c == array[i]) {
      return i;
    }
  }
  return -1;
}
