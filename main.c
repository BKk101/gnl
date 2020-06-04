#include "get_next_line.h"

int main()
{
    int fd, num;
    char *str1;
    char str[100];

    num = 1;
    //fd = open("/home/bykim/vscode/gnl/test.txt", O_RDONLY);
    fd = 0;
    while (num)
    {
        num = get_next_line(fd, &str1);
        printf("%d %s\n", num, str1);
    }
    return 0;
}