#pragma once

typedef enum print_type {
	INFO = 0,
	WARNING = 1,
	CRITICAL = 2, // "ERROR" was already taken on Windows
    DEBUG = 3
}print_type;

// These toggle an internal bool value, when false
// it makes all calls to log_error() inert.
void enable_logging();
void disable_logging();

// Usage is identical to printf(), except that you need to pass in a value
// from the above enum to control the color / text that prefixes your message
void log_error(print_type type, char* format_str, ...);
