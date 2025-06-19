
// file: terminal.c

#include "terminal.h"

void cursor_up(unsigned n)
{
  printf(CSI "%u" "A", n);
}

void cursor_down(unsigned n)
{
  printf(CSI "%u" "B", n);
}

void cursor_forward(unsigned n)
{
  printf(CSI "%u" "C", n);
}

void cursor_back(unsigned n)
{
  printf(CSI "%u" "D", n);
}

void cursor_next_line(unsigned n)
{
  printf(CSI "%u" "E", n);
}

void cursor_previous_line(unsigned n)
{
  printf(CSI "%u" "F", n);
}

void cursor_horizontal_absolute(unsigned n)
{
  printf(CSI "%u" "G", n);
}

void cursor_position(unsigned n, unsigned m)
{
  printf(CSI "%u;%u" "H", n, m);
}

void erase_display(ERASE_OPTION n)
{
  printf(CSI "%u" "J", n);
}

void erase_line(ERASE_OPTION n)
{
  if (n == ERASE_AND_FLUSH)
    n = ERASE_ALL;

  printf(CSI "%u" "K", n);
}

void scroll_up(unsigned n)
{
  printf(CSI "%u" "S", n);
}

void scroll_down(unsigned n)
{
  printf(CSI "%u" "T", n);
}

void horizontal_vertical_position(unsigned n, unsigned m)
{
  printf(CSI "%u;%u" "f", n, m);
}

void select_graphic_rendition(unsigned n)
{
  printf(CSI "%u" "m", n);
}

void aux_port_on(void)
{
  printf(CSI "5" "i");
}

void aux_port_off(void)
{
  printf(CSI "4" "i");
}

void device_status_report(void)
{
  printf(CSI "6" "n");
}

void cursor_save_position(void)
{
  printf(CSI "s");
}

void cursor_restore_position(void)
{
  printf(CSI "u");
}

void cursor_show(void)
{
  printf(CSI "25" "h");
}

void cursor_hide(void)
{
  printf(CSI "25" "l");
}

