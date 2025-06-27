
// file: test1.c

#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

typedef struct stty
{
  struct termios old;
  struct termios new;
} t_stty;

t_stty stty = { 0 };

void atexit_handler(void)
{
  tcsetattr(STDIN_FILENO, TCSANOW, &stty.old);
  printf("\033[?25h");
  printf("\033[2J");
  printf("\033[0;0H");
  fflush(stdout);
}

void sigint_handler(int sig)
{
  atexit_handler();
  exit(EXIT_SUCCESS);
}

int main(void)
{
  struct timespec prev  = { 0 };
  struct timespec curr  = { 0 };
  struct timespec delta = { 0 };

  atexit(atexit_handler);
  signal(SIGINT, sigint_handler);

  tcgetattr(STDIN_FILENO, &stty.old);
  stty.new = stty.old;

  stty.new.c_cc[VMIN]  = 0;
  stty.new.c_cc[VTIME] = 0;

  tcsetattr(STDIN_FILENO, TCSANOW, &stty.new);

  printf("\033[?25l");
  fflush(stdout);

  while (true)
  {
    prev = curr;
    clock_gettime(CLOCK_MONOTONIC, &curr);
    delta.tv_sec  = curr.tv_sec  - prev.tv_sec;
    delta.tv_nsec = curr.tv_nsec - prev.tv_nsec;

    printf("\033[2J");
    printf("\033[0;0H");
    printf("%ld.%ld", curr.tv_sec, curr.tv_nsec);
    //printf("\033[0;0H");
    fflush(stdout);
  }

}

