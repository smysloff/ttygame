
// file: fps.c

#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>


struct fps
{
  struct timespec prev, curr;
  long count, value;
};

void fps_set_frame_rate(struct *fps, int frame_rate)
{
  
}

void fps_update(struct *fps)
{

}


int main(void)
{
  struct fps fps = { 0 };

  while (true)
  {
    fps_update(&fps);
  }
}
