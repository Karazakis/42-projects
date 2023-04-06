#include "push_swap.h"

int ft_high_is_top(t_stackdetail *details, int side)
{
	if (side == 1)
	{
		if (details->bot_a >= details->top_a && details->bot_a != 0)
			return (1);
		else if (details->bot_a < details->top_a && details->bot_a != 0)
			return (2);
		else
			return (0);
	}
	if (side == 2)
	{
		if (details->bot_b >= details->top_b && details->bot_b != 0)
			return (1);
		else if (details->bot_b < details->top_b && details->bot_b != 0)
			return (2);
		else
			return (0);
	}
}

int	ft_check_high_top(int *stack, int len)
{
	int i;
	int high;
	
	high = ft_highest(stack, len);
	i = 0;
	while(i < len)
	{
		if (stack[i] == high)
			return(len - (i + 1));
		i++;
	}
}

int	ft_check_high_bot(int *stack, int len)
{
	int i;
	int high;
	
	high = ft_highest(stack, len);
	i = 0;
	while(i < len)
	{
		if (stack[i] == high && i + 1 != len)
			return(i + 1);
		else if (stack[i] == high && i + 1 == len)
			return (0);
		i++;
	}
}

int ft_check_order_full(int *stack, int count)
{
	int i;

	i = 0;
	while(i + 1 < count)
	{
		if (stack[i] > stack[i + 1])
			return(0);
		i++;
	}
	return(1);
}

int ft_check_orders_full(t_stack *stack,t_stackdetail *details)
{
	if (ft_check_order_full(stack->a, details->len.a) == 1)
		if (ft_check_order_full(stack->b, details->len.b) == 1)
			return (2);
	return (0);
}

void	ft_check_high_dist(t_stack *stack,t_stackdetail *details)
{
	details->top_a = ft_check_high_top(stack->a, details->len.a);
	details->top_b = ft_check_high_top(stack->b, details->len.b);
	details->bot_a = ft_check_high_bot(stack->a, details->len.a);
	details->bot_b = ft_check_high_bot(stack->b, details->len.b);
}
