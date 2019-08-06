/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_faster_on_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 14:24:49 by hharrold          #+#    #+#             */
/*   Updated: 2019/08/03 14:24:52 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int				ft_check_three_num(t_push *nums)
{
	int		last_num;
	t_num	*temp;
	int		i;

	if (!nums->num_a)
		return (1);
	temp = nums->num_a;
	last_num = temp->num;
	temp = temp->next;
	i = 1;
	while (temp->num != last_num)
	{
		temp = temp->next;
		++i;
	}
	if (i < 4)
		return (1);
	else
		return (0);
}

static void				ft_sup_for_push_on_b(t_push *nums)
{
	if (nums->num_b && nums->first_b < nums->num_b->next
					&& nums->first_a > nums->num_a->next)
		ft_swap_a_b(nums, 's', 1);
	else
	{
		if (nums->num_a->num != nums->max && nums->num_a->num != nums->min)
			ft_push_a(nums, 1);
		else
		{
			if (nums->num_b && nums->first_b < nums->last_b)
				ft_rotate_a_b(nums, 's', 1);
			else
				ft_rotate_a_b(nums, 'a', 1);
		}
	}
}

void					ft_push_on_b(t_push *nums)
{
	int		last_num;

	last_num = 0;
	if (ft_check_three_num(nums))
		return ;
	if (nums->num_a->prev->num != nums->max &&
								nums->num_a->prev->num != nums->min)
		last_num = nums->num_a->prev->num;
	else if (nums->num_a->prev->prev->num != nums->max &&
							nums->num_a->prev->prev->num != nums->min)
		last_num = nums->num_a->prev->prev->num;
	else
		last_num = nums->num_a->prev->prev->prev->num;
	while (last_num != nums->num_a->num)
		ft_sup_for_push_on_b(nums);
}
