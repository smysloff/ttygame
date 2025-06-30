
// file: timespec.c

#include "timespec.h"

void timespec_gettime(struct timespec *ts)
{
  clock_gettime(CLOCK_MONOTONIC, ts);
}

struct timespec timespec_diff(
  struct timespec *ts1,
  struct timespec *ts2
) {
  struct timespec result = {0};

  result.tv_sec  = ts1->tv_sec  - ts2->tv_sec;
  result.tv_nsec = ts1->tv_nsec - ts2->tv_nsec;

  while (result.tv_nsec < 0)
  {
    --result.tv_sec;
    result.tv_nsec += NANSEC_IN_SEC;
  }

  return result;
}

