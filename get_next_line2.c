/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 16:36:56 by bykim             #+#    #+#             */
/*   Updated: 2020/06/02 19:20:23 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 2

typedef struct  s_buf{
    char        buf[BUFFER_SIZE];
    char        c;
    char        remain[BUFFER_SIZE];
}               t_buf;

size_t  ft_strlen(const char *s)
{
    size_t len;

    len = 0;
    while (s[len])
        len++;
    return (len);
}

int get_next_line(int fd, char **line)
{
    static t_buf buf_list[2000] = {{0, 0, 0},};
    char *str;
    char *move_pos;
    int num;
    
    num = -1;
    str = ft_strjoin(buf_list[fd].remain, "");
    while (ft_strchr(str, '\n') == 0 && num != 0)
    {
        num = read(fd, buf_list[fd].buf, BUFFER_SIZE);
        str = ft_strjoin(str, buf_list[fd].buf);
    }
    if (ft_strchr(str, '\n') != 0)
    {
        *line = ft_strdup(str, ft_strchr(str, '\n') - str);
        move_pos = ft_strchr(buf_list[fd].buf, '\n') + 1;
        ft_memmove(buf_list[fd].remain, move_pos, BUFFER_SIZE - (move_pos - buf_list[fd].buf));
        ft_memset(buf_list[fd].buf, 0, BUFFER_SIZE);
    }
    else
        *line = ft_strdup(str, ft_strlen(str));
    free(str);
    if (num == 0)
        return (0);
    else
        return (1);
}