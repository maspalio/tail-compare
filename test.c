#include "tail_compare.h"

#include <tap.h>

#define MAXLEN 64

char *cases[] = {
  "alpha",      "alpha.1"
, "alpha.1",    "alpha.beta"
, "alpha.beta", "beta"
, "beta",       "beta.2"
, "beta.2",     "beta.11"
, "beta.11",    "rc.1"
, "rc.1",       ""
};
int count = sizeof ( cases ) / sizeof ( cases[0] ) / 2;

int main () {
  plan ( count * 2 );

  for ( int i = 0 ; i < count ; i++ ) {
    char lhs[MAXLEN], rhs[MAXLEN];
    strcpy ( lhs, cases[2*i  ] );
    strcpy ( rhs, cases[2*i+1] );

    char dlt[MAXLEN], dgt[MAXLEN];
    sprintf ( dlt, "%s < %s", lhs, rhs );
    sprintf ( dgt, "%s > %s", rhs, lhs );

    cmp_ok ( tail_lt ( lhs, rhs ), "==", true, dlt );
    cmp_ok ( tail_gt ( rhs, lhs ), "==", true, dgt );
  }

  done_testing ();
}
