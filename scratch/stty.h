
// file: stty.h

#pragma once

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#include "config.h"
#include "terminal.h"

typedef struct termios t_termios;

typedef struct stty
{
  t_termios original;
  t_termios modified;
} t_stty;

void stty_flush_input(void);

void stty_mode_raw(void);

void stty_restore(void);

