
// file: timespec.c

#include "timespec.h"

void timespec_gettime(struct timespec *ts)
{
  assert(ts != NULL);
  clock_gettime(CLOCK_MONOTONIC, ts);
}

Comparison_Result timespec_cmp(
  const struct timespec *ts1,
  const struct timespec *ts2
) {
  assert(ts1 != NULL && ts2 != NULL);
  assert(ts1->tv_nsec >= 0 && ts1->tv_nsec < NANSEC_IN_SEC);
  assert(ts2->tv_nsec >= 0 && ts2->tv_nsec < NANSEC_IN_SEC);

  if (ts1->tv_sec  > ts2->tv_sec)  return GREATER;
  if (ts1->tv_sec  < ts2->tv_sec)  return LESS;
  if (ts1->tv_nsec > ts2->tv_nsec) return GREATER;
  if (ts1->tv_nsec < ts2->tv_nsec) return LESS;
  return EQUAL;
}

struct timespec timespec_sum(
  const struct timespec *ts1,
  const struct timespec *ts2
) {
  assert(ts1 != NULL && ts2 != NULL);

  struct timespec result = {0};

  result.tv_sec  = ts1->tv_sec  + ts2->tv_sec;
  result.tv_nsec = ts1->tv_nsec + ts2->tv_nsec;

  while (result.tv_nsec >= NANSEC_IN_SEC)
  {
    ++result.tv_sec;
    result.tv_nsec -= NANSEC_IN_SEC;
  }

  return result;
}

struct timespec timespec_diff(
  const struct timespec *ts1,
  const struct timespec *ts2
) {
  assert(ts1 != NULL && ts2 != NULL);

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

void timespec_add(
        struct timespec *ts1,
  const struct timespec *ts2
) {
  assert(ts1 != NULL && ts2 != NULL);

  ts1->tv_sec  += ts2->tv_sec;
  ts1->tv_nsec += ts2->tv_nsec;

  while (ts1->tv_nsec >= NANSEC_IN_SEC)
  {
    ++ts1->tv_sec;
    ts1->tv_nsec -= NANSEC_IN_SEC;
  }
}

void timespec_sub(
        struct timespec *ts1,
  const struct timespec *ts2
) {
  assert(ts1 != NULL && ts2 != NULL);

  ts1->tv_sec  -= ts2->tv_sec;
  ts1->tv_nsec -= ts2->tv_nsec;

  while (ts1->tv_nsec < 0)
  {
    --ts1->tv_sec;
    ts1->tv_nsec += NANSEC_IN_SEC;
  }
}

