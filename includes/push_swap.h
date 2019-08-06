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

typedef struct				s_list_num
{
	int						num;
	int						len;
	int						operation_on_a_r;
	int						operation_on_a_rr;
	int						operation_on_b_r;
	int						operation_on_b_rr;
	int						step;
	char					mode;
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
	struct s_list_num		*sup_a;
	struct s_list_num		*sup_b;
	int						sp_a;
	int						sp_b;
	int						flag_visual;
	int						flag_j;
	int						flag_score;
	int						score;
	int						end_flag;
	int						min;
	int						max;
	int						flag_sleep_mode;
	int						len_max_num;
	int						len_a;
	int						len_b;
	int						checker;

}							t_push;

t_push						*ft_create_push_list();
int							ft_sup_checking(int ac, char **av, t_push *nums);
int							ft_check_flag(char *av, t_push *nums);
int							ft_check_valid(char *av, t_push *nums);
t_num						*ft_create_num();
void						ft_support_after_valid(t_push *nums);
void						ft_print_nums(t_push *nums, char command,
													char stack, int print);
int							ft_print_stack(t_num *nums_a, t_num *nums_b, int i);
void						ft_sup_prnt(t_push *nums);
int							ft_algorithm(t_push *nums);
void						ft_push_on_b(t_push *nums);
void						ft_push_a(t_push *nums, int p);
void						ft_push_b(t_push *nums, int p);
void						ft_supp_last_first_item(t_push *nums, char stack);
void						ft_resave_first_item(t_push *nums, char stack);
void						ft_num_null(t_push *nums, char stack);
void						ft_swap_a_b(t_push *nums, char stack, int p);
void						ft_help_swap(t_push *nums, char stack);
void						ft_rotate_a_b(t_push *nums, char stack, int p);
void						ft_rev_rotate_a_b(t_push *nums, char stack, int p);
int							ft_sort_a(t_push *nums);
int							ft_is_sort(t_push *nums);
void						ft_score_num_b(t_push *nums);
void						ft_push_faster_on_a(t_push *nums, int temp_num);
void						ft_sleep(int ms);
void						ft_sup_equal(t_push *nums, char command,
																char stack);
void						ft_print_command(char command, char stack);
void						ft_print_line(char command, char stack);
#endif
