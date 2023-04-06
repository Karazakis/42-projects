/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:59:49 by akoutsou          #+#    #+#             */
/*   Updated: 2023/04/06 15:37:20 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


typedef struct s_len
{
	int			a;
	int			b;
}	t_len;

typedef struct s_stack
{
	int			*a;
	int			*b;
}	t_stack;

typedef struct s_stackdetail
{
	t_len		len;

}	t_stackdetail;

void	ft_phase_one(t_stack *stack, t_stackdetail *details, int *arr, int max);
void	ft_phase_two(t_stack *stack, t_stackdetail *details);
void	ft_phase_three(t_stack *stack, t_stackdetail *details);
void	ft_push_swap(char **str, int count);
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
void	ft_rmv_frst_el(t_stack *stack, t_len *len, int side);
void	ft_rmv_lst_el(t_stack *stack, t_len *len, int side);
void	ft_push_elem_in_front(t_stack *stack, int to_shift, t_len *len, int side);
void	ft_push_elem_in_tail(t_stack *stack, int to_shift, t_len *len, int side);
void	ft_putstr(char *str);
int		ft_isnumber(char *str);
int		ft_checkinput(char **input);
int		ft_best_nbr_a(int *stack, int size, int *arr, int max);
int		ft_best_nbr_b(t_stack *stack, t_stackdetail *details);
int		ft_best_comb_helper(int *arr_a, int *arr_b, int *tmp, int size);
int		ft_best_comb(int *arr_a, int *arr_b, int size);
int		ft_move_a(int a, int b, t_stack *stack, t_stackdetail *details);
int		ft_min_nbr(int a, int b);
int		ft_max_nbr(int a, int b);
int		ft_the_needed_b(int max, int size);
int		ft_the_needed_a(t_stack *stack, t_stackdetail *details, int cont, int size);
int		*ft_intcpy(int	*arr, int size);
int		ft_max_or_min(t_stack *stack, t_stackdetail *details, int cont, int size);
int		return_max_or_min(int cont, int *max_n_min, int size);
int		*ft_arr_cat(int *arr, int to_cat, int count, int side);
int		*ft_arr_cat_front(int *arr, int to_cat, int count);
int		*ft_arr_cat_tail(int *arr, int to_cat, int count);
int		*ft_takelist(char **str, int count);
int		ft_atoi(char *str);
int		*ft_arr_cpy(int *arr, int count);
int		ft_arrlen(int *arr);
int	*ft_create_lis(int *dst, int size, int *max);
int	*ft_lis_utils(int *dst, int *arr, int max, int size);
int	*ft_lis_utils_helper(int max);
void ft_print_stack(int *stack, int count);
