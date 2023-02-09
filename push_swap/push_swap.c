
#include "push_swap.h"

void	ft_phase_one(t_stack stack, t_stackdetail *details, int count)
{
	t_count *counter;
	
	if (ft_check_order(stack.a, count) == 1)
	{
		details->is_ordered = 1;
		return;
	}
	counter = malloc(sizeof(int) * 2);
	ft_check_first_quart(stack, counter, count);
	ft_check_last_quart(stack, counter, count);
	if (counter->first >= counter->second)
	{
		details->half_to_b = 1;
		return;
	}
	else 
	{
		details->half_to_b = 2;
		return;
	}
}

void	ft_phase_two(t_stack *stack, t_stackdetail details)
{
	int moves;
	int halflen;
	int count;
	
	count = details.len.a;
	moves = 0;
	if (details.half_to_b == 2)
		halflen = (details.len.a / 2) + (details.len.a % 2);
	else
		halflen = details.len.a / 2;
	stack->ordered = ft_arr_cpy(stack->a, count);
	quickSort(stack->ordered, 0, count - 1);
	while (moves < halflen)
	{
		if (ft_is_half(stack, details.half_to_b, details.len.ordered_len) == 1)
		{
			ft_pb(stack, &details.len);
			moves++;
		}
		else if (ft_is_frombot(stack, details.half_to_b, details.len.a) == 1)
			ft_ra(stack, &details.len, 0);
		else
			ft_rra(stack, &details.len, 0);
	}
}

void	ft_phase_three(t_stack *stack,t_stackdetail *details)
{
	while (details->is_ordered == 1)
	{
		ft_check_swap_dist(stack, details);
		if (ft_check_move_cat(details) == 0)
			ft_swap_moves(stack, details);
		else
			ft_rotate_moves(stack, details);
		ft_check_orders(stack, details);
	}
}

void	ft_phase_four(t_stack stack, t_stackdetail details)
{
	/* REIMMISSIONE IN A valutare l-ordine di entrambi e ributtare stack b in a*/
}

void	ft_push_swap(char **str, int count)
{
	t_stack stack;
	t_stackdetail details;
	
	details.is_ordered = 0;
	details.half_to_b = 0;
	details.len.a = count - 1;
	details.len.ordered_len = details.len.a;
	details.len.b = 0;
	stack.a = ft_takelist(str, count - 1);
	ft_phase_one(stack, &details, count - 1);
	if (details.is_ordered == 1)
		return;
	ft_phase_two(&stack, details);
	
	printf("stack a\n");
	ft_print_stack(stack.a, details.len.a);
	printf("stack b\n");
	ft_print_stack(stack.b, details.len.b);
	ft_phase_three(&stack, &details);
	/*ft_phase_four(stack, details);*/
}
