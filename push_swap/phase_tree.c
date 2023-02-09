#include "push_swap.h"

void ft_check_swap_dist(t_stack *stack,t_stackdetail *details)
{
	ft_check_swp(stack, details);
	ft_check_rotate(stack, details);
}

int	ft_check_move_cat(t_stackdetail *details)
{
	if (details->a_is_swap == 1 && details->b_is_swap == 1)
		return (0);
	if (ft_check_if_swap(details) == 1)
		return (0);
	return (1);
}

void ft_swap_moves(t_stack *stack,t_stackdetail *details)
{
	if (details->a_is_swap == 1 && details->b_is_swap == 1)
		ft_ss(stack);
	if (details->a_is_swap == 1)
		ft_sa(stack, 0);
	else
		ft_sb(stack, 0);
}
void ft_rotate_moves(t_stack *stack,t_stackdetail *details)
{
	if (ft_check_rotate_comb(stack, details) == 1)
		return;
	if (details->bot_a <= details->top_a && details->bot_a <= details->bot_b && details->bot_a <= details->top_b)
		ft_rra(stack, &details->len, 0);
	if (details->top_a <= details->bot_a && details->top_a <= details->bot_b && details->top_a <= details->top_b)
		ft_ra(stack, &details->len, 0);
	if (details->bot_b < details->top_b && details->bot_b < details->bot_a && details->bot_b < details->top_a)
		ft_rra(stack, &details->len, 0);
	if (details->top_a < details->bot_a && details->top_a < details->bot_b && details->top_a < details->top_b)
		ft_rra(stack, &details->len, 0);
}

void ft_check_orders(t_stack *stack,t_stackdetail *details)
{
	if (ft_check_order(stack->a, details->len.a) == 1)
		if (ft_check_order(stack->b, details->len.b) == 1)
			return (1);
	return (0);
}

int ft_check_rotate_comb(t_stack *stack,t_stackdetail *details)
{
	if (details->bot_a < details->top_a && details->bot_b < details->top_b)
	{
		ft_rrr(stack, &details->len);
		return (1);
	}
	if (details->bot_a > details->top_a && details->bot_b > details->top_b)
	{
		ft_rr(stack, &details->len);
		return (1);
	}
	return (0);
}

void ft_check_swp(stack, details)
{
	
}

void ft_check_rotate(t_stack *stack,t_stackdetail *details)
{
	
}

void ft_check_if_swap(t_len details)
{
	
}
