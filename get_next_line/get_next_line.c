/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:32:21 by qraymaek          #+#    #+#             */
/*   Updated: 2023/10/27 21:16:28 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buffer(int fd)
{
	char	*buff;

	buff = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buff)
		return (NULL);
	if (read(fd, buff, BUFFER_SIZE) < 0)
	{
		free(buff);
		return (NULL);
	}
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char	*buff;

	str = "";
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (found_newline(str) == 1)
	{
		buff = buffer(fd);
		if (!buff)
			return (NULL);
		str = ft_strjoin(str, buff);
		free(buff);
	}
	return (str);
}

#include <stdio.h>

int main()
{
    int fd;
    char *line;
    
	fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening the file");
        return 1;
    }
		line = get_next_line(fd);
        printf("Line: %s\n", line);
        free(line); // Don't forget to free the line after using it

    // Close the file
    close(fd);

    return 0;
}
