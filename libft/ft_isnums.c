/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnums.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:11:37 by hharrold          #+#    #+#             */
/*   Updated: 2019/04/30 16:11:40 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isnums(char *av)
{
	int		i;

	i = 0;
	while (av[i] != '\0')
	{
		if (ft_isdigit(av[i]) || (i == 0 && av[i] == '-'))
			++i;
		else
			return (0);
	}
	return (1);
}
