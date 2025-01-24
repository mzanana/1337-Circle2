/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanana <mzanana@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:52:30 by mzanana           #+#    #+#             */
/*   Updated: 2025/01/24 20:52:31 by mzanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char        *buffer;
    static char *box;
    ssize_t     readret;
    ssize_t     checkpoint;

    buffer = NULL;
    while (1)
    {
        buffer = malloc (sizeof(char) * (ssize_t)BUFFER_SIZE + 1);
        if (fd < 0 || BUFFER_SIZE <= 0 || !buffer)
            return (free (buffer), free (box), box = NULL, NULL);
        readret = read (fd, buffer, BUFFER_SIZE);
        if (readret == -1)
            return (free (buffer), free (box), box = NULL, NULL);
        buffer[readret] = '\0';
        box = ft_strjoin (box, buffer);
        if (ft_strchr(box, &checkpoint))
        {
            buffer = ft_substr(box, 0, checkpoint, 0);
            box = ft_strncpy(box, box + checkpoint, ft_strlen(box + checkpoint));
            return (buffer);
        }
    }
}
