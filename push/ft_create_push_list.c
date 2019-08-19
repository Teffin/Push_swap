/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_push_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:54:47 by hharrold          #+#    #+#             */
/*   Updated: 2019/04/29 16:54:48 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_free_num(t_push *nums)
{
	t_num		*temp;
	t_num		*temp1;

	temp = nums->num_a->prev;
	while (nums->num_a != temp)
	{
		temp1 = nums->num_a->next;
		free(nums->num_a);
		nums->num_a = temp1;
	}
	free(nums->num_a);
	free(nums);
}

t_num			*ft_create_num(void)
{
	t_num		*number;

	if (!(number = (t_num*)malloc(sizeof(*number))))
		return (NULL);
	number->num = 0;
	number->len = 0;
	number->prev = NULL;
	number->next = NULL;
	number->operation_on_a_r = 0;
	number->operation_on_a_rr = 0;
	number->operation_on_b_r = 0;
	number->operation_on_b_rr = 0;
	number->step = 0;
	number->mode = 0;
	return (number);
}

static void		ft_help_create(t_push *nums)
{
	nums->flag_visual = 0;
	nums->flag_score = 0;
	nums->score = 0;
	nums->flag_j = 0;
	nums->flag_sleep_mode = 0;
	nums->end_flag = 0;
	nums->checker = 0;
}

t_push			*ft_create_push_list(void)
{
	t_push		*nums;

	if (!(nums = (t_push*)malloc(sizeof(*nums))))
		return (NULL);
	nums->num_a = NULL;
	nums->num_b = NULL;
	nums->first_a = NULL;
	nums->last_a = NULL;
	nums->first_b = NULL;
	nums->last_b = NULL;
	nums->sup_a = NULL;
	nums->sup_b = NULL;
	nums->sp_a = 0;
	nums->sp_b = 0;
	nums->len_a = 0;
	nums->len_b = 0;
	nums->min = 0;
	nums->max = 0;
	nums->len_max_num = 0;
	ft_help_create(nums);
	return (nums);
}
