/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:04:53 by bykim             #+#    #+#             */
/*   Updated: 2020/04/13 18:27:46 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    size_t len;

    len = 0;
    while (s[len])
        len++;
    return (len);
}

char    *ft_strchr(const char *s, int c)
{
    char *ptr;

    ptr = (char *)s;
    while (*ptr)
    {
        if (*ptr == (unsigned char)c)
            return (ptr);
        ptr++;
    }
    if (c == 0)
        return (ptr);
    return (0);
}

char	*ft_strdup(const char *src, int len)
{
	char *ptr;

	if ((ptr = (char *)malloc(len + 1)) == 0)
		return (0);
	ptr[len] = 0;
	while (--len >= 0)
		ptr[len] = src[len];
	return (ptr);
}

void    *ft_memset(void *s, int c, size_t n)
{
    unsigned char   *temp;
    unsigned long   idx;

    temp = (unsigned char *)s;
    idx = 0;
    while (idx < n)
        temp[idx++] = (unsigned char)c;
    return (s);
}

char	*ft_strjoin(char *s1, char const *s2)
{
    char	*temp;
	char    *res;
    int		len;
	int		num;

	len = 0;
	while (s1[len])
		len++;
	num = 0;
    while (s2[num++])
		len++;
    if ((res = (char *)malloc(len + 1)) == 0)
        return (0);
	temp = res;
	num = 0;
	while (s1[num] != '\0')
		*temp++ = s1[num++];
	while (*s2 != '\0')
		*temp++ = *s2++;
	*temp = 0;
	free(s1);
	return (res);
}