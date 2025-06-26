
// file: fps_test.c

#include <stdio.h>
#include "fps.h"

#define FRAME_RATE 4

int main(void)
{
  t_fps fps = fps_create(FRAME_RATE);
  printf("%ld %ld\n", fps.curr.tv_sec, fps.curr.tv_nsec);
  printf("%ld %ld\n", fps.value, fps.count);
  printf("-----\n");

  t_timespec sleep_duration = {
    .tv_sec = 0,
    .tv_nsec = 100'000'000L,
  };

  while (fps.value == 0)
  {
    clock_nanosleep(CLOCK_MONOTONIC, 0, &sleep_duration, NULL);
    fps_update(&fps);
    printf("%ld %ld\n", fps.curr.tv_sec, fps.curr.tv_nsec);
    printf("%ld %ld\n", fps.value, fps.count);
    printf("-----\n");
  }
}
