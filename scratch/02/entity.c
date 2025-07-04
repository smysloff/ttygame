
// file: entity.c

#include "entity.h"

static uint64_t current_entity_id = 0;
static t_entity entities[MAX_ENTITY_COUNT];

uint64_t add_entity(const t_entity_options *o)
{
  assert(current_entity_id < MAX_ENTITY_COUNT
    && "Attempt to init too many entities");

  assert(o->health >= 0
    && "Attempt to create entity with negative health");

  assert(o->speed  >= 0
    && "Attempt to create entity with negative speed");

  assert(o->sprite1 != NULL
    && "Attempt to create entity with NULL sprite");

  assert(o->sprite2 != NULL
    && "Attempt to create entity with NULL sprite");

  t_entity *e = &entities[current_entity_id];

  e->id       = current_entity_id;
  e->position = o->position;
  e->size     = o->size,
  e->color    = o->color;
  e->health   = o->health;
  e->speed    = o->speed;

  snprintf(e->sprite1, sizeof(e->sprite1), "%s", o->sprite1);
  snprintf(e->sprite2, sizeof(e->sprite2), "%s", o->sprite2);

  return current_entity_id++;
}

t_entity *get_entity(int64_t id)
{
  assert(current_entity_id < MAX_ENTITY_COUNT
    && "Attempt to get entity that can't exist");

  return &entities[id];
}

void log_entity(const t_entity *e)
{
  printf(
    "entity <%" PRIu64 "> {\n"
    "\t" "position: { x: %f, y: %f },\n"
    "\t" "color:    { r: %" PRIu8  ", g: %" PRIu8  ", b: %" PRIu8 " },\n"
    "\t" "health:   %" PRId64 ",\n"
    "\t" "speed:    %" PRId64 ",\n"
    "}\n",
    e->id,
    e->position.x, e->position.y,
    e->color.r,    e->color.g,    e->color.b,
    e->health,
    e->speed
  );
}

void print_entity(const t_entity *e)
{
  long x = (int) e->position.x; // terminal works with
  long y = (int) e->position.y; // integers

  const char *sprite = (
    (x & 1) == 0 ? e->sprite1 : e->sprite2
  );

  //for (size_t i = 0; i < e->size.y; ++i)
  //{
     ssize_t bytes_written = printf(
      "\033[%d;%dH" "%s",
      (int) y, (int) x,
      sprite + strlen(sprite) + 1 // 2 -> horizontal scale
    );

    printf("|%zd|", bytes_written);
  //}

}

