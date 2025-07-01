
// file: entity.c

#include <assert.h>
#include <inttypes.h>
#include <stdio.h>

#define MAX_ENTITY_ID 1024

typedef struct vec2
{
  int64_t x, y;
} t_vec2;

t_vec2 create_vec2(int64_t x, int64_t y)
{
  return (t_vec2) { x, y };
}

void init_vec2(t_vec2 *v, int64_t x, int64_t y)
{
  assert(v != NULL);
  v->x = x;
  v->y = y;
}

typedef struct color
{
  uint8_t r, g, b;
} t_color;

t_color create_color(uint8_t r, uint8_t g, uint8_t b)
{
  return (t_color) { r, g, b };
}

void init_color(t_color *c, uint8_t r, uint8_t g, uint8_t b)
{
  assert(c != NULL);
  c->r = r;
  c->g = g;
  c->b = b;
}

typedef struct entity
{
  uint64_t id;
  t_vec2   position;
  t_color  color;
  int64_t  health;
  int64_t  speed; // nansec for 1 tile
} t_entity;

typedef struct entity_options
{
  t_vec2   position;
  t_color  color;
  int64_t  health;
  int64_t  speed;
} t_entity_options;

static uint64_t last_entity_id;
static t_entity entities[MAX_ENTITY_ID];

uint64_t add_entity(t_entity_options &o)
{
  
}

void log_entity(const t_entity *e)
{
  printf(
    "entity <%" PRIu64 "> {\n"
    "\t\t" "color: [%" PRIu8 ", %" PRIu8"]"
  );
}

int main(void)
{
  uint64_t id = add_entity((t_entity_options *) &({
    .health = 100,
    .speed  = 100,
  }));
}
