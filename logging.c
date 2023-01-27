#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

#include "logging.h"

#ifdef _WIN32
#include <Windows.h>

// Enables ANSI escape codes on Windows
unsigned short enable_win_ansi()
{
    DWORD prev_console_mode;
    HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    if (console_handle  != INVALID_HANDLE_VALUE) {
        GetConsoleMode(console_handle , (LPDWORD) &prev_console_mode);
        if (prev_console_mode != 0) {
            SetConsoleMode(console_handle , prev_console_mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING | ENABLE_PROCESSED_OUTPUT);
            return 1;
        }
    }
	return 0;
}
#endif

static bool printing_enabled = true;

void enable_logging()
{
	printing_enabled = true;
}

void disable_logging()
{
	printing_enabled = false;
}

void log_error(print_type type, char* format_str, ...)
{
    #ifdef _WIN32
	static unsigned short ansi_enabled = 0;
    if (ansi_enabled == 0)
    {
        ansi_enabled = enable_win_ansi();
    }
    #endif
	if (printing_enabled)
	{
		switch (type) {
		case INFO:
			printf("[\033[32mINFO\033[0m] "); // Green
			break;
		case WARNING:
			printf("[\033[33mWARNING\033[0m] "); // Yellow
			break;
		case CRITICAL:
			printf("[\033[31mCRITICAL\033[0m] "); // Red
			break;
		case DEBUG:
			printf("[\033[34mDEBUG\033[0m] "); // Blue
			break;
		}

		va_list arg_list;
		va_start(arg_list, format_str);
		vprintf(format_str, arg_list);
		va_end(arg_list);
	}
}
