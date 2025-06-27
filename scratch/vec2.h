
// file: vec2.h

#pragma once

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct vec2
{
  int x, y;
} t_vec2;

t_vec2 vec2_clone(
  const t_vec2 *v
) __attribute__((nonnull(1)));

bool vec2_equals(
  const t_vec2 *v1,
  const t_vec2 *v2
) __attribute__((nonnull(1, 2)));

t_vec2 vec2_init(int x, int y);

void vec2_print(
  const t_vec2 *v
) __attribute__((nonnull(1)));

