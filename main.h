#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>

typedef struct fmt
{
  char type[3];
  int width;
  bool left;
  int dp;
  bool base_prefix;
  bool i_plus;
  bool p_plus;
  char leading;
  void (*printer)(void *, struct fmt);
} FMT;

int _printf(const char *format, ...);
FMT *get_specifiers(const char *, int *);

#endif /* MAIN_H */