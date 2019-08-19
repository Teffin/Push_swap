/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blockdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 18:15:17 by hharrold          #+#    #+#             */
/*   Updated: 2019/08/08 18:15:19 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			**ft_split_free(char **splt)
{
	int		i;

	i = 0;
	while (splt[i])
	{
		free(splt[i]);
		i++;
	}
	free(splt);
	return (NULL);
}
