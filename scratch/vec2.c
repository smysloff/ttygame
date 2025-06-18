
// file: vec2.c

#include "vec2.h"

vec2 vec2_clone(const vec2 *v)
{
  assert(v != NULL && "Attempt to clone NULL vec2");
  return vec2_init(v->x, v->y);
}

bool vec2_equals(const vec2 *v1, const vec2 *v2)
{
  assert(v1 != NULL && v2 != NULL
    && "Attemt to compare with NULL vec2");

  return (v1->x == v2->x)
      && (v1->y == v2->y);
}

vec2 vec2_init(int x, int y)
{
  return (vec2) { x, y };
}

void vec2_print(const vec2 *v)
{
  assert(v != NULL && "Attempt to print NULL vec2");
  printf("vec2 { x: %d, y: %d }\n", v->x, v->y);
}
