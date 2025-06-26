
// file: vec2.c

#include "vec2.h"

t_vec2 vec2_clone(const vec2 *v)
{
  assert(v != NULL && "Attempt to clone NULL t_vec2");
  return vec2_init(v->x, v->y);
}

bool vec2_equals(const t_vec2 *v1, const t_vec2 *v2)
{
  assert(v1 != NULL && v2 != NULL
    && "Attempt to compare with NULL t_vec2");

  return (v1->x == v2->x)
      && (v1->y == v2->y);
}

t_vec2 vec2_init(int x, int y)
{
  return (t_vec2) { x, y };
}

void vec2_print(const t_vec2 *v)
{
  assert(v != NULL && "Attempt to print NULL t_vec2");
  printf("t_vec2 { x: %d, y: %d }\n", v->x, v->y);
}

