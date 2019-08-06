/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supporting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:15:43 by hharrold          #+#    #+#             */
/*   Updated: 2019/07/01 14:15:45 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					ft_sup_checking(int ac, char **av, t_push *nums)
{
	int			counter;

	counter = 1;
	if (ac < 2)
		return (0);
	while (ac > counter)
	{
		if (!nums->end_flag && ft_check_flag(av[counter], nums))
			++counter;
		else if (ft_check_valid(av[counter], nums))
		{
			++counter;
			nums->end_flag = 1;
		}
		else
		{
			ft_putstr("Error\n");
			return (0);
		}
	}
	return (1);
}

void				ft_support_after_valid(t_push *nums)
{
	t_num	*temp;

	nums->first_a = nums->num_a;
	temp = nums->num_a;
	while (temp != NULL && temp->next != NULL)
	{
		temp = temp->next;
		nums->len_a += 1;
	}
	nums->last_a = temp;
	if (temp != NULL)
	{
		nums->len_a += 1;
		temp->next = nums->num_a;
		nums->num_a->prev = temp;
	}
}

void				ft_num_null(t_push *nums, char stack)
{
	if (stack == 'a')
	{
		nums->num_a = NULL;
		nums->first_a = NULL;
		nums->last_a = NULL;
	}
	if (stack == 'b')
	{
		nums->num_b = NULL;
		nums->first_b = NULL;
		nums->last_b = NULL;
	}
}

void				ft_supp_last_first_item(t_push *nums, char stack)
{
	if (stack == 'a')
	{
		nums->first_a = nums->num_a;
		nums->last_a = nums->num_a;
		nums->num_a->next = nums->num_a;
		nums->num_a->prev = nums->num_a;
	}
	if (stack == 'b')
	{
		nums->first_b = nums->num_b;
		nums->last_b = nums->num_b;
		nums->num_b->next = nums->num_b;
		nums->num_b->prev = nums->num_b;
	}
}

void				ft_resave_first_item(t_push *nums, char stack)
{
	if (stack == 'a')
	{
		nums->num_a->next = nums->first_a;
		nums->num_a->prev = nums->last_a;
		nums->first_a->prev = nums->num_a;
		nums->last_a->next = nums->num_a;
		nums->first_a = nums->num_a;
	}
	if (stack == 'b')
	{
		nums->num_b->next = nums->first_b;
		nums->num_b->prev = nums->last_b;
		nums->first_b->prev = nums->num_b;
		nums->last_b->next = nums->num_b;
		nums->first_b = nums->num_b;
	}
}
