
// file: entity.h

#pragma once

#include "rgb_color.h"
#include "vec2.h"

typedef struct directions
{
  bool top,  down;
  bool left, right;
} t_directions;

typedef struct entity
{
  t_vec2       pos;
  t_rgb_color  color;
  t_directions dir;
} t_entity;

t_entity entity_init(
  t_vec2 *pos,
  t_rgb_color *color
) __attribute__((nonnull(1)));

