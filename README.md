# get_next_line ⏭️​

`get_next_line` is a C function project that allows reading a file line by line.  
It handles multiple file descriptors simultaneously and returns each line of a file including the newline character (`\n`).

---

## Contents

- Features
- Installation
- Usage
- Examples
- Contributions
- License

---

## Features

- Reads a file **line by line**.
- Works with **multiple file descriptors** at the same time.
- Returns **each line including the newline character**.
- Handles **end-of-file** and **errors** gracefully.
- Memory is managed properly to avoid leaks.

---

## Installation

1. Clone the repository:

```bash
git clone https://github.com/dajose-p/get_next_line.git
cd get_next_line
```

---

## Usage

Compile the .c files as it is shown:

```bash
cc -D BUFFER_SIZE=<size_of_buffer> get_next_line.c get_next_line_utils.c -o my_program
cc -D BUFFER_SIZE=<size_of_buffer> get_next_line_bonus.c get_next_line_utils_bonus.c -o my_program
```

Call the function:

```c
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

---

## Examples

Example `main.c`:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    if (fd == -1)
        return 1;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

Expected output (for `example.txt` containing three lines):

```text
First line
Second line
Third line
```

---

## Contributing

This project is primarily for personal use in **42 school** projects.  
Contributions are welcome in the form of suggestions or improvements for function implementations.

---
