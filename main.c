/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:35:10 by hharrold          #+#    #+#             */
/*   Updated: 2019/04/29 15:35:12 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_next_step(t_push *nums)
{
	if (nums->num_a)
	{
		if (nums->flag_v)
			ft_print_nums(nums);
		printf("len_a = %d\n", nums->len_a); // printF
		ft_putstr("OK\n");
	}
	else
		ft_putstr("KO\n");
}

int				main(int ac, char **av)
{
	
	t_push		*nums;

	nums = ft_create_push_list();
	if(!ft_sup_checking(ac, av, nums))
		return(0);
	ft_support_after_valid(nums);
	ft_rotate_a_b(nums, 'a');
	ft_swap_a_b(nums, 's');
	ft_next_step(nums);
	return (0);
}


/* Dont forget about printf in ft_print_nums */