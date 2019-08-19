/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 17:10:34 by hharrold          #+#    #+#             */
/*   Updated: 2019/08/03 17:10:35 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				ft_sup_equal(t_push *nums, char command, char stack)
{
	nums->sup_a = nums->num_a;
	nums->sup_b = nums->num_b;
	nums->sp_a = nums->len_a;
	nums->sp_b = nums->len_b;
	ft_print_line(command, stack);
}

void				ft_print_command(char command, char stack)
{
	if (command == 's' && stack == 'a')
		ft_putstr("sa\n");
	else if (command == 's' && stack == 'b')
		ft_putstr("sb\n");
	else if (command == 's' && stack == 's')
		ft_putstr("ss\n");
	else if (command == 'p' && stack == 'a')
		ft_putstr("pb\n");
	else if (command == 'p' && stack == 'b')
		ft_putstr("pa\n");
	else if (command == 'r' && stack == 'a')
		ft_putstr("ra\n");
	else if (command == 'r' && stack == 'b')
		ft_putstr("rb\n");
	else if (command == 'r' && stack == 's')
		ft_putstr("rr\n");
	else if (command == 'v' && stack == 'a')
		ft_putstr("rra\n");
	else if (command == 'v' && stack == 'b')
		ft_putstr("rrb\n");
	else if (command == 'v' && stack == 's')
		ft_putstr("rrr\n");
}
