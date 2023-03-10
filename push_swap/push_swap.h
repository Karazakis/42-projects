/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:59:49 by akoutsou          #+#    #+#             */
/*   Updated: 2023/03/06 16:16:27 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_count
{
	int			first;
	int			second;
}	t_count;

typedef struct s_len
{
	int			a;
	int			b;
	int			ordered_len;
}	t_len;

typedef struct s_stack
{
	int			*a;
	int			*b;
	int			*ordered;
}	t_stack;

typedef struct s_stackdetail
{
	int			half_to_b;
	int			a_is_swap;
	int			b_is_swap;
	int			bot_a;
	int			top_a;
	int			bot_b;
	int			top_b;
	int			is_ordered;
	t_len		len;

}	t_stackdetail;

void	ft_push_swap(char **str, int count);
void	ft_phase_one(t_stack stack,t_stackdetail *details, int count);
void	ft_phase_two(t_stack *stack,t_stackdetail details);
void	ft_phase_three(t_stack *stack,t_stackdetail *details);
void	ft_phase_four(t_stack stack,t_stackdetail details);
void	swap(int* a, int* b);
void	quickSort(int *arr, int low, int high);
void	ft_print_stack(int *stack, int count);
void	ft_check_first_quart(t_stack stack, t_count *counter, int count);
void	ft_check_last_quart(t_stack stack, t_count *counter, int count);
void	ft_rmv_frst_el(t_stack *stack, t_len *len, int side);
void	ft_rmv_lst_el(t_stack *stack, t_len *len, int side);
void	ft_push_elem_in_front(t_stack *stack, int to_shift, t_len *len, int side);
void	ft_push_elem_in_tail(t_stack *stack, int to_shift, t_len *len, int side);
void	ft_pb(t_stack *stack, t_len *len);
void	ft_pa(t_stack *stack, t_len *len);
void	ft_rb(t_stack *stack, t_len *len, int flg);
void	ft_ra(t_stack *stack, t_len *len, int flg);
void	ft_rr(t_stack *stack, t_len *len);
void	ft_rrb(t_stack *stack, t_len *len, int flg);
void	ft_rra(t_stack *stack, t_len *len, int flg);
void	ft_rrr(t_stack *stack, t_len *len);
void	ft_sa(t_stack *stack, int flg);
void	ft_sb(t_stack *stack, int flg);
void	ft_ss(t_stack *stack);
void	ft_putstr(char *str);
void	ft_check_swap_dist(t_stack *stack,t_stackdetail *details);
void	ft_swap_moves(t_stack *stack,t_stackdetail *details);
void	ft_rotate_moves(t_stack *stack,t_stackdetail *details);
void	ft_check_swp(t_stack *stack,t_stackdetail *details);
void	ft_check_rotate_top(int *stack,t_stackdetail *details, int to_stack, int highest);
void	ft_check_rotate_bot(int *stack,t_stackdetail *details, int to_stack, int highest);
int		ft_highest(int *stack, int len);
int		ft_check_orders(t_stack *stack,t_stackdetail *details);
int		ft_check_if_swap(t_stackdetail details);
int		ft_check_move_cat(t_stackdetail *details);
int		*ft_arr_cat(int *arr, int to_cat, int count, int side);
int		*ft_arr_cat_front(int *arr, int to_cat, int count);
int		*ft_arr_cat_tail(int *arr, int to_cat, int count);
int		partition(int *arr, int low, int high);
int		*ft_takelist(char **str, int count);
int		ft_atoi(char *str);
int		*ft_arr_cpy(int *arr, int count);
int		ft_arrlen(int *arr);
int		ft_check_order(int *stack, int count);
int		ft_is_first(int *arr, int to_check, int count);
int		ft_far_from_bot(int *control_arr, t_stack *stack, int count, int half_to_b);
int		ft_far_from_top(int *control_arr, t_stack *stack, int count, int half_to_b);
int		ft_is_half(t_stack *stack, int half_to_b, int count);
int		ft_is_frombot(t_stack *stack, int half_to_b, int count);
int		ft_check_rotate_comb(t_stack *stack,t_stackdetail *details);


