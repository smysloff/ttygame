
// file: game_engine.h

#pragma once

#include <signal.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#include "config.h"
#include "entity.h"
#include "fps.h"
#include "rgb_color.h"
#include "stty.h"
#include "terminal.h"
#include "vec2.h"

typedef struct game_engine
{
  t_entity entities[ENTITY_COUNT];
  t_fps fps;
  bool quit;
} t_game_engine;

void game_init(void);

void game_loop(void);

void game_over(void);

void game_add_entity(
  t_vec2 pos,
  t_rgb_color color
);

