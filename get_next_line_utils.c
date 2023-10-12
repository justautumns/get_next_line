/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:01:17 by mehmeyil          #+#    #+#             */
/*   Updated: 2023/10/12 20:22:48 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	m;

	m = 0;
	if (!str)
		return (0);
	while (str[m] != '\0')
		m++;
	return (m);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		k;
	int		m;
	char	*ptr;

	if (!str1)
	{
		str1 = (char *) malloc(sizeof(char) * 1);
		if (!str1 || !str2)
			return (NULL);
		str1[0] = '\0';
	}
	ptr = (char *) malloc (sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!ptr)
		return (NULL);
	k = -1;
	m = 0;
	while (str1[++k])
		ptr[k] = str1[k];
	while (str2[m])
		ptr[k++] = str2[m++];
	ptr[k] = '\0';
	free(str1);
	return (ptr);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != (unsigned char)c && s[i] != '\0')
		i++;
	if (s[i] == (unsigned char)c)
		return (1);
	else
		return (0);
}

char	*ft_firstline(char *firstline)
{
	int		z;
	int		i;
	char	*ptr;

	z = 0;
	if (firstline[z] == '\0')
		return (NULL);
	while (firstline[z] != '\0' && firstline[z] != '\n')
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
	int		m;
	char	*ptr;

	k = 0;
	if (secondline[k] == '\0')
	{
		free(secondline);
		return (NULL);
	}
	while (secondline[k] != '\0' && secondline[k] != '\n')
		k++;
	ptr = (char *) malloc(sizeof(char) * (ft_strlen(secondline) + 1));
	if (!ptr)
		return (NULL);
	if (secondline[k] == '\n')
		k++;
	m = 0;
	while (secondline[k] != '\0')
	{
		ptr[m++] = secondline[k++];
	}
	ptr[m] = '\0';
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
	char deneme1[] = "\n deneme";

	 ema = ft_strjoin(s1, s2);
	// printf("%ld\n", ft_strlen(s1));
	// printf("%s\n", ema);
	// free(ema);
	//printf("%s\n", ft_strchr(s1, m));
	printf("%s\n", ft_secondline(deneme1));
	//printf("%s\n", ft_firstline(deneme));
	//free(s1);

	return (0);
}*/
