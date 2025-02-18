/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 22:14:09 by gomandam          #+#    #+#             */
/*   Updated: 2025/01/06 23:03:19 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	char    *line;
	int fd = open("file.txt", O_RDONLY | O_CREAT);
	// open returns an int datatype
	 
	if (fd == -1) 
	{
		printf("Error. File is not archived.");
		return (0);
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return(0);
}
