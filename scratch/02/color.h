
// file: color.h

#pragma once

#include <assert.h>
#include <inttypes.h>
#include <stddef.h>

typedef struct color
{
  uint8_t r, g, b;
} t_color;

t_color create_color(uint8_t r, uint8_t g, uint8_t b);

void init_color(t_color *c, uint8_t r, uint8_t g, uint8_t b);

