/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:02:37 by dshirais          #+#    #+#             */
/*   Updated: 2025/10/13 14:46:09 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(char const *s, char c)
{
	int	i;

	if (*s == '\0')
		return (0);
	i = 1;
	while (*s)
	{
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
		if (*s)
		{
			i++;
			s++;
		}
	}
	return (i);
}

static void	ft_free(char **arr_str, int num)
{
	while (num >= 0)
	{
		free(arr_str[num]);
		num--;
	}
	free(arr_str);
}

static char	**makestr(int size, char *str, char c, char **arr_str)
{
	int		num;
	size_t	i;

	num = 0;
	while (num < size)
	{
		i = 0;
		while (str[i] && str[i] != c)
			i++;
		arr_str[num] = (char *)malloc(sizeof(char) * (i + 1));
		if (!arr_str[num])
		{
			ft_free(arr_str, num - 1);
			return (NULL);
		}
		ft_memcpy(arr_str[num], str, i);
		arr_str[num][i] = '\0';
		str = str + i;
		while (*str && *str == c)
			str++;
		num++;
	}
	arr_str[num] = NULL;
	return (arr_str);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	int		size;
	char	**arr_str;

	str = ft_strtrim(s, &c);
	size = count_size(str, c);
	arr_str = (char **)malloc(sizeof(char *) * (size + 1));
	if (!arr_str)
		return (NULL);
	if (size == 0)
	{
		arr_str[0] = NULL;
		free(str);
		return (arr_str);
	}
	arr_str = makestr(size, str, c, arr_str);
	free(str);
	return (arr_str);
}
// #include <stdio.h>
// #include <stdlib.h>
// #include "libft.h"

// int main(void)
// {
// 	char **tab = ft_split("apple", ' ');
// 	if (!tab)
// 		return 1;

// 	for (int i = 0; tab[i]; i++)
// 		printf("tab[%d] = \"%s\"\n", i, tab[i]);

// 	// Free memory
// 	for (int i = 0; tab[i]; i++)
// 		free(tab[i]);
// 	free(tab);
// 	return 0;
// }