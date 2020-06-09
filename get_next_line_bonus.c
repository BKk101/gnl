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

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int		my_gnl(int fd, char **line, t_buf *list)
{
	char	*str;
	char	*move_pos;
	int		byte;

	byte = 1;
	str = ft_strjoin(ft_memset(malloc(1), 0, 1), list[fd].remain);
	ft_memset(list[fd].remain, 0, BUFFER_SIZE);
	while (ft_strchr(str, '\n') == 0 && byte > 0)
	{
		byte = read(fd, list[fd].buf, BUFFER_SIZE);
		str = ft_strjoin(str, list[fd].buf);
		ft_memset(list[fd].buf, 0, BUFFER_SIZE);
	}
	if (ft_strchr(str, '\n') != 0)
	{
		*line = ft_strdup(str, ft_strchr(str, '\n') - str);
		move_pos = ft_strchr(str, '\n') + 1;
		ft_memmove(list[fd].remain, move_pos,
		ft_strlen(str) - (move_pos - str));
	}
	else
		*line = ft_strdup(str, ft_strlen(str));
	free(str);
	return (byte);
}

int		get_next_line(int fd, char **line)
{
	static t_buf	buf_list[2000];
	int				rtn;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	rtn = my_gnl(fd, line, buf_list);
	if (rtn == 0)
		return (0);
	else if (rtn == -1)
		return (-1);
	else
		return (1);
}
