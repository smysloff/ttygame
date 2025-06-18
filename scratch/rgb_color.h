
// file: rgb_color.h

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct rgb_color
{
  unsigned char r, g, b;
} rgb_color;

rgb_color rgb_color_clone(rgb_color *c);

bool rgb_color_equals(
  const rgb_color *c1, const rgb_color *c2);

rgb_color rgb_color_from_hex(uint32_t hex);

rgb_color rgb_color_init(uint8_t r, uint8_t g, uint8_t b);
