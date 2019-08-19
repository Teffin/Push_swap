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

int				main(int ac, char **av)
{
	t_push		*nums;

	nums = ft_create_push_list();
	if (!ft_sup_checking(ac, av, nums))
		return (0);
	ft_support_after_valid(nums);
	if (nums->flag_visual && nums->checker)
		ft_print_nums(nums, 'z', 's', 1);
	if (!ft_algorithm(nums))
		ft_putstr("My fail\n");
	ft_free_num(nums);
	return (0);
}
