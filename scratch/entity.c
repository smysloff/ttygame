
// file: entity.c

#include "entity.h"

entity entity_init(vec2 *pos, rgb_color *color)
{
  return (entity) {
    .pos   = vec2_clone(pos),
    .color = rgb_color_clone(color),
    .dir   = { 0 },
  };
}

