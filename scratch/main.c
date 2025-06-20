
// file: main.c

#include "game_engine.h"

extern game_engine g;

int main(void)
{
  game_add_entity(
    vec2_init(21, 42), rgb_color_init(0, 255, 0));

  game_add_entity(
    vec2_init(42, 21), rgb_color_init(0, 0, 255));

  game_init();
  game_loop();
  game_over();

  vec2_print(&g.entities[0].pos);
  vec2_print(&g.entities[1].pos);
}

