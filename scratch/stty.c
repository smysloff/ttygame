
// file: stty.c

#include "stty.h"

stty termopts = { 0 };

void stty_flush_input(void)
{
  tcflush(STDIN_FILENO, TCIFLUSH);
}

void stty_frame_rate(int rate)
{
  tcgetattr(STDIN_FILENO, &termopts.original);

  termopts.modified = termopts.original;

  termopts.modified.c_lflag &= ~(ICANON | ECHO);
  termopts.modified.c_cc[VMIN] = UCHAR_MAX;
  termopts.modified.c_cc[VTIME] = rate;

  tcsetattr(STDIN_FILENO, TCSAFLUSH, &termopts.modified);

  cursor_hide();

  // clear screan
  erase_display(ERASE_ALL);
  select_graphic_rendition(0);
  cursor_position(0, 0);
}

void stty_mode_raw(void)
{
  tcgetattr(STDIN_FILENO, &termopts.original);
  termopts.modified = termopts.original;
  termopts.modified.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &termopts.modified);
}

void stty_restore(void)
{
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &termopts.original);

  // clear screan
  erase_display(ERASE_ALL);
  select_graphic_rendition(0);
  cursor_position(0, 0);

  cursor_show();
}

