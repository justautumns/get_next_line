/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:02:48 by mehmeyil          #+#    #+#             */
/*   Updated: 2023/10/03 17:20:20 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*firsread(int fd, char *s)
{
	int		n;
	char	*tmp;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	n = 1;
	while (!ft_strchr(s, '\n') && n != 0)
	{
		n = read(fd, tmp, BUFFER_SIZE);
		if (n == -1)
		{
			free (tmp);
			return (NULL);
		}
		tmp[n] = '\0';
		s = ft_strjoin(s, tmp);
	}
	free (tmp);
	return (s);
}
char	*get_next_line(int fd)
{
	char			*x;
	static	char 	*ptr;

	if (BUFFER_SIZE <= 0)
		return (0);
	if (fd < 0)
		return (0);
	ptr = firsread(fd, ptr);
	if (!ptr)
		return (NULL);
	x = ft_firstline(ptr);
	ptr = ft_secondline(ptr);

	return (x);
}

int	main(void)
{
	char	*omg;
	int	n;
	int k;

	n = open("test.txt", O_RDONLY);
	while ((omg = get_next_line(n)))
	{
		printf("%s", omg);
		free(omg);
	}
	close(n);
	return (0);
}
