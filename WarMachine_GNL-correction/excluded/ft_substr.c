/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:26:45 by gomandam          #+#    #+#             */
/*   Updated: 2025/01/06 15:58:49 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		res = malloc(sizeof(char) * (1));
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (start < ft_strlen(s) && i < len && s[start])
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{	
		printf("RTFM! ft_substr(array, #start, #length)\n");
		printf("Usage: %s <string> <start> <length>\n", argv[0]);
		return (0);
	}

	char		*result;
	unsigned int	start;
	size_t		length;
	
	start = (unsigned int)atoi(argv[2]);
	length = (size_t)atoi(argv[3]);
	result = ft_substr(argv[1], start, length);
	printf("%s", result);
	free(result);
}
