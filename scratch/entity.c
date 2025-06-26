
// file: entity.c

#include "entity.h"

t_entity entity_init(t_vec2 *pos, t_rgb_color *color)
{
  return (t_entity) {
    .pos   = vec2_clone(pos),
    .color = rgb_color_clone(color),
    .dir   = { 0 },
  };
}

