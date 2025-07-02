
// keys.c

#include "keys.h"

static t_keys keys;

void init_keys(const struct timespec *timestamp)
{
  keys.time = *timestamp;
}

void update_keys(
  const struct timespec *timestamp
) {
    // read key from stdin

    ssize_t bytes_read = read(STDIN_FILENO, &keys.value, 1);

    if (bytes_read == 1)
    {
      keys.time = *timestamp;

      // handle multi-byte keys

      if (!isprint(keys.value))
      {
        char c;
        size_t i = 0;

        keys.sequence[i++] = '?';

        while (
          read(STDIN_FILENO, &c, 1) == 1
          && i < sizeof(keys.sequence) - 1
        ) {
          keys.sequence[i++] = c;
        }

        keys.sequence[i] = '\0';
      }
    }

    keys.duration = timespec_diff(timestamp, &keys.time);

    if (keys.duration.tv_sec >= 1)
      keys.value = 0;
}

const t_keys *get_keys(void)
{
  return (const t_keys *) &keys;
}

