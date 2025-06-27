
// file: terminal.h

#pragma once

#include <stdio.h>

#define CSI "\033["

typedef enum ERASE_OPTION
{
  ERASE_TO_END = 0,
  ERASE_TO_BEGIN = 1,
  ERASE_ALL = 2,
  ERASE_AND_FLUSH = 3,
} ERASE_OPTION;

void cursor_up(unsigned n); // CUU

void cursor_down(unsigned n); // CUD

void cursor_forward(unsigned n); // CUF

void cursor_back(unsigned n); // CUB

void cursor_next_line(unsigned n); // CNL

void cursor_previous_line(unsigned n); // CPL

void cursor_horizontal_absolute(unsigned n); // CHA

void cursor_position(unsigned n, unsigned m); // CUP

void erase_display(ERASE_OPTION opt); // ED

void erase_line(ERASE_OPTION opt); // EL

void scroll_up(unsigned n); // SU

void scroll_down(unsigned n); // SD

void horizontal_vertical_position(unsigned n, unsigned m); // HVP

void select_graphic_rendition(unsigned n); // SGR

void aux_port_on(void);

void aux_port_off(void);

void device_status_report(void); // DSR

void cursor_save_position(void); // SCP

void cursor_restore_position(void); // RCP

void cursor_show(void); // DECTCEM

void cursor_hide(void); // DECTCEM

void clear_screen(void);

