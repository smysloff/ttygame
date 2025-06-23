
// file: fps.c

#include <stdbool.h>
#include <stdio.h>
#include <time.h>

typedef struct fps
{
  struct timespec prev;
  struct timespec curr;
  struct timespec delta;
  long count;
  long value;
} t_fps;

void fps_init(t_fps *fps)
{
  *fps = (t_fps) { 0 };

  if (clock_gettime(CLOCK_MONOTONIC, &fps->curr) == -1)
    perror("fps_init: clock_gettime fails");
}


void fps_update(t_fps *fps)
{
  fps->prev = fps->curr;

  if (clock_gettime(CLOCK_MONOTONIC, &fps->curr) == -1)
    perror("fps_update: clock_gettime fails");

  fps->delta.tv_sec = fps->curr.tv_sec - fps->prev.tv_sec;
  fps->delta.tv_nsec = fps->curr.tv_nsec - fps->prev.tv_nsec;
}

int main(void)
{
  t_fps fps;

  fps_init(&fps);

  for (int i = 0; i < 5; ++i)
  {
    usleep(1'000'000);
    long elapsed_time = fps_update(&fps);
    printf("%d: %ld\n", i, elapsed_time);
  }
}
