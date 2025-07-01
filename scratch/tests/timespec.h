
// file: timespec.h

#pragma once

#include <assert.h>
#include <time.h>

#include "constants.h"

void timespec_gettime(struct timespec *ts);

struct timespec timespec_sum(
  const struct timespec *ts1,
  const struct timespec *ts2
);

struct timespec timespec_diff(
  const struct timespec *ts1,
  const struct timespec *ts2
);

void timespec_add(
        struct timespec *ts1,
  const struct timespec *ts2
);

void timespec_sub(
        struct timespec *ts1,
  const struct timespec *ts2
);

