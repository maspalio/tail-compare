#include "tail_compare.h"

bool tail_lt ( char *lhs, char *rhs ) {
  printf ( "lhs: %s\n", lhs );
  // printf ( "rhs: %s\n", rhs );

  char xlhs[256], xrhs[256];
  strcpy ( xlhs, lhs );
  strcpy ( xrhs, rhs );

  char *dot = ".";
  char *l_token, *l_last, *r_last;

  for ( l_token = strtok_r ( xlhs, dot, &l_last ) ; l_token ; l_token = strtok_r ( NULL, dot, &l_last ) ) {
    printf ( "l_token: %s\n", l_token );
  }

  return true;
}
