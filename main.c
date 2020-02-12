#include "token.h"
#include "scan.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
  puts("About to start");
  FILE *file = fopen(argv[1], "r");
  if (!file) return 1;
  ScanState state = newstate(file);
  while(scantoken(&state) != EOF) {
    const char *token = tokenname(state.token.type);
    printf("Token found!!: %s at line: %d\n", token, state.line);
    if(state.token.type == INTLIT) {
        printf("with value: %d\n", state.token.intvalue);
    }
  }
  fclose(file);
  return 0;
}
