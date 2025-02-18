/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:02:04 by gomandam          #+#    #+#             */
/*   Updated: 2025/01/08 18:20:10 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

char	*ft_get_buffer(int fd, char **buffer)
{
	char	*buff;
	int		readx;

	if (!*buffer)
		*buffer = ft_calloc(sizeof(char), 1);
	if (!*buffer)
		return (NULL);
	buff = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buff)
		return (ft_free(buffer), NULL);
	readx = 1;
	while (!ft_strrchr(buff, '\n') && readx != 0)
	{
		readx = read(fd, buff, BUFFER_SIZE);
		if (readx == -1)
			return (ft_free(buffer), ft_free(&buff), NULL);
		if (readx > 0)
		{
			buff[readx] = '\0';
			*buffer = ft_strjoin(*buffer, buff);
			if (!*buffer)
				return (ft_free(&buff), NULL);
		}
	}
	return (ft_free(&buff), *buffer);
}

char	*ft_get_line(char **buffer)
{
	char	*line;
	int		i;

	if (!(*buffer)[0])
		return (NULL);
	i = 0;
	while ((*buffer)[i] != '\0' && (*buffer)[i] != '\n')
		i++;
	line = ft_substr(*buffer, 0, i + 1);
	if (!line)
		return (ft_free(buffer), NULL);
	if ((*buffer)[i] == '\n')
		line[i] = (*buffer)[i];
	return (line);
}

char	*ft_get_clean(char **buffer)
{
	char	*aux;
	int		i;

	i = 0;
	while ((*buffer)[i] != '\n' && (*buffer)[i] != '\0')
		i++;
	if (!(*buffer)[i])
		return (ft_free(buffer), NULL);
	aux = ft_substr(*buffer, i + 1, ft_strlen(*buffer));
	return (ft_free(buffer), aux);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = ft_get_buffer(fd, &buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(&buffer);
	buffer = ft_get_clean(&buffer);
	return (line);
}
#include "get_next_line.h"

int	main()
{
	int	fd = open("file.txt", O_RDONLY | O_CREAT, 0644);
	char	*line;

	if (fd == -1)
	{
		printf("Error. Not archived.");
		return (0);
	}
	line = get_next_line(0);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}