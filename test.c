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
  plan ( count * 2 + 2 );

  for ( int i = 0 ; i < count ; i++ ) {
    char lhs[MAXLEN], rhs[MAXLEN], description[MAXLEN];
    strcpy ( lhs, cases[2*i  ] );
    strcpy ( rhs, cases[2*i+1] );
    sprintf ( description, "'%s' < '%s'", lhs, rhs );

    cmp_ok ( tail_lt ( lhs, rhs ), "==", true, description );
  }

  for ( int i = 0 ; i < count ; i++ ) {
    char lhs[MAXLEN], rhs[MAXLEN], description[MAXLEN];
    strcpy ( lhs, cases[2*i  ] );
    strcpy ( rhs, cases[2*i+1] );
    sprintf ( description, "'%s' > '%s'", rhs, lhs );

    cmp_ok ( tail_gt ( rhs, lhs ), "==", true, description );
  }

  cmp_ok ( tail_eq ( "",    ""    ), "==", true, "'' == ''" );
  cmp_ok ( tail_eq ( "foo", "foo" ), "==", true, "'foo' == 'foo'" );

  done_testing ();
}
