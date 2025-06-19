
// file: rgb_color.c

#include "rgb_color.h"

rgb_color rgb_color_clone(rgb_color *c)
{
  assert(c != NULL && "Attempt to clone NULL rgb_color");
  return rgb_color_init(c->r, c->g, c->b);
}

bool rgb_color_equals(const rgb_color *c1, const rgb_color *c2)
{
  assert(c1 != NULL && c2 != NULL
    && "Attemt to compare with NULL rgb_color");

  return c1->r == c2->r
      && c1->g == c2->g
      && c1->b == c2->b;
}

rgb_color rgb_color_from_hex(uint32_t hex)
{
  return (rgb_color) {
    (hex >> 16) & 0xff,
    (hex >> 8 ) & 0xff,
     hex        & 0xff,
  };
}

rgb_color rgb_color_init(uint8_t r, uint8_t g, uint8_t b)
{
  return (rgb_color) { r, g, b };
}
