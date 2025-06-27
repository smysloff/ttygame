
// file: game_engine.c

#include "game_engine.h"

t_game_engine g = { 0 };

size_t last_entity_id = 0;

static void sigint_handler(int sig)
{
  stty_restore();
  exit(EXIT_FAILURE);
}

void game_init(void)
{
  signal(SIGINT, sigint_handler);
  atexit(stty_restore);
  stty_mode_raw();
  fps_init(&g.fps, FRAME_RATE);
}

void game_loop(void)
{
  while (!g.quit)
  {
    // update

    fps_update(&g.fps);


    // render

    clear_screen();

    printf("fps:   %ld (%ld)",
      g.fps.value, g.fps.count);

    cursor_next_line(0);

    printf("prev:  %ld.%ld sec",
      g.fps.prev.tv_sec, g.fps.prev.tv_nsec);

    cursor_next_line(0);

    printf("curr:  %ld.%ld sec",
      g.fps.curr.tv_sec, g.fps.curr.tv_nsec);

    cursor_next_line(0);

    printf("delta: %ld.%ld sec",
      g.fps.delta.tv_sec, g.fps.delta.tv_nsec);

    cursor_position(0, 0);


    // flush

    fflush(stdout);
  }
}

void game_over(void)
{
  printf("game over\n");

  // ...
}

void game_add_entity(
  t_vec2 pos,
  t_rgb_color color
) {
  assert(last_entity_id < sizeof(g.entities)
    && "Created too many entities!");

  g.entities[last_entity_id++] = entity_init(&pos, &color);
}
