
// file: stty.c

#include "stty.h"

t_stty termopts = { 0 };

void stty_flush_input(void)
{
  tcflush(STDIN_FILENO, TCIFLUSH);
}

void stty_frame_rate(int rate)
{
  tcgetattr(STDIN_FILENO, &termopts.original);

  termopts.modified = termopts.original;

  termopts.modified.c_lflag &= ~(ICANON | ECHO);
  termopts.modified.c_cc[VMIN] = UCHAR_MAX;
  termopts.modified.c_cc[VTIME] = rate;

  tcsetattr(STDIN_FILENO, TCSAFLUSH, &termopts.modified);

  cursor_hide();

  // clear screan
  erase_display(ERASE_ALL);
  select_graphic_rendition(0);
  cursor_position(0, 0);
}

void stty_mode_raw(void)
{
  tcgetattr(STDIN_FILENO, &termopts.original);
  termopts.modified = termopts.original;

  // Input flags
  //
  // BRKINT
  // * Прерывание при получении сигнала BREAK (если очищен - игнорирует BREAK)
  // * Отключаем, чтобы случайные break-сигналы не прерывали ввод
  //
  // ICRNL
  // * Автоматически преобразует CR (Carriage Return, \r) в NL (New Line, \n)
  // * Отключаем для точного чтения сырых клавиш (например, чтобы различать Enter и Ctrl+M)
  //
  // INPCK
  // * Включает проверку четности входящих данных
  // * Играм не нужна проверка четности, это избыточно
  //
  // ISTRIP
  // * Обрезает 8-й бит символов (оставляет только 7 бит)
  // * Отключаем для поддержки Unicode и специальных клавиш
  //
  // IXON
  // * Включает управление потоком через Ctrl+S (остановка) и Ctrl+Q (продолжение)
  // * Отключаем, чтобы комбинации Ctrl+S не блокировали игру

  termopts.modified.c_iflag &=
    ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);

  // Output flags
  //
  // OPOST
  // * Включает постобработку вывода (например, преобразование \n в \r\n)
  // * Отключаем для максимальной скорости вывода и прямого управления курсором через ANSI-коды

  termopts.modified.c_oflag &= ~(OPOST);

  // Local flags
  //
  // ECHO
  // * Отображает введенные символы на экране
  // * Отключаем, чтобы клавиши не "эхоировались" в терминале (критично для игр)
  //
  // ICANON
  // * Включает канонический режим (построчный ввод)
  // * Откючаем для немедленного чтения клавиш без ожидания Enter
  //
  // IEXTEN
  // * Включает расширенную обработку ввода (например, Ctrl+V для вставки)
  // * Отключаем, чтобы специальные комбинации не мешали управлению игрой
  //
  // ISIG
  // * Включает реакцию на сигналы (Ctrl+C → SIGINT, Ctrl+Z → SIGTSTP)
  // * Отключаем, чтобы игрок случайно не завершил игру комбинациями

  termopts.modified.c_lflag &= ~(ICANON | ECHO | IEXTEN); // ISIG?

  // Control chars
  //
  // VMIN = 0
  // * Минимальное количество символов для чтения
  // * read() будет возвращаться сразу, даже если нет данных
  //
  // VTIME = 0
  // * Время ожидания ввода (в десятых долях секунды)
  // * Немедленный возврат из read() без блокировки

  termopts.modified.c_cc[VMIN] = 0;
  termopts.modified.c_cc[VTIME] = 0;

  tcsetattr(STDIN_FILENO, TCSAFLUSH, &termopts.modified);
}

void stty_restore(void)
{
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &termopts.original);

  // clear screan
  erase_display(ERASE_ALL);
  select_graphic_rendition(0);
  cursor_position(0, 0);

  cursor_show();
}

