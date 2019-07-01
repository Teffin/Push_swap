/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 13:53:07 by hharrold          #+#    #+#             */
/*   Updated: 2019/04/29 13:53:09 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_pars_flags(char c, t_push *nums)
{
	if (c == 'v')
		nums->flag_v = 1;
	else if (c == 'j')
		nums->flag_j = 1;
	else if (c == '-')
		nums->end_flag = 1;
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

static int		ft_double_num(int num, t_push *nums)
{
	t_num		*temp;

	temp = nums->num_a;
	while (temp != NULL && temp->next != NULL)
	{
		if (temp->num == num)
			return (0);
		temp = temp->next;
	}
	return (1);
}

static int		ft_check_swap_write(char **splt_num, t_push *nums, int i)
{
	t_num		*temp;
	t_num		*temp1;

	temp1 = NULL;
	temp = nums->num_a;
	while (temp != NULL && temp->next != NULL)
		temp = temp->next;
	if (temp == NULL)
	{
		nums->num_a = ft_create_num();
		temp = nums->num_a;
	}
	else
	{
		temp->next = ft_create_num();
		temp1 = temp;
		temp = temp->next;
		temp->prev = temp1;
	}
	temp->len = ft_strlen(splt_num[i]);
	temp->num = ft_atoi(splt_num[i]);
	if (!ft_strequ(splt_num[i], ft_itoa(temp->num)) ||
								!ft_double_num(temp->num, nums))
		return (0);
	return (1);
}

int				ft_check_valid(char *av, t_push *nums)
{
	int			i;
	char		**splt_num;
	int			temp_len;

	i = 0;
	splt_num = ft_strsplit(av, ' ');
	while (splt_num[i] != NULL)
	{
		if (ft_isnums(splt_num[i]))
		{
			if (!ft_check_swap_write(splt_num, nums, i))
				return (0);
			temp_len = ft_strlen(splt_num[i]);
			if (temp_len > nums->len_max_num)
				nums->len_max_num = temp_len;
		}
		else
			return (0);
		++i;
	}
	return (1);
}
