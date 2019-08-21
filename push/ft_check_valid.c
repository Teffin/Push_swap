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

static int		ft_equaly_a_i(char *splt_num, t_num *temp, t_push *nums)
{
	char		*str_itoa;
	int			i;

	i = 0;
	str_itoa = ft_itoa(temp->num);
	while (splt_num[i] == '0' && splt_num[i + 1] >= '0' &&
														splt_num[i + 1] <= '9')
		++i;
	if (!ft_strequ(splt_num + i, str_itoa) || !ft_double_num(temp->num, nums))
	{
		free(str_itoa);
		return (0);
	}
	free(str_itoa);
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
	if (!(ft_equaly_a_i(splt_num[i], temp, nums)))
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
		if (!(ft_isnums(splt_num[i])) ||
			(!ft_check_swap_write(splt_num, nums, i)))
		{
			ft_split_free(splt_num);
			return (0);
		}
		temp_len = ft_strlen(splt_num[i]);
		if (temp_len > nums->len_max_num)
			nums->len_max_num = temp_len;
		++i;
	}
	ft_split_free(splt_num);
	return (1);
}
