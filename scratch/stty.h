
// file: stty.h

#pragma once

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#include "config.h"
#include "terminal.h"

typedef struct stty
{
  struct termios original;
  struct termios modified;
} stty;

void stty_flush_input(void);

void stty_frame_rate(int rate);

void stty_mode_raw(void);

void stty_restore(void);

