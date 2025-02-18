/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:02:04 by gomandam          #+#    #+#             */
/*   Updated: 2025/01/28 02:56:30 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_buffer(int fd, char *buffer)
{
	char	*buff;
	int		readx;

	if (!buffer)
		buffer = ft_calloc(sizeof(char), 1);
	buff = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	readx = 1;
	while (!ft_strrchr(buff, '\n') && readx != 0)
	{
		readx = read(fd, buff, BUFFER_SIZE);
		if (readx == -1)
		{
			free(buff);
			free(buffer);
			return (NULL);
		}
		buff[readx] = '\0';
		buffer = ft_strjoin(buffer, buff);
	}
	free(buff);
	return (buffer);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	if (!buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = ft_substr(buffer, 0, i + 1);
	if (buffer[i] == '\n')
		line[i] = buffer[i];
	return (line);
}

char	*ft_get_clean(char *buffer)
{
	char	*aux;
	int		i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	aux = ft_substr(buffer, i + 1, ft_strlen(buffer));
	free(buffer);
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = ft_get_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_get_clean(buffer);
	return (line);
}

int	main()
{
	int	fd = open("file.txt", O_RDONLY | O_CREAT);
	char	*line;

	if (fd == -1)
	{
		printf("Error. Not archived.");
		return (0);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
