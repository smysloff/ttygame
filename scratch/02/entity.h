
// file: entity.h

#pragma once

#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>

#include "color.h"
#include "vec2.h"

#define MAX_ENTITY_COUNT 8
#define SPRITE_SIZE 64

typedef struct entity
{
  uint64_t id;
  t_vec2f  position;
  t_vec2   size;
  t_color  color;
  int64_t  health;
  int64_t  speed; // nansec for 1 tile
  char     sprite1[SPRITE_SIZE];
  char     sprite2[SPRITE_SIZE];
} t_entity;

typedef struct entity_options
{
  t_vec2f  position;
  t_vec2   size;
  t_color  color;
  int64_t  health;
  int64_t  speed;
  char     sprite1[SPRITE_SIZE];
  char     sprite2[SPRITE_SIZE];
} t_entity_options;

uint64_t add_entity(const t_entity_options *o);

t_entity *get_entity(int64_t id);

void log_entity(const t_entity *e);

void print_entity(const t_entity *e);

