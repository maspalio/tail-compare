#include "tail_compare.h"

// http://semver.org/#spec-item-11:
// Precedence for two pre-release versions with the same major, minor, and patch version MUST be determined
// by comparing each dot separated identifier from left to right until a difference is found as follows:
// identifiers consisting of only digits are compared numerically and identifiers with letters or hyphens
// are compared lexically in ASCII sort order. Numeric identifiers always have lower precedence than
// non-numeric identifiers. A larger set of pre-release fields has a higher precedence than a smaller set,
// if all of the preceding identifiers are TAIL_CMP_EQual. Example:
// 1.0.0-alpha < 1.0.0-alpha.1 < 1.0.0-alpha.beta < 1.0.0-beta < 1.0.0-beta.2 < 1.0.0-beta.11 < 1.0.0-rc.1 < 1.0.0.

int tail_cmp ( char *lhs, char *rhs ) {
  if ( !strcmp ( lhs, rhs ) ) return TAIL_CMP_EQ;

  char *dot = ".";
  char *l_last, *r_last;

  char *l_token = strtok_r ( lhs, dot, &l_last );
  char *r_token = strtok_r ( rhs, dot, &r_last );

  if (  l_token && !r_token ) return TAIL_CMP_LT;
  if ( !l_token &&  r_token ) return TAIL_CMP_GT;

  while ( l_token || r_token ) {
    if ( l_token && r_token ) {
      int l_numeric = isdigit ( l_token[0] );
      int r_numeric = isdigit ( r_token[0] );

      if ( l_numeric && r_numeric ) {
        int l_int = atoi ( l_token );
        int r_int = atoi ( r_token );

        if ( l_int < r_int ) return TAIL_CMP_LT;
        if ( l_int > r_int ) return TAIL_CMP_GT;
      }
      else if ( l_numeric ) {
        return TAIL_CMP_LT;
      }
      else if ( r_numeric ) {
        return TAIL_CMP_GT;
      }
      else {
        int cmp = strcmp ( l_token, r_token );

        if ( cmp ) return cmp > 0 ? TAIL_CMP_GT : TAIL_CMP_LT;
      }
    }
    else if ( l_token ) {
      return TAIL_CMP_GT;
    }
    else if ( r_token ) {
      return TAIL_CMP_LT;
    }

    l_token = strtok_r ( NULL, dot, &l_last );
    r_token = strtok_r ( NULL, dot, &r_last );
  }

  return TAIL_CMP_KO;
}

int tail_lt ( char *lhs, char *rhs ) {
  return tail_cmp ( lhs, rhs ) == TAIL_CMP_LT;
}
int tail_eq ( char *lhs, char *rhs ) {
  return tail_cmp ( lhs, rhs ) == TAIL_CMP_EQ;
}
int tail_gt ( char *lhs, char *rhs ) {
  return tail_cmp ( lhs, rhs ) == TAIL_CMP_GT;
}
