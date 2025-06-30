
// file: keys.h

#pragma once

#include <time.h>

typedef struct keys
{
  struct timespec time;
  struct timespec duration;
  char sequence[8];
  char pressed;
} t_keys;

