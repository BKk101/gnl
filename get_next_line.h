/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:01:54 by bykim             #+#    #+#             */
/*   Updated: 2020/03/15 22:10:43 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

int     get_next_line(int fd, char **line);
char    *ft_strchr(const char *s, int c);
char    *ft_strjoin(char *s1, char const *s2);
char	*ft_strdup(const char *src, int byte);
void    *ft_memset(void *s, int c, size_t n);
size_t  ft_strlen(const char *s);

#endif