
// file: game_engine.c

#include "game_engine.h"

t_game_engine g = { 0 };

void game_init(void)
{
  atexit(stty_restore);
  //stty_frame_rate(TIMEOUT);
  stty_frame_rate(5);
}

void game_loop(void)
{
  int i = 0;

  char buf[8] = { 0 };

  while (!g.quit)
  {
    // stty_frame()

    // clear screan
    erase_display(ERASE_ALL);
    select_graphic_rendition(0);
    cursor_position(0, 0);
    //fflush(stdout);

    ssize_t read_bytes =
      read(STDIN_FILENO, buf, sizeof(buf) - 1);

    buf[read_bytes] = '\0';


    printf("%d: %s", i++, buf);
    cursor_position(0, 0);

    memset(buf, 0, sizeof(buf));

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
