#include "get_next_line.h"

int main()
{
	int fd1, num;
	char *str1;

	num = 1;
	fd1 = open("/home/bykim/vscode/gnl/test.txt", O_RDONLY);
	//fd2 = open("/home/bykim/vscode/gnl/test2.txt", O_RDONLY);
	while (num)
	{
		num = get_next_line(fd1, &str1);
		printf("%d %s\n", num, str1);
		//num = get_next_line(fd2, &str1);
		//printf("%d %s\n", num, str1);
	}
	return 0;
}