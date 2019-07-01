/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:59:44 by hharrold          #+#    #+#             */
/*   Updated: 2019/07/01 14:59:47 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void				ft_push_a(t_push *nums)
{
	if (nums->num_a)
	{
		ft_rotate_a_b(nums, 'a');
		if (nums->num_a->next)
		{
			nums->num_b = nums->num_a->prev;
			nums->num_a->prev->prev->next = nums->num_a;
			nums->num_a->prev = nums->num_a->prev->prev;
		}
		else
			ft_num_null(nums, 'a');
		nums->len_a -= 1;
		if (nums->len_b++ > 0)
		{
			nums->num_b->next = nums->first_b;
			nums->first_b->prev = nums->num_b;
			nums->first_b = nums->num_b;
			nums->last_b->next = nums->num_b;
			nums->num_b->prev = nums->last_b;
		}
		else
			ft_supp_last_first_item(nums, 'b');
	}
}

void				ft_push_b(t_push *nums)
{
	if (nums->num_b)
	{
		ft_rotate_a_b(nums, 'b');
		if (nums->num_b->next)
		{
			nums->num_a = nums->num_a->prev;
			nums->num_b->prev->prev->next = nums->num_b;
			nums->num_b->prev = nums->num_b->prev->prev;
		}
		else
			ft_num_null(nums, 'b');
		nums->len_b -= 1;
		if (nums->len_a++ > 0)
		{
			nums->num_a->next = nums->first_a;
			nums->first_a->prev = nums->num_a;
			nums->first_a = nums->num_a;
			nums->last_a->next = nums->num_a;
			nums->num_a->prev = nums->last_a;
		}
		else
			ft_supp_last_first_item(nums, 'a');
	}
}

void				ft_swap_a_b(t_push *nums, char stack)
{
	t_num	*temp;

	ft_rotate_a_b(nums, stack);
	if (stack == 'a' || stack == 's')
		if (nums->len_a > 2)
		{
			temp = nums->num_a->prev;
			nums->last_a = nums->num_a->prev->prev;
			nums->num_a->prev->prev->next = nums->num_a;
			nums->num_a->prev = temp->prev;
			nums->num_a->next->prev = temp;
			temp->next = nums->num_a->next;
			nums->num_a->next = temp;
		}
	if (stack == 'b' || stack == 's')
		if (nums->len_b > 2)
		{
			temp = nums->num_b->prev;
			nums->last_b = nums->num_b->prev->prev;
			nums->num_b->prev->prev->next = nums->num_b;
			nums->num_b->prev = temp->prev;
			nums->num_b->next->prev = temp;
			temp->next = nums->num_b->next;
			nums->num_b->next = temp;
		}
}

void				ft_rotate_a_b(t_push *nums, char stack)
{
	if (stack == 'a' || stack == 's')
	{
		if (nums->num_a && nums->len_a > 1)
		{
			nums->num_a = nums->num_a->next;
			nums->first_a = nums->num_a;
			nums->last_a = nums->num_a->prev;
		}
	}
	if (stack == 'b' || stack == 's')
	{
		if (nums->num_b && nums->len_b > 1)
		{
			nums->num_b = nums->num_b->next;
			nums->first_b = nums->num_b;
			nums->last_b = nums->num_b->prev;
		}
	}
}

void				ft_rev_rotate_a_b(t_push *nums, char stack)
{
	if (stack == 'a' || stack == 's')
	{
		if (nums->num_a && nums->len_a > 1)
		{
			nums->num_a = nums->num_a->prev;
			nums->first_a = nums->num_a;
			nums->last_a = nums->num_a->next;
		}
	}
	if (stack == 'b' || stack == 's')
	{
		if (nums->num_b && nums->len_b > 1)
		{
			nums->num_b = nums->num_b->prev;
			nums->first_b = nums->num_b;
			nums->last_b = nums->num_b->next;
		}
	}
}