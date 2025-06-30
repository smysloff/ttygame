
// file:    main.c
// compile: gcc *.c && ./a.out

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "config.h"
#include "keys.h"
#include "terminal.h"
#include "timespec.h"


// source code

typedef struct fps
{
  struct timespec prev;
  struct timespec curr;
  struct timespec delta;
  long value;
  long count;
} t_fps;


int main(void)
{
  t_keys keys = {0};

  prepare_terminal();

  timespec_gettime(&keys.time);


  while (true)
  {
    struct timespec timestamp; // fps | game_engine
    ssize_t bytes_read;

    timespec_gettime(&timestamp);


    // get keys

    bytes_read = read(STDIN_FILENO, &keys.pressed, 1);

    if (bytes_read == 1)
    {
      keys.time = timestamp;

      if (!isprint(keys.pressed))
      {
        char c;
        size_t i = 0;
        keys.sequence[i++] = '?';
        while (
          read(STDIN_FILENO, &c, 1) == 1
          && i < sizeof(keys.sequence) - 1
        ) {
          keys.sequence[i++] = c;
        }
        keys.sequence[i] = '\0';
      }
    }

    keys.duration = timespec_diff(&timestamp, &keys.time);

    if (keys.duration.tv_sec >= 1)
      keys.pressed = 0;


    // print keys

    clear_screen();

    if (keys.pressed)
    {
      (isprint(keys.pressed))
        ? printf("char: %c (%d)", keys.pressed,  keys.pressed)
        : printf("char: %s (%d)", keys.sequence, keys.pressed);
    }

    else
      printf("no input");


    // print info

    next_line();
    printf("press any key or Ctrl+C to exit");


    // flush io

    flush_terminal();


    // delay between frames

    struct timespec sleep_time = {
      .tv_sec  = 0,
      .tv_nsec = FRAME_DURATION,
    };
    clock_nanosleep(CLOCK_MONOTONIC, 0, &sleep_time, NULL);

  } // while (true)


  return EXIT_SUCCESS;
}
