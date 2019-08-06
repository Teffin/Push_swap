/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sup_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:04:44 by hharrold          #+#    #+#             */
/*   Updated: 2019/07/04 15:04:46 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_sleep(int ms)
{
	int		time;

	time = 0;
	while (ms)
	{
		while (time <= 700000)
			++time;
		time = 0;
		--ms;
	}
}

void			ft_sup_prnt(t_push *nums)
{
	int		i;

	i = nums->len_max_num - nums->sup_a->len + 2;
	nums->sp_a -= ft_print_stack(nums->sup_a, nums->sup_b, i);
	--nums->sp_b;
	nums->sup_a = nums->sup_a->next;
	nums->sup_b = nums->sup_b->next;
}

void			ft_help_swap(t_push *nums, char stack)
{
	ft_rotate_a_b(nums, stack, 0);
	ft_push_a(nums, 0);
	ft_rev_rotate_a_b(nums, stack, 0);
	ft_push_b(nums, 0);
}

int				ft_is_sort(t_push *nums)
{
	t_num	*temp;
	int		last;

	temp = nums->num_a;
	while (temp->num != nums->min)
		temp = temp->next;
	last = temp->prev->num;
	while (temp->num != last)
	{
		if (temp->num > temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int				ft_sort_a(t_push *nums)
{
	if (!ft_is_sort(nums))
	{
		if (nums->num_a->num > nums->num_a->next->num &&
				nums->num_a->num < nums->num_a->prev->num)
			ft_swap_a_b(nums, 'a', 1);
		else if (nums->num_a->next->num > nums->num_a->num &&
		nums->num_a->next->num > nums->num_a->next->next->num)
		{
			ft_rotate_a_b(nums, 'a', 1);
			ft_swap_a_b(nums, 'a', 1);
		}
		else
			ft_swap_a_b(nums, 'a', 1);
		if (!ft_is_sort(nums))
			return (0);
	}
	return (1);
}
