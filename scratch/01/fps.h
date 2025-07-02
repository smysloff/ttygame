
// file: fps.h

#pragma once

#include <time.h>

#include "config.h"
#include "timespec.h"

typedef struct fps
{
  struct timespec timestamp;
  struct timespec lasttime;
  struct timespec deltatime;
  struct timespec current_frame_duration;
  struct timespec required_frame_duration;
  long count;
  long value;
} t_fps;

void init_fps(void);

void update_timestamp(void);

void update_fps(void);

void sync_frame_rate(void);

const struct timespec *get_timestamp(void);

long get_fps(void);

