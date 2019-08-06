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

void				ft_push_a(t_push *nums, int p)
{
	t_num	*temp;

	if (nums->num_a != NULL)
	{
		nums->num_b = nums->num_a;
		ft_rotate_a_b(nums, 'a', 0);
		if (nums->len_a > 1)
		{
			temp = nums->num_b->prev;
			temp->next = nums->num_a;
			nums->num_a->prev = temp;
			nums->last_a = temp;
		}
		else
			ft_num_null(nums, 'a');
		nums->len_a -= 1;
		if (nums->len_b++ > 0)
			ft_resave_first_item(nums, 'b');
		else
			ft_supp_last_first_item(nums, 'b');
	}
	if ((nums->flag_visual && p && nums->checker) || !nums->checker)
		ft_print_nums(nums, 'p', 'a', p);
}

void				ft_push_b(t_push *nums, int p)
{
	t_num	*temp;

	if (nums->num_b != NULL)
	{
		nums->num_a = nums->num_b;
		ft_rotate_a_b(nums, 'b', 0);
		if (nums->len_b > 1)
		{
			temp = nums->num_a->prev;
			temp->next = nums->num_b;
			nums->num_b->prev = temp;
			nums->last_b = temp;
		}
		else
			ft_num_null(nums, 'b');
		nums->len_b -= 1;
		if (nums->len_a++ > 0)
			ft_resave_first_item(nums, 'a');
		else
			ft_supp_last_first_item(nums, 'a');
	}
	if ((nums->flag_visual && p && nums->checker) || !nums->checker)
		ft_print_nums(nums, 'p', 'b', p);
}

void				ft_swap_a_b(t_push *nums, char stack, int p)
{
	if (stack == 'a' || stack == 's')
	{
		if (nums->len_a > 2)
			ft_help_swap(nums, 'a');
		else
			ft_rotate_a_b(nums, 'a', 0);
	}
	if (stack == 'b' || stack == 's')
	{
		if (nums->len_b > 2)
			ft_help_swap(nums, 'b');
		else
			ft_rotate_a_b(nums, 'b', 0);
	}
	if ((nums->flag_visual && p && nums->checker) || !nums->checker)
		ft_print_nums(nums, 's', stack, p);
}

void				ft_rotate_a_b(t_push *nums, char stack, int p)
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
	if ((nums->flag_visual && p && nums->checker) || !nums->checker)
		ft_print_nums(nums, 'r', stack, p);
}

void				ft_rev_rotate_a_b(t_push *nums, char stack, int p)
{
	if (stack == 'a' || stack == 's')
	{
		if (nums->num_a && nums->len_a > 1)
		{
			nums->num_a = nums->num_a->prev;
			nums->first_a = nums->num_a;
			nums->last_a = nums->num_a->prev;
		}
	}
	if (stack == 'b' || stack == 's')
	{
		if (nums->num_b && nums->len_b > 1)
		{
			nums->num_b = nums->num_b->prev;
			nums->first_b = nums->num_b;
			nums->last_b = nums->num_b->prev;
		}
	}
	if ((nums->flag_visual && p && nums->checker) || !nums->checker)
		ft_print_nums(nums, 'v', stack, p);
}
