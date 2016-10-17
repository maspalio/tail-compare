#include "tail_compare.h"

// http://semver.org/#spec-item-11:
// Precedence for two pre-release versions with the same major, minor, and patch version MUST be determined
// by comparing each dot separated identifier from left to right until a difference is found as follows:
// identifiers consisting of only digits are compared numerically and identifiers with letters or hyphens
// are compared lexically in ASCII sort order. Numeric identifiers always have lower precedence than
// non-numeric identifiers. A larger set of pre-release fields has a higher precedence than a smaller set,
// if all of the preceding identifiers are equal.
// Example:
// 1.0.0-alpha < 1.0.0-alpha.1 < 1.0.0-alpha.beta < 1.0.0-beta < 1.0.0-beta.2 < 1.0.0-beta.11 < 1.0.0-rc.1 < 1.0.0.

bool tail_lt ( char *lhs, char *rhs ) {
  char xlhs[256], xrhs[256];
  strcpy ( xlhs, lhs );
  strcpy ( xrhs, rhs );

  char *dot = ".";
  char *l_last, *r_last;

  char *l_token = strtok_r ( xlhs, dot, &l_last );
  char *r_token = strtok_r ( xrhs, dot, &r_last );

  if ( l_token && !r_token ) {
    return true;
  }

  while ( l_token || r_token ) {
    if ( l_token && r_token ) {
      int l_numeric = isdigit ( l_token[0] );
      int r_numeric = isdigit ( r_token[0] );

      if ( l_numeric && r_numeric ) {
        return atoi ( l_token ) < atoi ( r_token );
      }
      else if ( l_numeric ) {
        return true;
      }
      else if ( r_numeric ) {
        return false;
      }
      else {
        int cmp = strcmp ( l_token, r_token );

        if ( cmp ) {
          return cmp;
        }
      }
    }
    else if ( l_token ) {
      return false;
    }
    else {
      return true;
    }

    l_token = strtok_r ( NULL, dot, &l_last );
    r_token = strtok_r ( NULL, dot, &r_last );
  }

  return false;
}
