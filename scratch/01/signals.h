
// file: signals.h

#pragma once

#include <stdlib.h>
#include <unistd.h>

#include "terminal.h"

void atexit_handler(void);

void sigint_handler(int sig, siginfo_t *info, void *ucontext);

