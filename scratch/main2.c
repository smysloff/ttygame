
// file: main.c

#define FRAME_RATE 2

int main(void)
{
  t_fps fps = fps_init(FRAME_RATE);

  for (int i = 0; i < 10; ++i)
  {
    fps_update(&fps);
    printf("%ld %ld\n", fps.count, fps.value);
  }
}
