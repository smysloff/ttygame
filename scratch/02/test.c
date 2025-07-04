#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WIDTH_SCALE  2
#define HEIGHT_SCALE 1

typedef struct vec2
{
  int64_t x, y;
} t_vec2;

typedef struct sprite
{
  const char *ptr;
  int64_t w, h;
} t_sprite;


size_t sprite_width  = 2;
size_t sprite_height = 4;

void print_sprite(t_sprite *sprite, t_vec2 *position)
{
  assert(sprite != NULL);
  assert(position != NULL);

  const char *ptr = sprite->ptr;

  for (size_t i = 0; i < sprite->h; ++i)
  {
    size_t len = strlen(ptr);

    ssize_t bytes_written = printf(
      "\033[%d;%dH%s",
      (int) (position->y + i),
      (int) position->x,
      ptr
    );

    if (bytes_written < 0)
    {
      perror("printf fails!");
      exit(EXIT_FAILURE);
    }

    ptr += (len + 1);
  }
  printf("\n");
}


int main(void)
{
  t_vec2 position = { .x = 10, .y = 5 };

  t_sprite sprite = {
    .ptr = "▗▟▙▖" 
      "\0" "▝▟▙▘" 
      "\0" "▗▌▐▖" 
      "\0" "++++",
    .w = 2, .h = 4,
  };

  print_sprite(&sprite, &position);

  return EXIT_SUCCESS;
}

