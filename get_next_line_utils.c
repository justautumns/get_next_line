/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:57:18 by mehmeyil          #+#    #+#             */
/*   Updated: 2023/10/03 16:30:47 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
size_t	ft_strlen(char *str)
{
	size_t	m;

	m = 0;
	if(!str)
		return (0);
	while (str[m] != '\0')
		m++;
	return (m);
}

char	*ft_strjoin(char *string1, char *string2)
{
	size_t	n;
	size_t	k;
	char	*ptr;
	size_t	len;

	if (!string1)
	{
		string1 = (char *) malloc(1 * sizeof(char));
		if (!string1)
			return (NULL);
		string1[0] = '\0';
	}
	if (!string1 || !string2)
		return (NULL);
	len = ft_strlen(string1) + ft_strlen(string2) + 1;
	ptr = malloc (sizeof(char) * len);
	if (!ptr)
		return (NULL);
	n = 0;
	k = 0;
	if (string1)
	{
		while (string1[n] != '\0')
		{
			ptr[n] = string1[n];
			n++;
		}
	}
	while (string2[k] != '\0')
	{
		ptr[n] = string2[k];
		n++;
		k++;
	}
	ptr[len - 1] = '\0';
	free(string1);
	return (ptr);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!c)
		return ((char *)s);
	while (s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}

char	*ft_firstline(char *firstline)
{
	int		z;
	int		i;
	char	*ptr;

	z = 0;
	if (!firstline)
		return (NULL);
	while (firstline[z] && firstline[z] != '\n')
		z++;
	ptr = (char *) malloc (sizeof(char) * (z + 2));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < z + 1)
	{
		ptr[i] = firstline[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_secondline(char *secondline)
{
	int		k;
	int		l;
	char	*ptr;
	size_t	len;

	k = 0;
	while (secondline[k] && secondline[k] != '\n')
		k++;
	if (!secondline[k])
		free(secondline);
		return (NULL);
	len = ft_strlen(secondline);
	ptr = (char *) malloc(sizeof(char) * (len - k + 1));
	if (!ptr)
		return (NULL);
	k++;
	l = 0;
	while (secondline[k])
	{
		ptr[l++] = secondline[k++];
	}
	ptr[l] = '\0';
	free(secondline);
	return (ptr);
}

/*int	main(void)
{
	char *s1 = "Hello blabla";
	char *s2 = "blabla";
	int m = ' ';
	char *ema;
	char deneme[] = "hello world         \n";
	char deneme1[] = "deneme yapiyorum \n deneme deneme";

	// ema = ft_strjoin(s1, s2);
	// printf("%ld\n", ft_strlen(s1));
	// printf("%s\n", ema);
	// free(ema);
	//printf("%s\n", ft_strchr(s1, m));
	printf("%s\n", ft_firstline(deneme));
	//free(s1);

	return (0);
}*/
