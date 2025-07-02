
// file: vec2.h

#pragma once

#include <assert.h>
#include <inttypes.h>
#include <stddef.h>

typedef struct vec2
{
  int64_t x, y;
} t_vec2;

t_vec2 create_vec2(int64_t x, int64_t y);

void init_vec2(t_vec2 *v, int64_t x, int64_t y);

