
// file: timespec.h

#pragma once

#include <time.h>

#include "constants.h"

void timespec_gettime(struct timespec *ts);

struct timespec timespec_diff(
  struct timespec *ts1,
  struct timespec *ts2
);

