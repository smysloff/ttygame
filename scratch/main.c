#include <stdio.h>

#include "entity.h"
#include "rgb_color.h"
#include "vec2.h"

#define ENTITY_COUNT 8

typedef struct game_engine
{
  entity entities[ENTITY_COUNT];
  size_t entity_id;
} game_engine;

game_engine g = { 0 };

void game_init(void)
{
  printf("game init\n");
}

void game_loop(void)
{
  printf("game loop\n");
}

void game_over(void)
{
  printf("game over\n");
}

void game_add_entity(vec2 pos, rgb_color color)
{
  assert(g.entity_id < sizeof(g.entities) && "Too many entities!");
  g.entities[g.entity_id++] = entity_init(pos, color);
}

int main(void)
{
  game_add_entity(
    vec2_init(21, 42), rgb_color_init(  0, 255,   0));

  game_add_entity(
    vec2_init(42, 21), rgb_color_init(  0,   0, 255));

  game_init();
  game_loop();
  game_over();

  vec2_print(&g.entities[0]);
  vec2_print(&g.entities[1]);
}
