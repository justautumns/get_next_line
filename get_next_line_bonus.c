/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:37:42 by mehmeyil          #+#    #+#             */
/*   Updated: 2023/10/13 20:21:19 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*firsread(int fd, char *s)
{
	int		n;
	char	*tmp;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	n = 1;
	while (ft_strchr(s, '\n') == 0 && n > 0)
	{
		n = read(fd, tmp, BUFFER_SIZE);
		if (n == -1)
		{
			free (tmp);
			if (s)
				free(s);
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
	static char		*ptr[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ptr[fd] = firsread(fd, ptr[fd]);
	if (ptr[fd] == NULL)
		return (NULL);
	x = ft_firstline(ptr[fd]);
	ptr[fd] = ft_secondline(ptr[fd]);
	return (x);
}
/*int	main(void)
{
	char	*omg;
	int	n;


	n = open("test.txt", O_RDONLY);
	omg = get_next_line(n);
	printf("%s", omg);
	omg = get_next_line(n);
	printf("%s", omg);
	omg = get_next_line(n);
	printf("%s", omg);
	omg = get_next_line(n);
	printf("%s", omg);
	omg = get_next_line(n);
	printf("%s", omg);
	omg = get_next_line(n);
	printf("%s", omg);
	omg = get_next_line(n);
	printf("%s", omg);
	free(omg);
	close(n);
	return (0);
}*/
