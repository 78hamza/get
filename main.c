# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

int main()
{
    int fd = open("file.txt", O_RDONLY);
    if (fd == -1)
        return (1);
    // char *pocket = get_next_line(fd);
    // printf("%s", pocket);
    char *res;
    for (int i = 0; i < 20; i++)
    {
        res = get_next_line(fd);
        printf("%s", res);
        free(res);
    }
    close(fd);
    return (0);
}