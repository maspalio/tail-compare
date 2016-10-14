// clang -o tail_compare tail_compare.c -I../libtap/ ../libtap/libtap.a -O0 -Wall

#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#include "tail_compare.h"

#include <tap.h>

int main () {
  plan ( 7 );

  cmp_ok ( tail_lt ( "alpha",      "alpha.1"    ), "==", true );
  cmp_ok ( tail_lt ( "alpha.1",    "alpha.beta" ), "==", true );
  cmp_ok ( tail_lt ( "alpha.beta", "beta"       ), "==", true );
  cmp_ok ( tail_lt ( "beta",       "beta.2"     ), "==", true );
  cmp_ok ( tail_lt ( "beta.2",     "beta.11"    ), "==", true );
  cmp_ok ( tail_lt ( "beta.11",    "rc.1"       ), "==", true );
  cmp_ok ( tail_lt ( "rc.1",       ""           ), "==", true );

  done_testing ();
}

bool tail_lt ( char* lhs, char* rhs ) {
  return true;
}
