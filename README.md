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
git clone https://github.com/your_username/get_next_line.git
cd get_next_line
```

2. Compile the library:

```bash
make
```

This will generate `libftgnl.a` (if you created a library) or object files for linking.

---

## Usage

Include the header in your project:

```c
#include "get_next_line.h"
```

Compile your program with the library:

```bash
cc main.c -L. -lftgnl -o my_program
```

Or compile directly with the object files:

```bash
cc main.c get_next_line.c -o my_program
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
