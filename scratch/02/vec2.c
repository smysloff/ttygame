
// file: vec2.c

#include "vec2.h"

t_vec2 create_vec2(int64_t x, int64_t y)
{
  return (t_vec2) { x, y };
}

void init_vec2(t_vec2 *v, int64_t x, int64_t y)
{
  assert(v != NULL && "Attempt to init NULL pointer");
  v->x = x;
  v->y = y;
}

t_vec2f create_vec2f(double x, double y)
{
  return (t_vec2f) { .x = x, .y = y };
}

void init_vec2f(t_vec2f *v, double x, double y)
{
  assert(v != NULL && "Attempt to init NULL pointer");
  v->x = x;
  v->y = y;
}

