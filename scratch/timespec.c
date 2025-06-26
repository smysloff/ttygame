
// file: timespec.c

#include "timespec.h"

bool timespec_init(t_timespec *ts, clockid_t clockid)
{
  if (clock_gettime(clockid, ts) == -1)
  {
    return false;
    perror("timespec_init: clock_gettime failed");
  }

  return true;
}

t_timespec timespec_create(clockid_t clockid)
{
  t_timespec ts = { 0 };

  if (clock_gettime(clockid, &ts) == -1)
    perror("timespec_create: clock_gettime failed");

  return ts;
}

t_timespec timespec_sum(
  const t_timespec *a,
  const t_timespec *b
) {
  assert(a != NULL
      && b != NULL
      && "timespec_sum args can't be NULL");

  t_timespec ts = { 0 };

  ts.tv_sec = a->tv_sec + b->tv_sec;
  ts.tv_nsec = a->tv_nsec + b->tv_nsec;

  while (ts.tv_nsec >= NSEC_PER_SEC)
  {
    ++ts.tv_sec;
    ts.tv_nsec -= NSEC_PER_SEC;
  }

  return ts;
}

t_timespec timespec_diff(
  const t_timespec *a,
  const t_timespec *b
) {
  assert(a != NULL
      && b != NULL
      && "timespec_diff args can't be NULL");

  t_timespec ts = { 0 };

  ts.tv_sec = a->tv_sec - b->tv_sec;
  ts.tv_nsec = a->tv_nsec - b->tv_nsec;

  while (ts.tv_nsec < 0)
  {
    --ts.tv_sec;
    ts.tv_nsec += NSEC_PER_SEC;
  }

  return ts;
}

int timespec_cmp(
  const t_timespec *a,
  const t_timespec *b
) {
  assert(a != NULL
      && b != NULL
      && "timespec_cmp args can't be NULL");

  if (a->tv_sec > b->tv_sec)   return GREATER;
  if (a->tv_sec < b->tv_sec)   return LESS;
  if (a->tv_nsec > b->tv_nsec) return GREATER;
  if (a->tv_nsec < b->tv_nsec) return LESS;
                               return EQUAL;
}

void timespec_add(
  t_timespec *a,
  const t_timespec *b
) {
  assert(a != NULL
      && b != NULL
      && "timespec_add args can't be NULL");

  a->tv_sec += b->tv_sec;
  a->tv_nsec += b->tv_nsec;

  while (a->tv_nsec >= NSEC_PER_SEC)
  {
    ++a->tv_sec;
    a->tv_nsec -= NSEC_PER_SEC;
  }
}

void timespec_sub(
  t_timespec *a,
  const t_timespec *b
) {
  assert(a != NULL
      && b != NULL
      && "timespec_sub args can't be NULL");

  a->tv_sec -= b->tv_sec;
  a->tv_nsec -= b->tv_nsec;

  while (a->tv_nsec < 0)
  {
    --a->tv_sec;
    a->tv_nsec += NSEC_PER_SEC;
  }
}

