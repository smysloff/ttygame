
// file: signals.c

#include "signals.h"

void atexit_handler(void)
{
  cleanup_terminal();
}

void sigint_handler(int sig, siginfo_t *info, void *ucontext)
{
  (void)sig;
  (void)info;
  (void)ucontext;
  atexit_handler();
  _exit(EXIT_SUCCESS);
}

