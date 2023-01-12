# Logging
This piece of code allows you to print errors in color to help them stand out, even on Windows.

## Usage
  - Include `logging.h`
  - Add `logging.c` to your source file list or otherwise add it to your compiler setup
  - Call `log_error()`, ANSI color codes will be automatically enabled if necessary
  
`log_error()` functions identically to `printf()`, except that you need to pass in an enum value to indicate what color your message should be prefixed with.
 
## Examples:
 
```c
#include "logging.h"

int main() {
    unsigned int size = 1024;
    char* buffer = malloc(size);
    if (buffer == NULL)
    {
      log_error(CRITICAL, "Couldn't allocate the buffer with size %d!\n", size);
    }
    else
    {
      log_error(DEBUG, "Allocated %d bytes of memory.\n", size);
      unsigned int result = some_function(buffer);
      if (result > 0)
      {
        log_error(WARNING, "Potential error operating on a buffer in main()\n");
      }
      unsigned int texture_count = 10;
      unsigned int model_count = 5;
      log_error(INFO, "Reporting to the user: found %d textures and %d models in this file.\n", texture_count, model_count);
      free(buffer);
      log_error(DEBUG, "Freed %d bytes of memory.\n", size);
    }
    return 0;
}
```

![2023-01-08_23_09_56](https://user-images.githubusercontent.com/73564623/211961389-9d0b93fc-b6b2-4093-9346-3c571a54940b.png)
![2023-01-11 21_29_02](https://user-images.githubusercontent.com/73564623/211961738-4f14f286-79b5-407a-a21c-e04966bd99be.png)
![2023-01-11 21_29_48](https://user-images.githubusercontent.com/73564623/211961739-ae084409-28e8-4061-9fb8-d9aea3a61e81.png)
