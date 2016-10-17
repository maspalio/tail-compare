#include "tail_compare.h"

#include <tap.h>

int plan = 7;
char *cases[] = {
  "alpha",      "alpha.1"
, "alpha.1",    "alpha.beta"
, "alpha.beta", "beta"
, "beta",       "beta.2"
, "beta.2",     "beta.11"
, "beta.11",    "rc.1"
, "rc.1",       ""
};

int main () {
  plan ( plan );

  for ( int i = 0 ; i < plan ; i++ ) {
    char *description;
    sprintf ( description, "%s < %s", cases[2*i], cases[2*i+1] );

    cmp_ok ( tail_lt ( cases[2*i], cases[2*i+1] ), "==", true, description );
  }

  done_testing ();
}
