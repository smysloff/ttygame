
// file: fps.h

#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#include "config.h"
#include "timespec.h"

typedef struct fps
{
  struct timespec prev;
  struct timespec curr;
  struct timespec delta;
  struct timespec duration;
  long count;
  long value;
} t_fps;

t_fps fps_init(long frame_rate);

void fps_update(t_fps *fps);

