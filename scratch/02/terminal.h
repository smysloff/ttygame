
// file: terminal.h

#pragma once

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

#include "signals.h"

typedef struct termopts
{
  struct termios original;
  struct termios modified;
} t_termopts;

void prepare_terminal(void);

void cleanup_terminal(void);

void flush_terminal(void);

void clear_screen(void);

void next_line(void);

