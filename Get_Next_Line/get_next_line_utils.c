/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanana <mzanana@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:07:17 by mzanana           #+#    #+#             */
/*   Updated: 2025/01/24 21:07:19 by mzanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int     ft_strlen(char *str)
{
    int     i;

    if (!str)
        return (0);
    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_substr(char *src, int from, int to, int flag)
{
    char    *ret;
    int     i;
    int     length;

    length = to - from;
    ret = malloc (sizeof(char) * (length + 1));
    if (!ret)
        return (free (src), NULL);
    i = 0;
    while (i < length)
    {
        ret[i] = src[i + from];
        i++;
    }
    ret [i] = '\0';
    if (flag)
        free(src);
    return (ret);
}

char    *ft_strncpy(char *dst, char *src, int n)
{
    int i;

    i = 0;
    while (i < n && src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}

char    *ft_strchr(char *src, size_t *ptr)
{
    if (!src)
        return (0);
    *ptr = 0;
    while (src[(*ptr)])
    {
        if (src[(*ptr)] == '\n')
            return (1);
        (*ptr)++;
    }
    return (0);
}

