
// file: timespec.c

#include "timespec.h"

t_timespec timespec_init(clockid_t clockid)
{
  t_timespec ts = { 0 };

  if (clock_gettime(clockid, &ts) == -1)
    perror("timespec_get: clock_gettime failed");

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

  if (a->tv_sec > b->tv_sec)   return  1;
  if (a->tv_sec < b->tv_sec)   return -1;
  if (a->tv_nsec > b->tv_nsec) return  1;
  if (a->tv_nsec < b->tv_nsec) return -1;
                               return  0;
}

t_timespec *timespec_add(
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

  return a;
}

t_timespec *timespec_sub(
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

  return a;
}

