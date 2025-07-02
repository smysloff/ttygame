
// file: color.c

#include "color.h"

t_color create_color(uint8_t r, uint8_t g, uint8_t b)
{
  return (t_color) { r, g, b };
}

void init_color(t_color *c, uint8_t r, uint8_t g, uint8_t b)
{
  assert(c != NULL && "Attempt to init NULL pointer");
  c->r = r;
  c->g = g;
  c->b = b;
}

