#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"


int main(void)
{
    int fd = open("test", O_RDONLY);
    int i = 0;
    char *line;

    if (fd < 0)
    {
        perror("open failed");
        return 1;
    }

    while (i < 10759)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        printf("%s", line);
        free(line);
        i++;
    }

    close(fd);
    return 0;
}