
// file: stty.h

<<<<<<< HEAD
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#include "config.h"
#include "terminal.h"

=======
#pragma once

#include <termios.h>
#include <unistd.h>

>>>>>>> 34901ac (wip: refactor)
typedef struct stty
{
  struct termios original;
  struct termios modified;
} stty;

<<<<<<< HEAD
void stty_frame_rate(int rate);

void stty_restore(void);
=======
void stty_flush_input(void);

void stty_mode_raw(stty *tty);

void stty_restore(stty *tty);
>>>>>>> 34901ac (wip: refactor)

