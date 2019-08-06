/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:58:16 by hharrold          #+#    #+#             */
/*   Updated: 2019/04/30 16:58:19 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			ft_print_next(char command, char stack)
{
	if (command == 'p' && stack == 'a')
		ft_putstr("Exec pa:\n");
	else if (command == 'p' && stack == 'b')
		ft_putstr("Exec pb:\n");
	else if (command == 'r' && stack == 'a')
		ft_putstr("Exec ra:\n");
	else if (command == 'r' && stack == 'b')
		ft_putstr("Exec rb:\n");
	else if (command == 'r' && stack == 's')
		ft_putstr("Exec rr:\n");
	else if (command == 'v' && stack == 'a')
		ft_putstr("Exec rra:\n");
	else if (command == 'v' && stack == 'b')
		ft_putstr("Exec rrb:\n");
	else if (command == 'v' && stack == 's')
		ft_putstr("Exec rrr:\n");
}

void				ft_print_line(char command, char stack)
{
	int j;

	j = 30;
	while (j-- && (command == 'z' || command == 'e'))
		ft_putstr("-");
	if (command == 'e' && stack == 's')
		ft_putstr("\n");
	else if (command == 'z')
		ft_putstr("\nInitial a and b:\n");
	else if (command == 's' && stack == 'a')
		ft_putstr("Exec sa:\n");
	else if (command == 's' && stack == 'b')
		ft_putstr("Exec sb:\n");
	else if (command == 's' && stack == 's')
		ft_putstr("Exec ss:\n");
	else
		ft_print_next(command, stack);
}

static void			ft_bottom_print(int i, t_push *nums)
{
	int j;

	j = i;
	ft_putstr("\n-");
	while (i--)
		ft_putstr(" ");
	ft_putstr("-\na");
	while (j--)
		ft_putstr(" ");
	ft_putstr("b\n");
	if (nums->flag_score && nums->checker)
	{
		ft_putstr(ft_itoa(nums->score++));
		ft_putstr(" - time(s)\n");
	}
	ft_print_line('e', 's');
}

int					ft_print_stack(t_num *nums_a, t_num *nums_b, int i)
{
	if (i == 1)
		ft_putstr(ft_itoa(nums_a->num));
	else if (nums_a->num == nums_b->num)
	{
		while (i--)
			ft_putstr(" ");
		ft_putstr(ft_itoa(nums_b->num));
	}
	else
	{
		ft_putstr(ft_itoa(nums_a->num));
		while (i--)
			ft_putstr(" ");
		ft_putstr(ft_itoa(nums_b->num));
	}
	return (1);
}

void				ft_print_nums(t_push *nums, char command,
												char stack, int print)
{
	if (nums->flag_sleep_mode && nums->checker)
		ft_sleep(nums->flag_sleep_mode);
	if (!nums->checker && print)
		return (ft_print_command(command, stack));
	else if (!nums->checker)
		return ;
	ft_sup_equal(nums, command, stack);
	while (nums->sp_a > 0 || nums->sp_b > 0)
	{
		if (nums->sp_a > nums->sp_b)
		{
			nums->sp_a -= ft_print_stack(nums->sup_a, nums->sup_a, 1);
			nums->sup_a = nums->sup_a->next;
		}
		else if (nums->sp_a < nums->sp_b)
		{
			nums->sp_b -= ft_print_stack(nums->sup_b, nums->sup_b,
												nums->len_max_num + 2);
			nums->sup_b = nums->sup_b->next;
		}
		else
			ft_sup_prnt(nums);
		ft_putstr("\n");
	}
	ft_bottom_print(nums->len_max_num + 1, nums);
}
