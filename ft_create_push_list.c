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

t_num			*ft_create_num(void)
{
	t_num		*number;

	if (!(number = (t_num*)malloc(sizeof(*number))))
		return (NULL);
	number->num = 0;
	number->len = 0;
	number->prev = NULL;
	number->next = NULL;
	return (number);
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
	nums->flag_v = 0;
	nums->flag_j = 0;
	nums->end_flag = 0;
	nums->len_a = 0;
	nums->len_b = 0;
	nums->len_max_num = 0;
	return (nums);
}
