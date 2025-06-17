
// file: stty.h

#pragma once

#include <termios.h>
#include <unistd.h>

typedef struct stty
{
  struct termios original;
  struct termios modified;
} stty;

void stty_flush_input(void);
void stty_mode_raw(stty *tty);
void stty_restore(stty *tty);
