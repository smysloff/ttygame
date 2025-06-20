
// file: game_engine.h

#pragma once

#include <unistd.h>
#include <stddef.h>

#include "config.h"
#include "entity.h"
#include "rgb_color.h"
#include "stty.h"
#include "terminal.h"
#include "vec2.h"

typedef struct game_engine
{
  entity entities[ENTITY_COUNT];
  size_t entity_id;
  stty termopts;
} game_engine;

void game_init(void);

void game_loop(void);

void game_over(void);

void game_add_entity(vec2 pos, rgb_color color);

