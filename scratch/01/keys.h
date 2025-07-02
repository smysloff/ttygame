
// file: keys.h

#pragma once

#include <ctype.h>
#include <time.h>
#include <unistd.h>

#include "timespec.h"

typedef struct keys
{
  struct timespec time;
  struct timespec duration;
  char sequence[8];
  char value;
} t_keys;

void init_keys(const struct timespec *timestamp);

void update_keys(const struct timespec *timestamp);

const t_keys *get_keys(void);

