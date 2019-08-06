/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_score_for_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 14:09:05 by hharrold          #+#    #+#             */
/*   Updated: 2019/08/03 14:09:07 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char					ft_what_min(t_num *temp)
{
	int		a;
	int		b;
	int		c;
	int		d;

	if (temp->operation_on_a_r > temp->operation_on_b_r)
		a = temp->operation_on_a_r;
	else
		a = temp->operation_on_b_r;
	if (temp->operation_on_a_rr > temp->operation_on_b_rr)
		b = temp->operation_on_a_rr;
	else
		b = temp->operation_on_b_rr;
	c = temp->operation_on_a_r + temp->operation_on_b_rr;
	d = temp->operation_on_b_r + temp->operation_on_a_rr;
	if (a <= b && a <= c && a <= d && (temp->step = a))
		return ('a');
	else if (b <= c && b <= d && (temp->step = b))
		return ('b');
	else if (c <= d && (temp->step = c))
		return ('c');
	temp->step = d;
	return ('d');
}

static void					ft_scope_for_b(t_num *temp,
												t_num *temp_b, char times)
{
	if (times == '1')
	{
		while (temp->num != temp_b->num)
		{
			temp_b = temp_b->next;
			++temp->operation_on_b_r;
		}
	}
	if (times == '2')
	{
		while (temp->num != temp_b->num)
		{
			temp_b = temp_b->prev;
			++temp->operation_on_b_rr;
		}
	}
}

static void					ft_rotate_scope(t_push *nums, t_num *temp)
{
	t_num	*temp_a;
	t_num	*temp_b;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp_a = nums->num_a;
	temp_b = nums->num_b;
	ft_scope_for_b(temp, temp_b, '1');
	temp_b = nums->num_b;
	ft_scope_for_b(temp, temp_b, '2');
	while (!(temp->num < temp_a->num && temp->num > temp_a->prev->num))
	{
		temp_a = temp_a->next;
		++temp->operation_on_a_r;
	}
	temp_a = nums->num_a;
	while (!(temp->num < temp_a->num && temp->num > temp_a->prev->num))
	{
		temp_a = temp_a->prev;
		++temp->operation_on_a_rr;
	}
	temp->mode = ft_what_min(temp);
}

void						ft_score_num_b(t_push *nums)
{
	t_num	*temp;

	temp = nums->num_b;
	while (temp->operation_on_b_r == 0 && temp->operation_on_a_r == 0 &&
				temp->operation_on_b_rr == 0 && temp->operation_on_a_rr == 0)
	{
		ft_rotate_scope(nums, temp);
		if (temp == temp->next)
			break ;
		temp = temp->next;
	}
}
