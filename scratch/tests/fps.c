
// file: fps.c

#include "fps.h"

static t_fps fps;

void init_fps(void)
{
  fps.required_frame_duration = (struct timespec) {
    .tv_sec  = 0,
    .tv_nsec = FRAME_DURATION,
  };

  timespec_gettime(&fps.timestamp);
}

void update_timestamp(void)
{
  fps.lasttime = fps.timestamp;
  timespec_gettime(&fps.timestamp);
}

void update_fps(void)
{
  update_timestamp();

  fps.current_frame_duration =
    timespec_diff(&fps.timestamp, &fps.lasttime);

  timespec_add(&fps.deltatime, &fps.current_frame_duration);

  ++fps.count;

  while (fps.deltatime.tv_sec > 0)
  {
    fps.value = fps.count;
    fps.count = 0;
    --fps.deltatime.tv_sec;
  }

}

void sync_frame_rate(void)
{
  // @todo timespec_cmp
  struct timespec sleep_time = timespec_diff(
    &fps.required_frame_duration, &fps.current_frame_duration);

  clock_nanosleep(CLOCK_MONOTONIC, 0, &sleep_time, NULL);
}

const struct timespec *get_timestamp(void)
{
  return (const struct timespec *) &fps.timestamp;
}

long get_fps(void)
{
  return fps.value;
}


