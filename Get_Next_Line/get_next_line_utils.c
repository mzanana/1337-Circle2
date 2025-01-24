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

char    *ft_strjoin(char *origin, char *added)
{
    char    *ret;
    int     orlen;
    int     adlen;

    adlen = ft_strlen(added);
    orlen = ft_strlen(origin);
    if (!adlen && !orlen)
        return (free(origin), free(added), NULL);
    if (!orlen)
        return (free(origin), ft_substr(added, 0, adlen, 1));
    if(!adlen)
        return (free (added), ft_substr(origin, 0, orlen, 1));
    ret = malloc (sizeof (char) * (adlen + orlen + 1));
    if (!ret)
        return (free(origin), free(added), NULL);
    ft_strncpy (ret, origin, orlen);
    ft_strncpy (ret + orlen, added, adlen);
    free (origin);
    free (added);
    return (ret);
}