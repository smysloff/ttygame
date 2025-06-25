
// file: timespec.h

#pragma once

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include "config.h" // NSEC_PER_SEC

typedef struct timespec t_timespec;

bool timespec_init(
  t_timespec *ts,
  clockid_t clockid
);

t_timespec timespec_create(
  clockid_t clockid
);

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

void timespec_add(
  t_timespec *a,
  const t_timespec *b
) __attribute__((nonnull(1, 2)));

void timespec_sub(
  t_timespec *a,
  const t_timespec *b
) __attribute__((nonnull(1, 2)));

