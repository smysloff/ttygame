
// file: entity.h

#pragma once

#include "rgb_color.h"
#include "vec2.h"

typedef struct directions
{
  bool top,  down;
  bool left, right;
} directions;

typedef struct entity
{
  vec2       pos;
  rgb_color  color;
  directions dir;
} entity;

entity entity_init(vec2 *pos, rgb_color *color);
