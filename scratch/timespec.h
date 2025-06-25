
// file: timespec.h

#pragma once

#include <assert.h>
#include <stdio.h>
#include <time.h>
#include "config.h" // NSEC_PER_SEC

typedef struct timespec t_timespec;

t_timespec timespec_init(clockid_t clockid);

t_timespec timespec_sum(
  const t_timespec *a,
  const t_timespec *b
) __attribute__((nonnull(1, 2)));

t_timespec timespec_diff(
  const t_timespec *a,
  const t_timespec *b
) __attribute__((nonnull(1, 2)));

int timespec_cmp(
  const t_timespec *a,
  const t_timespec *b
) __attribute__((nonnull(1, 2)));

t_timespec *timespec_add(
  t_timespec *a,
  const t_timespec *b
) __attribute__((nonnull(1, 2)));

t_timespec *timespec_sub(
  t_timespec *a,
  const t_timespec *b
) __attribute__((nonnull(1, 2)));

