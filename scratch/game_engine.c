
// file: game_engine.c

#include "game_engine.h"

game_engine g = { 0 };

void game_init(void)
{
  atexit(stty_restore);
  stty_frame_rate(TIMEOUT);
}

void game_loop(void)
{
  while (!g.quit)
  {
    // stty_frame()

    // clear screan
    erase_display(ERASE_ALL);
    select_graphic_rendition(0);
    cursor_position(0, 0);
    //fflush(stdout);

    printf("%d", i);
    cursor_position(0, 0);

    // stty_flush()
    fflush(stdout);
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
