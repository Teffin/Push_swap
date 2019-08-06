/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_faster_on_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 14:02:48 by hharrold          #+#    #+#             */
/*   Updated: 2019/08/03 14:02:50 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void					ft_sup_for_faster_mode_a(t_push *nums, t_num *temp)
{
	while (temp->operation_on_a_r != 0 && temp->operation_on_b_r != 0)
	{
		ft_rotate_a_b(nums, 's', 1);
		--temp->operation_on_a_r;
		--temp->operation_on_b_r;
	}
	while (temp->operation_on_a_r != 0)
	{
		ft_rotate_a_b(nums, 'a', 1);
		--temp->operation_on_a_r;
	}
	while (temp->operation_on_b_r != 0)
	{
		ft_rotate_a_b(nums, 'b', 1);
		--temp->operation_on_b_r;
	}
}

static void					ft_sup_for_faster_mode_b(t_push *nums, t_num *temp)
{
	while (temp->operation_on_a_rr != 0 && temp->operation_on_b_rr != 0)
	{
		ft_rev_rotate_a_b(nums, 's', 1);
		--temp->operation_on_a_rr;
		--temp->operation_on_b_rr;
	}
	while (temp->operation_on_a_rr != 0)
	{
		ft_rev_rotate_a_b(nums, 'a', 1);
		--temp->operation_on_a_rr;
	}
	while (temp->operation_on_b_rr != 0)
	{
		ft_rev_rotate_a_b(nums, 'b', 1);
		--temp->operation_on_b_rr;
	}
}

static void					ft_sup_for_faster_mode_c(t_push *nums, t_num *temp)
{
	while (temp->operation_on_a_r != 0)
	{
		ft_rotate_a_b(nums, 'a', 1);
		--temp->operation_on_a_r;
	}
	while (temp->operation_on_b_rr != 0)
	{
		ft_rev_rotate_a_b(nums, 'b', 1);
		--temp->operation_on_b_rr;
	}
}

static void					ft_sup_for_faster_mode_d(t_push *nums, t_num *temp)
{
	while (temp->operation_on_b_r != 0)
	{
		ft_rotate_a_b(nums, 'b', 1);
		--temp->operation_on_b_r;
	}
	while (temp->operation_on_a_rr != 0)
	{
		ft_rev_rotate_a_b(nums, 'a', 1);
		--temp->operation_on_a_rr;
	}
}

void						ft_push_faster_on_a(t_push *nums, int temp_num)
{
	t_num	*temp;

	temp = nums->num_b;
	while (temp->num != temp_num)
		temp = temp->next;
	if (temp->mode == 'a')
		ft_sup_for_faster_mode_a(nums, temp);
	else if (temp->mode == 'b')
		ft_sup_for_faster_mode_b(nums, temp);
	else if (temp->mode == 'c')
		ft_sup_for_faster_mode_c(nums, temp);
	else if (temp->mode == 'd')
		ft_sup_for_faster_mode_d(nums, temp);
	ft_push_b(nums, 1);
}
