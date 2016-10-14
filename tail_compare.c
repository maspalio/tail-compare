// clang -o tail_compare tail_compare.c -I../libtap/ ../libtap/libtap.a -O0 -Wall

#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#include "tail_compare.h"

#include <tap.h>

int main () {
  plan ( 1 );
  cmp_ok ( tail_compare ( "alpha", "alpha.1" ), "==", false );
  done_testing ();
}

bool tail_compare ( char* lhs, char* rhs ) {
  return false;
}
