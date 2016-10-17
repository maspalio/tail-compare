#include "tail_compare.h"

#include <tap.h>

int main () {
  plan ( 7 );

  cmp_ok ( tail_lt ( "alpha",      "alpha.1"    ), "==", true, "alpha < alpha.1"      );
  cmp_ok ( tail_lt ( "alpha.1",    "alpha.beta" ), "==", true, "alpha.1 < alpha.beta" );
  cmp_ok ( tail_lt ( "alpha.beta", "beta"       ), "==", true, "alpha.beta < beta"    );
  cmp_ok ( tail_lt ( "beta",       "beta.2"     ), "==", true, "beta < beta.2"        );
  cmp_ok ( tail_lt ( "beta.2",     "beta.11"    ), "==", true, "beta.2 < beta.11"     );
  cmp_ok ( tail_lt ( "beta.11",    "rc.1"       ), "==", true, "beta.11 < rc.1"       );
  cmp_ok ( tail_lt ( "rc.1",       ""           ), "==", true, "rc.1 < {empty}"       );

  done_testing ();
}
