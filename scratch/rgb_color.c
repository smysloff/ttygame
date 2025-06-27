
// file: rgb_color.c

#include "rgb_color.h"

t_rgb_color rgb_color_clone(t_rgb_color *c)
{
  assert(c != NULL
    && "Attempt to clone NULL t_rgb_color");

  return rgb_color_init(c->r, c->g, c->b);
}

bool rgb_color_equals(
  const t_rgb_color *c1,
  const t_rgb_color *c2
) {
  assert(c1 != NULL && c2 != NULL
    && "Attempt to compare with NULL t_rgb_color");

  return c1->r == c2->r
      && c1->g == c2->g
      && c1->b == c2->b;
}

t_rgb_color rgb_color_from_hex(
  uint32_t hex
) {
  return (t_rgb_color) {
    (hex >> 16) & 0xff,
    (hex >> 8 ) & 0xff,
     hex        & 0xff,
  };
}

t_rgb_color rgb_color_init(
  uint8_t r,
  uint8_t g,
  uint8_t b
) {
  return (t_rgb_color) { r, g, b };
}

