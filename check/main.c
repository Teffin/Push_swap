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
#include <fcntl.h>

static int		ft_chck_sort(t_push *nums)
{
	t_num		*temp;

	temp = nums->num_a;
	if (nums->num_b)
		return (0);
	while (temp->num != nums->last_a->num)
	{
		if (temp->num > temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int				ft_do_command(t_push *nums, char *comm)
{
	if (ft_strequ(comm, "pb"))
		ft_push_a(nums, 1);
	else if (ft_strequ(comm, "pa"))
		ft_push_b(nums, 1);
	else if (ft_strequ(comm, "sa"))
		ft_swap_a_b(nums, 'a', 1);
	else if (ft_strequ(comm, "sb"))
		ft_swap_a_b(nums, 'b', 1);
	else if (ft_strequ(comm, "ss"))
		ft_swap_a_b(nums, 's', 1);
	else if (ft_strequ(comm, "ra"))
		ft_rotate_a_b(nums, 'a', 1);
	else if (ft_strequ(comm, "rb"))
		ft_rotate_a_b(nums, 'b', 1);
	else if (ft_strequ(comm, "rr"))
		ft_rotate_a_b(nums, 's', 1);
	else if (ft_strequ(comm, "rra"))
		ft_rev_rotate_a_b(nums, 'a', 1);
	else if (ft_strequ(comm, "rrb"))
		ft_rev_rotate_a_b(nums, 'b', 1);
	else if (ft_strequ(comm, "rrr"))
		ft_rev_rotate_a_b(nums, 's', 1);
	else
		return (0);
	return (1);
}

int				ft_check_command(t_push *nums)
{
	char	*comm;

	while (ft_take(0, &comm) > 0)
	{
		if (ft_strequ(comm, ""))
			break ;
		if (!ft_do_command(nums, comm))
		{
			ft_putstr("Error\n");
			free(comm);
			exit(0);
		}
		free(comm);
	}
	if (!ft_chck_sort(nums))
	{
		ft_putstr("KO\n");
		return (0);
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_push		nums;

	ft_create_push_list(&nums);
	if (!ft_sup_checking(ac, av, &nums))
	{
		ft_free_num(&nums);
		return (0);
	}
	if (!nums.num_a)
		return (0);
	nums.checker = 1;
	ft_support_after_valid(&nums);
	if (nums.flag_visual && nums.checker)
		ft_print_nums(&nums, 'z', 's', 1);
	if (ft_check_command(&nums))
		ft_putstr("OK\n");
	ft_free_num(&nums);
	return (0);
}
