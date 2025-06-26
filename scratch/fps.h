
// file: fps.h

#pragma once

#include <assert.h>
#include "config.h"
#include "timespec.h"

typedef struct fps
{
  t_timespec prev;
  t_timespec curr;
  t_timespec duration;
  t_timespec delta;
  long count;
  long value;
} t_fps;

t_fps fps_create(
  long frame_rate
);

void fps_init(
  t_fps *fps,
  long frame_rate
) __attribute__((nonnull(1)));

void fps_update(
  t_fps *fps
) __attribute__((nonnull(1)));

