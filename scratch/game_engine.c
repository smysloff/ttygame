
// file: game_engine.c

#include "game_engine.h"

game_engine g = { 0 };

void game_init(void)
{
  stty_frame_rate(TIMEOUT);
  atexit(stty_restore);
}

void game_loop(void)
{
  for (int i = 0; i < 10; ++i)
  {
    erase_display(ERASE_ALL);
    cursor_position(0, 0);
    select_graphic_rendition(0);
    cursor_hide();
    fflush(stdout);

    printf("%d", i);
    cursor_position(0, 0);
    cursor_hide();
    fflush(stdout);

    sleep(1);
  }
}

void game_over(void)
{
  printf("game over\n");

  // ...
}

void game_add_entity(vec2 pos, rgb_color color)
{
  assert(g.entity_id < sizeof(g.entities) && "Too many entities!");
  g.entities[g.entity_id++] = entity_init(&pos, &color);
}
