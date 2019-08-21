/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 20:10:42 by hharrold          #+#    #+#             */
/*   Updated: 2019/08/08 20:10:44 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_pars_flags(char c, t_push *nums)
{
	if (c == 'v')
		nums->flag_visual = 1;
	else if (c == 'j')
		nums->flag_j = 1;
	else if (c == '-')
		nums->end_flag = 1;
	else if (c == 'd')
		nums->flag_sleep_mode = 100;
	else if (c == 's')
		nums->flag_score = 1;
	else if (c == 't')
		nums->checker = 1;
	else
		return (0);
	return (1);
}

int				ft_check_flag(char *av, t_push *nums)
{
	int		i;

	i = 0;
	if (av[i] == '-')
	{
		++i;
		if (av[i])
		{
			while (av[i] != '\0')
			{
				if (ft_pars_flags(av[i], nums))
					++i;
				else
					return (0);
			}
			return (1);
		}
	}
	return (0);
}
