
// file: stty.h

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

void stty_frame_rate(int rate);

void stty_restore(void);

