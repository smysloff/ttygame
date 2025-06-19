
// file: vec2.h

#pragma once

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct vec2
{
  int x, y;
} vec2;

vec2 vec2_clone(const vec2 *v);

bool vec2_equals(const vec2 *v1, const vec2 *v2);

vec2 vec2_init(int x, int y);

void vec2_print(const vec2 *v);

