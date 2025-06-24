
// file: timespec.h

#pragma once

#include "config.h"

struct timespec timespec_add(  // a += b
  struct timespec *a,
  const struct timespec *b
);

long timespec_cmp(             // a <=> b
  const struct timespec *a,
  const struct timespec *b
);

struct timespec timespec_diff( // a - b
  const struct timespec *a,
  const struct timespec *b
);

struct timespec timespec_sub(  // a -= b
  struct timespec *a,
  const struct timespec *b
);

struct timespec timespec_sum(  // a + b
  const struct timespec *a,
  const struct timespec *b
);

