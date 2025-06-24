
// file: fps.c

#include "fps.h"

#define FRAME_RATE 2

t_fps fps_init(long frame_rate)
{
  t_fps fps = { 0 };

  if (clock_gettime(CLOCK_MONOTONIC, &fps.curr) == -1)
    perror("fps_init: clock_gettime");

  fps.duration.tv_nsec = NSEC_PER_SEC / frame_rate;

  return fps;
}

void fps_update(t_fps *fps)
{
  // save previous 'current' time

  fps->prev = fps->curr;


  // get new current time

  if (clock_gettime(CLOCK_MONOTONIC, &fps->curr) == -1)
  {
    perror("fps_update: clock_gettime");
  }


  // add delay to match frame rate
  // and update delta time

  struct timespec duration =
    timespec_diff(&fps->curr, &fps->prev);

  if (timespec_cmp(&duration, &fps->duration) < 0)
  {
    struct timespec delta =
      timespec_diff(&fps->duration, &duration);

    timespec_add(&fps->duration, &delta);

    nanosleep(&delta, NULL);
  }

  timespec_add(&fps->delta, &duration);


  // update fps counter

  struct timespec second = (struct timespec) {
    .tv_sec = 1,
    .tv_nsec = 0,
  };

  if (timespec_cmp(&fps->delta, second) < 0)
    ++fps->counter;

  else
  {
    fps->value = fps->counter;
    fps->counter = 0;
    timespec_sub(&fps->delta, second);
  }

}

