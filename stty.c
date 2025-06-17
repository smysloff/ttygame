
// file: stty.c

#include "stty.h"

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
}
