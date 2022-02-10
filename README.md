# get_next_line
The aim of this project is to make you code a function that returns a line, read from a file descriptor.

※ In this repository, Mandatory part and Bonus part have the same implementation.

## Usage

Compile with BUFFER_SIZE as shown below.

The file is read per BUFFER_SIZE.

```bash
$ gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c -I. -D BUFFER_SIZE=<buffer_size>
```

Pass a file descriptor to get_next_line, and you can get one line from that file.

If you pass an invalid file descriptor or read the file to the end, NULL will be returned.

Even if you pass multiple file descriptors alternately, you can get one line of the corresponding file properly.

```c
fd = open("<file_path>", O_RDONLY);
line = get_next_line(fd);  // Return first line
line = get_next_line(fd);  // Return second line
```

## Example

Use the following two text files.

```plainText:text1.txt
/* text1.txt */
Hello!!
How are you?
Bye :D
```

```plainText:text2.txt
/* text2.txt */
Apple
Lemon
Grape
```

**Single file ver**
```c
int main(void)
{
  int   i;
  int   fd;
  char  *line;
  
  i = 0;
  fd = open("text1.txt", O_RDONLY);
  while (1)
  {
    line = get_next_line(fd);
    if (line == NULL)
      break ;
    printf("%d: %s", i, line);
    free(line);
    i++;
  }
  return (0);
}
```

The output looks like this.
```plainText
0: /* text1.txt */
1: Hello!!
2: How are you?
3: Bye :D
```

**Multiple files ver**
```c
int main(void)
{
  int   i;
  int   fd1;
  int   fd2;
  char  *line;
  
  i = 0;
  fd1 = open("text1.txt", O_RDONLY);
  fd2 = open("text2.txt", O_RDONLY);
  while (1)
  {
    if (i % 2 == 0)
      line = get_next_line(fd1);
    else
      line = get_next_line(fd2);
    if (line == NULL)
      break ;
    printf("%d: %s", i, line);
    free(line);
    i++;
  }
  return (0);
}
```

The output looks like this.
```plainText
0: /* text1.txt */
1: /* text2.txt */
2: Hello!!
3: Apple
4: How are you?
5: Lemon
6: Bye :D
7: Grape
```
