
// file: fps.c

#include "fps.h"

t_fps fps_create(long frame_rate)
{
  t_fps fps = { 0 };
  fps_init(&fps, frame_rate);
  return fps;
}

void fps_init(t_fps *fps, long frame_rate)
{
  timespec_init(&fps->curr, frame_rate);

  fps->duration.tv_nsec = (frame_rate > 0)
    ? NSEC_PER_SEC / frame_rate
    : NSEC_PER_SEC;
}

void fps_update(t_fps *fps)
{
  // save previous current time
  fps->prev = fps->curr;

  // get new current time
  timespec_init(&fps->curr, CLOCK_MONOTONIC);

  // get current frame duration
  t_timespec frame_duration = timespec_diff(&fps->curr, &fps->prev);

  // add current frame duration to fps delta counter
  timespec_add(&fps->delta, &frame_duration);

  // add delay to the current frame duration
  // to sync frame duration with a frame rate
  if (timespec_cmp(&fps->duration, &frame_duration) == GREATER)
  {
    // find difference between needle and actual frame duration
    t_timespec diff =
      timespec_diff(&fps->duration, &frame_duration);

    // add this difference to fps delta counter
    timespec_add(&fps->delta, &diff);

    // sleep
    clock_nanosleep(CLOCK_MONOTONIC, 0, &diff, NULL);
  }


  // update fps counter

  if (fps->delta.tv_sec < 1)
    ++fps->count;

  // of update fps value if fps->delta >g 1 sec

  else
  {
    fps->value = fps->count;
    fps->count = 0;

    while (fps->delta.tv_sec > 0)
      --fps->delta.tv_sec;
  }

}

