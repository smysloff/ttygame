
// file: timespec.c

#include "timespec.h"

struct timespec *timespec_add(
  struct timespec *a,
  const struct timespec *b
) {
  if (!a || !b)
  {
    perror("timespec_add args can't be NULL");
    return (struct timespec) { 0 };
  }

  a->tv_sec += b->tv_sec;
  a->tv_nsec += b->tv_nsec;

  if (a->tv_nsec >= NSEC_PER_SEC)
  {
    a->tv_nsec -= NSEC_PER_SEC;
    ++a->tv_sec;
  }

  return a;
}

struct timespec timespec_cmp(
  const struct timespec *a,
  const struct timespec *b
) {
  if (!a || !b)
  {
    perror("timespec_cmp args can't be NULL");
    return (struct timespec) { 0 };
  }

  return a->tv_sec == b->tv_sec
    ? a->tv_nsec - b->tv_nsec
    : a->tv_sec - b->tv_sec;
}

struct timespec timespec_diff(
  const struct timespec *a,
  const struct timespec *b
) {
  if (!a || !b)
  {
    perror("timespec_diff args can't be NULL");
    return (struct timespec) { 0 };
  }

  struct timespec result = (struct timespec) {
    .tv_sec = a->tv_sec - b->tv_sec,
    .tv_nsec = a->tv_nsec - b->tv_nsec,
  };

  if (result.tv_nsec < 0)
  {
    result.tv_nsec += NSEC_PER_SEC;
    --result.tv_sec;
  }

  return result;
}

struct timespec *timespec_sub(
  struct timespec *a,
  const struct timespec *b
) {
  if (!a || !b)
  {
    perror("timespec_sub args can't be NULL");
    return (struct timespec) { 0 };
  }

  a->tv_sec -= b->tv_sec,
  a->tv_nsec -= b->tv_nsec,

  if (a->tv_nsec < 0)
  {
    a->tv_nsec += NSEC_PER_SEC;
    --a->tv_sec;
  }

  return a;
}

struct timespec timespec_sum(
  const struct timespec *a,
  const struct timespec *b
) {
  if (!a || !b)
  {
    perror("timespec_add args can't be NULL");
    return (struct timespec) { 0 };
  }

  struct timespec result = (struct timespec) {
    .tv_sec = a->tv_sec + b->tv_sec,
    .tv_nsec = a->tv_nsec + b->tv_nsec,
  };

  if (result.tv_nsec >= NSEC_PER_SEC)
  {
    result.tv_nsec -= NSEC_PER_SEC;
    ++result.tv_sec;
  }

  return result;
}

