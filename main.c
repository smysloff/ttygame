
// file: main.c

#include <ctype.h>
#include <poll.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "config.h"
#include "stty.h"

#define CLEAR_SCREEN   "\033[2J"
#define RESTORE_CURSOR "\033[H"
#define DEFAULT_COLORS "\033[0m"

void clear_screen(void)
{
  write(STDOUT_FILENO, CLEAR_SCREEN RESTORE_CURSOR, 7);
  write(STDOUT_FILENO, DEFAULT_COLORS, 4);
}

void hide_cursor(void) {
  write(STDOUT_FILENO, "\033[?25l", 6);
}

void show_cursor(void) {
  write(STDOUT_FILENO, "\033[?25h", 6);
}


// @todo rename this struct
typedef struct string_buffer
{
  ssize_t current_size;
  char value[INPUT_BUFFER_SIZE];
} string_buffer;

void string_buffer_clear(string_buffer *buf)
{
  bzero(buf->value, sizeof(buf->value));
  buf->current_size = 0;
}

typedef struct directions
{
  bool top;
  bool down;
  bool left;
  bool right;
} directions;

typedef struct position
{
  int x;
  int y;
} position;

typedef struct entity
{
  position pos;
  directions dir;
} entity;

//#include <sys/ioctl.h>
//void get_term_size(int *w, int *h) {
//  struct winsize ws;
//  ioctl(0, TIOCGWINSZ, &ws);
//  *w = ws.ws_col;
//  *h = ws.ws_row;
//}

void update_entity(entity *e)
{
  if (e->dir.top)   e->pos.y -= 1;
  if (e->dir.down)  e->pos.y += 1;
  if (e->dir.left)  e->pos.x -= 1;
  if (e->dir.right) e->pos.x += 1;

  if (e->pos.x < 0) e->pos.x = 0;
  if (e->pos.y < 0) e->pos.y = 0;

  e->dir.top   = false;
  e->dir.down  = false;
  e->dir.left  = false;
  e->dir.right = false;
}

void draw_entity(entity *e)
{
  fprintf(stdout, "\033[48;2;255;20;147m"); // color DeepPink
  fprintf(stdout, "\033[%02d;%02dH  ", e->pos.y, e->pos.x);
  fprintf(stdout, "\033[0;0H");
  fprintf(stdout, "\033[0m");
  fflush(stdout);
}

typedef struct game_app
{
  struct pollfd fds;
  string_buffer input_buffer;
  stty termopts;
  entity player;
  bool quit;
} game_app;

game_app app = { 0 };

void atexit_handler(void)
{
  clear_screen();
  show_cursor();
  stty_restore(&app.termopts);
}

void game_init(void)
{
  atexit(atexit_handler);

  app.fds.fd = STDIN_FILENO;
  app.fds.events = POLLIN;

  stty_mode_raw(&app.termopts);
  hide_cursor();
  clear_screen();
}

bool get_input_data(void)
{
  stty_flush_input();
  string_buffer_clear(&app.input_buffer);

  if (
    poll(&app.fds, 1, FRAME_TIMEOUT_MS) > 0
    && (app.fds.revents & POLLIN)
  ) {
    app.input_buffer.current_size =
      read(
        STDIN_FILENO,
        app.input_buffer.value,
        sizeof(app.input_buffer.value)
      );

    if (app.input_buffer.current_size > 0)
    {
      app.input_buffer.value[app.input_buffer.current_size] = '\0';
      return true;
    }

    else if (app.input_buffer.current_size < 0)
    {
      perror("poll failed");
      app.quit = true;
    }
  }

  return false;
}

void keydown_handler(char c)
{
  switch (c)
  {
    case 27: // ESC
      app.quit = true;
      break;

    case 'w':
    case 'W':
      app.player.dir.top = true;
      break;

    case 's':
    case 'S':
      app.player.dir.down = true;
      break;

    case 'a':
    case 'A':
      app.player.dir.left = true;
      break;

    case 'd':
    case 'D':
      app.player.dir.right = true;
      break;
  }
}

void print_last_char(void)
{
  char c =
    app.input_buffer.value[app.input_buffer.current_size - 1];

  char output_buffer[14] = { 0 };

  snprintf(
    output_buffer,
    sizeof(output_buffer),
    "char: %c (%03d)", isprint(c) ? c : '?', c
  );

  write(STDOUT_FILENO, output_buffer, sizeof(output_buffer));

  keydown_handler(c);
}

void game_loop(void)
{
  while (!app.quit)
  {
    if (get_input_data())
    {
      clear_screen();
      print_last_char();
      update_entity(&app.player);
      draw_entity(&app.player);
    }

    else
    {
      clear_screen();
      draw_entity(&app.player);
    }
  }
}

int main(void)
{
  app.player.pos.x = 5;
  app.player.pos.y = 5;

  game_init();
  game_loop();
}
