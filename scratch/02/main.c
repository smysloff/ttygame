
// file:    main.c
// compile: gcc *.c && ./a.out

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "color.h"
#include "config.h"
#include "entity.h"
#include "fps.h"
#include "keys.h"
#include "terminal.h"
#include "timespec.h"
#include "vec2.h"

int main(void)
{
  prepare_terminal();
  init_fps();
  init_keys(get_timestamp());

  uint64_t player_id = add_entity(&(const t_entity_options) {

    .position = create_vec2f(10, 5),

    .size     = create_vec2(4, 2),

    .sprite1  = "▗▟▙▖" "\0"
                "▝▟▙▘" "\0"
                "▗▌▐▖" "\0"
                "    ",

    .sprite2  = " ▗▖ " "\0"
                "▐▜▛▌" "\0"
                " ▛▜ " "\0"
                "▝▘▝▘",

  });

  t_entity *player = get_entity(player_id);

  while (true)
  {
    // update fps counter
    // and get keys

    update_fps();
    update_keys(get_timestamp());

    // print info

    clear_screen();

    print_entity(player);
    printf("\033[H");

    //// - print fps info

    //printf("fps: %ld", get_fps());


    //// - print keys info

    //next_line();

    //const t_keys *keys = get_keys();

    //if (keys->value)
    //{
    //  (isprint(keys->value))
    //    ? printf("char: %c (%d)", keys->value,    keys->value)
    //    : printf("char: %s (%d)", keys->sequence, keys->value);
    //}

    //else
    //  printf("no input");

    //// - print game info

    //next_line();
    //printf("press any key or Ctrl+C to exit");


    // flush io
    // and add delay

    flush_terminal();
    sync_frame_rate();

  } // while (true)


  return EXIT_SUCCESS;
}
