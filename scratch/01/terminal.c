
// file: terminal.c

#include "terminal.h"

t_termopts termopts = {0};

void prepare_terminal(void)
{
  // set signal handlers
  // for cleanup terminal after program ends

  struct sigaction sigact = {
    .sa_sigaction = sigint_handler,
    .sa_flags = SA_SIGINFO | SA_RESTART,
    .sa_mask = {{0}},
  };

  sigaction(SIGINT,  &sigact, NULL);
  sigaction(SIGTERM, &sigact, NULL);
  atexit(atexit_handler);

  // configure terminal
  // to work in real time input/output

  tcgetattr(STDIN_FILENO, &termopts.original); // -> 0|-1
  termopts.modified = termopts.original;

  cfmakeraw(&termopts.modified);
  termopts.modified.c_lflag |= (ISIG | IEXTEN);

  termopts.modified.c_cc[VMIN]  = 0;
  termopts.modified.c_cc[VTIME] = 0;

  tcsetattr(STDIN_FILENO, TCSANOW, &termopts.modified); // -> 0|-1

  printf("\033[2J\033[H\033[?25l"); // erase display
                                    // set cursor to (0,0)
                                    // hide cursor
  fflush(stdout);
}

void cleanup_terminal(void)
{
  printf("\033[2J\033[H\033[?25h"); // erase display
                                    // set cursor to (0,0)
                                    // show cursor
  fflush(stdout);

  tcsetattr(STDIN_FILENO, TCSANOW, &termopts.original); // -> 0|-1
}

void flush_terminal(void)
{
  fflush(stdout);
  tcflush(STDIN_FILENO, TCIFLUSH);
}

void clear_screen(void)
{
  printf("\033[2J\033[H"); // erase display
                           // set cursor to (0,0)
}

void next_line(void)
{
  printf("\033[E"); // move cursor to begining next line
}

