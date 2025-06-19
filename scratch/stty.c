
// file: stty.c

#include "stty.h"

<<<<<<< HEAD
stty termopts = { 0 };

void stty_frame_rate(int rate)
{
  tcgetattr(STDIN_FILENO, &termopts.original);

  termopts.modified = termopts.original;

  termopts.modified.c_lflag &= ~(ICANON | ECHO);
  termopts.modified.c_cc[VMIN] = UCHAR_MAX;
  termopts.modified.c_cc[VTIME] = rate;

  tcsetattr(STDIN_FILENO, TCSAFLUSH, &termopts.modified);

  cursor_hide();
  cursor_position(0, 0);
  erase_display(ERASE_ALL);
}

void stty_restore(void)
{
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &termopts.original);

  erase_display(ERASE_ALL);
  cursor_position(0, 0);
  select_graphic_rendition(0);
  cursor_show();
=======
// @todo error handling
void stty_flush_input(void)
{
  tcflush(STDIN_FILENO, TCIFLUSH);
}

// @todo error handling
void stty_mode_raw(stty *tty)
{
  tcgetattr(STDIN_FILENO, &tty->original);
  tty->modified = tty->original;
  tty->modified.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &tty->modified);
}

// @todo error handling
void stty_restore(stty *tty)
{
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &tty->original);
>>>>>>> 34901ac (wip: refactor)
}

