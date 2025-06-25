
// file: test.c

#include <stdio.h>
#include <time.h>
#include "timespec.h"

int main(void)
{
  t_timespec begin = timespec_init(CLOCK_MONOTONIC);
  printf("%ld | %ld\n", begin.tv_sec, begin.tv_nsec);

  t_timespec sleep_duration = { .tv_sec = 1, .tv_nsec = 0 };
  clock_nanosleep(CLOCK_MONOTONIC, 0, &sleep_duration, NULL);

  t_timespec end = timespec_init(CLOCK_MONOTONIC);
  printf("%ld | %ld\n", end.tv_sec, end.tv_nsec);

  t_timespec delta = timespec_diff(&end, &begin);
  printf("%ld | %ld\n", delta.tv_sec, delta.tv_nsec);

  t_timespec result = timespec_sum(&begin, &delta);
  printf("%ld | %ld\n", result.tv_sec, result.tv_nsec);

  printf("%d", timespec_cmp(&begin, &end));
  printf("%d", timespec_cmp(&end, &result));
  printf("%d\n", timespec_cmp(&result, &begin));

  timespec_add(&result, &delta);
  printf("%ld | %ld\n", result.tv_sec, result.tv_nsec);

  timespec_sub(&result, &delta);
  printf("%ld | %ld\n", result.tv_sec, result.tv_nsec);
}
