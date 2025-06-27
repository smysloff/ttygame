
// file: rgb_color.h

#pragma once

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct t_rgb_color
{
  uint8_t r, g, b;
} t_rgb_color;

t_rgb_color rgb_color_clone(
  t_rgb_color *c
) __attribute((nonnull(1)));

bool rgb_color_equals(
  const t_rgb_color *c1,
  const t_rgb_color *c2
) __attribute((nonnull(1, 2)));

t_rgb_color rgb_color_from_hex(uint32_t hex);

t_rgb_color rgb_color_init(
  uint8_t r,
  uint8_t g,
  uint8_t b
);

