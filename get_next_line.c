/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:03:41 by bykim             #+#    #+#             */
/*   Updated: 2020/03/15 23:16:43 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 2
#define STORAGE_SIZE 1000

int get_next_line(int fd, char **line)
{
    static char buf[BUFFER_SIZE] = {0};
    static char storage[STORAGE_SIZE] = {0}; //? 저장할게 엄청 길면 어떡하지?
    char *end;
    char *temp;
    int idx;
    int num;
    
    //buf[17]='a';
    temp = ft_strdup("", 0);
    if (ft_strlen(storage) != 0)
        temp = ft_strjoin(temp, storage);
    while(ft_strchr(buf, '\n') == 0)
    {
        if (ft_strchr(storage, '\n') == 0)
        {
            num = read(fd, buf, BUFFER_SIZE);
            temp = ft_strjoin(temp, buf);
        }
        if((end = ft_strchr(temp, '\n')) != 0 || num == 0) //읽어서 개행 포함
        {
            if (num == 0)
                end = ft_strchr(temp, '\0');
            *line = ft_strdup(temp, end - temp + 1); //free 여부?
            if (end - temp + 1 < BUFFER_SIZE) //개행 뒤에 남은거 저장 최대 길이 BUFFER_SIZE -1 //temp 길이가 맞나?
            {
                idx = 0;
                ft_memset(storage, 0, STORAGE_SIZE);
                while (*(++end) != '\0')
                    storage[idx++] = *end;
                storage[idx] = 0;
                break;
            }
        }
    }
    ft_memset(buf, 0, BUFFER_SIZE); //초기화 함수 만들어도될듯
    free(temp);
    if (num == 0)
        return (0);
    return (1);//에러인 경우 추가
}

int main()
{
    int fd, num;
    char *str1;
    char str[100];

    num = 1;
    fd = open("test.txt", O_RDONLY);
    while (num)
    {
        num = get_next_line(fd, &str1);
        printf("%d %s\n", num, str1);
    }
    return 0;
}