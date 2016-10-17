#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAIL_COMPARE_LT -1
#define TAIL_COMPARE_EQ  0
#define TAIL_COMPARE_GT +1
#define TAIL_COMPARE_KO  9

int tail_cmp ( char* lhs, char* rhs );

int tail_lt  ( char* lhs, char* rhs );
int tail_eq  ( char* lhs, char* rhs );
int tail_gt  ( char* lhs, char* rhs );
