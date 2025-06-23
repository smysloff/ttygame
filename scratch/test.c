
// file: test.c

#include <stdio.h>  // printf
#include <unistd.h> // usleep
#include <time.h>   // clock_gettime

struct counter
{
  struct timespec start, prev, curr;
  long delta;
};

void counter_init(struct counter *counter)
{
  clock_gettime(CLOCK_MONOTONIC, &counter->start);
  counter->curr = counter->start;
  counter->delta = 0;
};

long counter_diff(struct counter *counter) // delta in ms
{
  counter->prev = counter->curr;
  clock_gettime(CLOCK_MONOTONIC, &counter->curr);
  counter->delta = (
    (counter->curr.tv_sec - counter->prev.tv_sec) * 1000
      + (counter->curr.tv_nsec - counter->prev.tv_nsec) / 1000000
  );
  return counter->delta;
};

struct fps
{
  long count, value;
  long delta;
};

void fps_init(struct fps *fps)
{
  fps->count = 0;
  fps->value = 0;
  fps->delta = 0;
}

int main(void)
{
  struct counter counter;

  counter_init(&counter);
  usleep(100000);
  long delta = counter_diff(&counter);
  printf("frame is %ld ms long | ", delta);
  printf("need to usleep %ld ms\n", 500 - delta);
}
