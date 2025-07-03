
// file: entity.c

#include "entity.h"

static uint64_t current_entity_id = 0;
static t_entity entities[MAX_ENTITY_COUNT];

uint64_t add_entity(const t_entity_options *o)
{
  assert(current_entity_id < MAX_ENTITY_COUNT && "Attempt to init too many entities");
  assert(o->health >= 0     && "Attempt to create entity with negative health");
  assert(o->speed  >= 0     && "Attempt to create entity with negative speed");
  assert(o->sprite1 != NULL && "Attempt to create entity with NULL sprite");
  assert(o->sprite2 != NULL && "Attempt to create entity with NULL sprite");

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
  assert(current_entity_id < MAX_ENTITY_COUNT && "Attempt to get entity that can't exist");

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
  long x = (long) e->position.x;
  long y = (long) e->position.y;

  const char *sprite = ((x & 1) == 0 ? e->sprite1 : e->sprite2);

  for (size_t i = 0; i < e->size.y; ++i)
  {
     printf(
      "\033[%ld;%ldH" "%.*s",
      x, y + i,
      e->size.y,
      sprite + i * e->size.x * 2 // 2 -> horizontal scale
    );
  }

}

//int main(void)
//{
//  uint64_t e_id = add_entity(&(const t_entity_options) {
//
//    .position = create_vec2f(10, 21),
//
//    .size     = create_vec2(4, 2),
//
//    .sprite1  = "▗▟▙▖" "\n"
//                "▝▟▙▘" "\n"
//                "▗▌▐▖" "\n"
//                "    " "\n",
//
//    .sprite2  = " ▗▖ " "\n"
//                "▐▜▛▌" "\n"
//                " ▛▜ " "\n"
//                "▝▘▝▘" "\n",
//
//  });
//
//  //uint64_t e_id = add_entity(&(const t_entity_options) {
//
//  //  .position = create_vec2f(10, 21),
//
//  //  .size     = create_vec2(4, 2),
//
//  //  .sprite1  = "▗▟▙▖" "\n"
//  //              "▝▟▙▘" "\n"
//  //              "▗▌▐▖" "\n"
//  //              "    " "\n",
//
//  //  .sprite2  = " ▗▖ " "\n"
//  //              "▐▜▛▌" "\n"
//  //              " ▛▜ " "\n"
//  //              "▝▘▝▘" "\n",
//
//  //});
//
//  const t_entity *e = get_entity(e_id);
//
//  log_entity(e);
//
//
//  printf("\033[2J\033[H\033[?25l"); // erase display
//                                    // set cursor to (0,0)
//                                    // hide cursor
//
//  print_entity(e);
//
//  printf("\033[?25h");              // show cursor
//
//  fflush(stdout);
//}

