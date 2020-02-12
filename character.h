#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "scan.h"
#include "logic.h"

int next(ScanState *state);
void putback(ScanState *state, int character);
bool iswhite(int character);
bool isdigit(int character);
int skipwhite(ScanState *state);
int charpos(const char *array, const int c);

#endif
