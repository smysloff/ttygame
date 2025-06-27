
// file: stty.c

#include "stty.h"

t_stty termopts = { 0 };

void stty_flush_input(void)
{
  tcflush(STDIN_FILENO, TCIFLUSH);
}

void stty_mode_raw(void)
{
  tcgetattr(STDIN_FILENO, &termopts.original);

  termopts.modified = termopts.original;

  // Input flags
  //
  // BRKINT
  // * Interrupt on BREAK signal (ignores BREAK if cleared)
  // * Disable to prevent random break signals
  //   from interrupting input
  //
  // ICRNL
  // * Automatically converts CR (Carriage Return, \r)
  //   to NL (New Line, \n)
  // * Disable to accurately read raw keys
  //   (e.g. to distinguish Enter from Ctrl+M)
  //
  // INPCK
  // * Enables parity checking of incoming data
  // * Games don't need parity checking, it's redundant
  //
  // ISTRIP
  // * Trims the 8th bit of characters (leaving only 7 bits)
  // * Disable to support Unicode and special keys
  //
  // IXON
  // * Enables flow control via Ctrl+S (stop) and Ctrl+Q (continue)
  // * Disable to prevent Ctrl+S combinations from locking the game

  termopts.modified.c_iflag &=
    ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);

  // Output flags
  //
  // OPOST
  // * Enables output post-processing (e.g. converting \n to \r\n)
  // * Disable for maximum output speed
  //   and direct cursor control via ANSI codes

  termopts.modified.c_oflag &= ~(OPOST);

  // Local flags
  //
  // ECHO
  // * Displays entered characters on the screen
  // * Disable to prevent keys from being "echoed" in the terminal
  //   (critical for games)
  //
  // ICANON
  // * Enables canonical mode (line-by-line input)
  // * Disable to immediately read keys without waiting for Enter
  //
  // IEXTEN
  // * Enables extended input processing (e.g. Ctrl+V for paste)
  // * Disable to prevent special combinations
  //   from interfering with game control
  //
  // ISIG
  // * Enables response to signals
  //   (Ctrl+C → SIGINT, Ctrl+Z → SIGTSTP)
  // * Disable to prevent the player
  //   from accidentally ending the game with combinations

  termopts.modified.c_lflag &= ~(ICANON | ECHO | IEXTEN); // ISIG?

  // Control chars
  //
  // VMIN = 0
  // * Minimum number of characters to read
  // * read() will return immediately even if there is no data
  //
  // VTIME = 0
  // * Input wait time (in tenths of a second)
  // * Return immediately from read() without blocking

  termopts.modified.c_cc[VMIN]  = 0;
  termopts.modified.c_cc[VTIME] = 0;

  tcsetattr(STDIN_FILENO, TCSAFLUSH, &termopts.modified);

  cursor_hide();
  clear_screen();
}

void stty_restore(void)
{
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &termopts.original);
  clear_screen();
  cursor_show();
}

