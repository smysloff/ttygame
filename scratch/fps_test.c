
// file: fps_test.c

#include <stdio.h>
#include "fps.h"

#define FRAME_RATE 2

int main(void)
{
  t_fps fps = fps_create(FRAME_RATE);

  printf("%ld %ld\n", fps.curr.tv_sec, fps.curr.tv_nsec);
}
