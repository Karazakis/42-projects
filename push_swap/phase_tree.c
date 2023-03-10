#include "push_swap.h"

void ft_check_swap_dist(t_stack *stack,t_stackdetail *details)
{
	int last_a;
	int last_b;
	
	last_a = ft_highest(stack->a, details->len.a);
	last_b = ft_highest(stack->b, details->len.b);
	ft_check_swp(stack, details);
	ft_check_rotate_top(stack->a, details, 1, last_a);
	ft_check_rotate_bot(stack->a, details, 1, last_a);
	ft_check_rotate_bot(stack->b, details, 2, last_b);
	ft_check_rotate_top(stack->b, details, 2, last_b);
}

int	ft_check_move_cat(t_stackdetail *details)
{
	if (details->a_is_swap == 1 && details->b_is_swap == 1)
		return (0);
	if (ft_check_if_swap(*details) == 1)
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

int ft_check_orders(t_stack *stack,t_stackdetail *details)
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

void ft_check_swp(t_stack *stack,t_stackdetail *details)
{
	int last_a;
	int last_b;
	
	last_a = ft_highest(stack->a, details->len.a);
	last_b = ft_highest(stack->b, details->len.b);
	
	if (stack->a[0] == last_a && stack->a[0] > stack->a[1])
		details->a_is_swap = 1;
	if (stack->b[0] == last_b && stack->b[0] > stack->b[1])
		details->b_is_swap = 1;
}

void ft_check_rotate_top(int *stack,t_stackdetail *details, int to_stack, int highest)
{
	int flg;
	int i;
	
	flg = 1;
	i = 0;
	while (flg == 1)
	{
		if (stack[i] > stack[i + 1] && stack[i] != highest)
		{
			if (to_stack == 1)
				details->top_a = i;
			else
				details->top_b = i;
			flg = 0;
		}
		i++;
	}
}

void ft_check_rotate_bot(int *stack,t_stackdetail *details, int to_stack, int highest)
{
	int flg;
	int distance;
	int i;
	
	flg = 1;
	if (to_stack == 1)
		i = details->len.a - 1;
	else
		i = details->len.b - 1;
	distance = 0;
	if (stack[0] < stack[i])
	{
		flg = 0;
		if (to_stack == 1)
			details->bot_a = 1;
		else
			details->bot_b = 1;
	}
	while (flg == 1)
	{
		if (stack[i] > stack[i + 1])
		{
			if (to_stack == 1)
				details->top_a = i;
			else
				details->top_b = i;
			flg = 0;
		}
		distance++;
		i--;
	}
}

int ft_check_if_swap(t_stackdetail details)
{
	if (details.a_is_swap == 1)
		if (details.bot_a > 1 || details.top_a > 1)
			return (1);
	if (details.b_is_swap == 1)
		if (details.bot_b > 1 || details.top_b > 1)
			return (1);
	return (0);
}

int ft_highest(int *stack, int len)
{
	int i;
	int temp;
	
	i = 0;
	temp = stack[i];
	while (i < len)
	{
		if (temp < stack[i])
			temp = stack[i];
		i++;
	}
	return (temp);
}
