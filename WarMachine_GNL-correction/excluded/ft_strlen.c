/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:59:37 by gomandam          #+#    #+#             */
/*   Updated: 2025/01/06 22:03:52 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/*
int	main(int argc, char *argv[])
{
	int	count;
	int	i;

	count = 0;
	i = 1;
	while (argc > i)
	{
		count = count + ft_strlen(argv[i]);
		i++;
	}
	printf("Total string counted for each arguments");
	printf(" excluding space: %d\n", count);
}
*/
/*
int     main(void)
{
        char    str[] = "count the string length.";
        int     length = ft_strlen(str);
        
        printf("%d\n", length);
}
*/
/*
Study the psuedo-code for GNL
Understand the libft functions to be used fpr GNL like
ft_bzero
calloc or malloc: OK
ft_strlen: OK
ft_strchr: OK
ft_strjoin: OK
ft_substr: OK
file descriptors: OK
*/
