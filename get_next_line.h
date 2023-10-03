/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 09:25:40 by mehmeyil          #+#    #+#             */
/*   Updated: 2023/10/03 16:30:02 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include <stdio.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
# endif

size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *string1, char *string2);
char	*ft_firstline(char *firstline);
char	*ft_secondline(char *secondline);
char	*firsread(int fd, char *s);
char	*get_next_line(int fd);

#endif
