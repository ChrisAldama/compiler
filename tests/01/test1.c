#include <token.h>
#include <scan.h>
#include <stdio.h>
#include <munit/munit.h>

int main()
{
  const int tokens[] = {INTLIT, PLUS, INTLIT, SLASH, INTLIT, EQUALS, INTLIT};
  const int values[] = {12312, 123, 23, 0};
  int token_idx = 0;
  int value_idx = 0;

  FILE *file = fopen("input", "r");
  if (!file) return 1;
  ScanState state = newstate(file);
  while(scantoken(&state) != EOF) {
    munit_assert_int(state.token.type, ==, tokens[token_idx++]);
    if(state.token.type == INTLIT) {
      munit_assert_int(state.token.intvalue, ==, values[value_idx++]);
    }
  }
  fclose(file);
  return 0;
}
