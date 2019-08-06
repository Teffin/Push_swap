/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:39:55 by hharrold          #+#    #+#             */
/*   Updated: 2019/08/01 16:39:57 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void					ft_search_first_last_item(t_push *nums)
{
	int		last_num;
	t_num	*temp;

	temp = nums->num_a;
	last_num = temp->num;
	nums->min = last_num;
	nums->max = last_num;
	temp = temp->next;
	while (temp->num != last_num)
	{
		if (temp->num > nums->max)
			nums->max = temp->num;
		if (temp->num < nums->min)
			nums->min = temp->num;
		temp = temp->next;
	}
}

void						ft_score_reset(t_push *nums)
{
	t_num	*temp;

	if (!nums->num_b)
		return ;
	temp = nums->num_b;
	temp->operation_on_a_r = 0;
	temp->operation_on_a_rr = 0;
	temp->operation_on_b_r = 0;
	temp->operation_on_b_rr = 0;
	temp = temp->next;
	while (temp != nums->num_b)
	{
		temp->operation_on_a_r = 0;
		temp->operation_on_a_rr = 0;
		temp->operation_on_b_r = 0;
		temp->operation_on_b_rr = 0;
		temp = temp->next;
	}
}

static void					ft_search_min_and_push(t_push *nums)
{
	t_num	*temp;
	int		min;
	int		temp_num;

	temp = nums->num_b;
	min = temp->step;
	temp_num = temp->num;
	temp = temp->next;
	while (temp != nums->num_b)
	{
		if (min > temp->step)
		{
			min = temp->step;
			temp_num = temp->num;
		}
		temp = temp->next;
	}
	ft_push_faster_on_a(nums, temp_num);
}

void						ft_rotate_for_sort(t_push *nums)
{
	t_num		*temp;
	int			i;
	int			j;

	j = 0;
	i = 0;
	temp = nums->num_a;
	while (temp->num != nums->min)
	{
		temp = temp->next;
		++j;
	}
	temp = nums->num_a;
	while (temp->num != nums->min)
	{
		temp = temp->prev;
		++i;
	}
	if (j < i)
		while (j--)
			ft_rotate_a_b(nums, 'a', 1);
	else
		while (i--)
			ft_rev_rotate_a_b(nums, 'a', 1);
}

int							ft_algorithm(t_push *nums)
{
	ft_search_first_last_item(nums);
	if (ft_is_sort(nums))
	{
		ft_rotate_for_sort(nums);
		return (1);
	}
	ft_push_on_b(nums);
	if (!ft_sort_a(nums))
		return (0);
	while (nums->num_b)
	{
		ft_score_num_b(nums);
		ft_search_min_and_push(nums);
		ft_score_reset(nums);
	}
	ft_rotate_for_sort(nums);
	return (1);
}
