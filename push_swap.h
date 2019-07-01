/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 13:09:20 by hharrold          #+#    #+#             */
/*   Updated: 2019/04/29 13:09:22 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <stdio.h> /* PRINTF */

typedef struct				s_list_num
{
	int						num;
	int						len;
	struct s_list_num		*next;
	struct s_list_num		*prev;
}							t_num;

typedef struct				s_list_push
{
	struct s_list_num		*num_a;
	struct s_list_num		*num_b;
	struct s_list_num		*first_a;
	struct s_list_num		*last_a;
	struct s_list_num		*first_b;
	struct s_list_num		*last_b;
	int						flag_v;
	int						flag_j;
	int						end_flag;
	int						len_max_num;
	int						len_a;
	int						len_b;
}							t_push;

int							ft_check_valid(char *av, t_push *nums);
t_push						*ft_create_push_list();
t_num						*ft_create_num();
void						ft_print_nums(t_push *nums);
int							ft_check_flag(char *av, t_push *nums);
void						ft_swap_a_b(t_push *nums, char stack);
void						ft_rotate_a_b(t_push *nums, char stack);
void						ft_rev_rotate_a_b(t_push *nums, char stack);
void						ft_support_after_valid(t_push *nums);
void						ft_num_null(t_push *nums, char stack);
void						ft_supp_last_first_item(t_push *nums, char stack);
int         				ft_sup_checking(int ac, char **av, t_push *nums);
void						ft_support_after_valid(t_push *nums);
void						ft_num_null(t_push *nums, char stack);
#endif
