/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:09:25 by gomandam          #+#    #+#             */
/*   Updated: 2025/01/06 15:55:38 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0' && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (0);
}
char    *ft_strrchr(char *s, int c)
{
        int     len;

        len = ft_strlen(s);
        while (len >= 0)
        {
                if (s[len] == (unsigned char)c)
                        return ((char *)s);
                len--;
        }
        return (0);
}

/*
int	main(void)
{
	char	character = '\n';
	char	string[] = "Test for searching a \n newline character.";
	char	*result;

	result = ft_strchr(string, character);
	printf("%s\n", result);
} */
/*
char *ft_strchr(const char *s, int c)
{
    while (*s != '\0')  	     //Iterate with the pointer itself.
    {
        if (*s == (char)c)  	     //If character is found, return pointer
            return ((char *)s);
        s++;  			     //Move pointer to the next character
    }
    return (0);  		     //Return null if no found character
}
*/

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Invalid sequence.\n");
		printf("RTFM! ft_strchr\n");
		return (0);
	}

	char	character = argv[1][0]; //Accesses index 0 of 1st argument
	char	*string = argv[2];
	char	*result;

	result = ft_strchr(string, character);
	printf("%s\n", result);
	return (0);
}
