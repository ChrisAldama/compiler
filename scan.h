#ifndef __SCAN_H__
#define __SCAN_H__

#include <stdio.h>
#include "token.h"
#include "logic.h"

typedef struct
{
  int line;
  int  putback;
  FILE *file;
  Token token;
} ScanState;

int scanint(int character, ScanState *state);
int scantoken(ScanState *state);
ScanState newstate(FILE *file);


#endif
