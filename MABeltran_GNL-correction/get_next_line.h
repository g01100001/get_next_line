/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:03:51 by gomandam          #+#    #+#             */
/*   Updated: 2025/01/07 22:41:54 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> //free
# include <stdlib.h> //main arguments, malloc, calloc
# include <fcntl.h> //open, read
# include <stdio.h> //printf

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20

# endif

//get_next_line function
char	*get_next_line(int fd);

//utilities

size_t	ft_strlen(char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strrchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	ft_free(char **str);

#endif
