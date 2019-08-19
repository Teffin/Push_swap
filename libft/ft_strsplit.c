/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:49:05 by hharrold          #+#    #+#             */
/*   Updated: 2018/12/03 20:01:52 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_blen(char const *s, char c)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (s[a] != '\0')
	{
		if (s[a] != c)
			b++;
		while (s[a] != c && s[a] != '\0')
			a++;
		while (s[a] == c & s[a] != '\0')
			a++;
	}
	return (b);
}

static int	ft_len_word(char const *str, char c)
{
	int		i;

	i = 0;
	while (*str != c && *str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

static void	ft_strcopy(char *str, char const *s, char c)
{
	while (*s != c && *s != '\0')
	{
		*str = *s;
		str++;
		s++;
	}
	*str = '\0';
}

char		**ft_strsplit(char const *av, char c)
{
	int		a;
	int		words;
	char	**str;

	if (!av)
		return (NULL);
	words = ft_blen(av, c) + 1;
	if (!(str = (char**)malloc(sizeof(char*) * (words))))
		return (NULL);
	a = 0;
	while (words-- > 0)
	{
		while (*av == c && *av != '\0')
			av++;
		if (*av == '\0')
			break ;
		if (!(str[a] = (char*)malloc(sizeof(char) * ft_len_word(av, c) + 1)))
			return (ft_split_free(str));
		ft_strcopy(str[a++], av, c);
		while (*av != c && *av != '\0')
			av++;
	}
	str[a] = NULL;
	return (str);
}
