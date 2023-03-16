
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
	counter->first = 0;
	counter->second = 0;
	ft_check_first_quart(stack, counter, count);
	ft_check_last_quart(stack, counter, count);
	if (counter->first >= counter->second)
	{
		free(counter);
		details->half_to_b = 1;
		return;
	}
	else 
	{
		free(counter);
		details->half_to_b = 2;
		return;
	}
}


void	ft_phase_two(t_stack *stack, t_stackdetail *details)
{
	int moves;
	int halflen;
	int count;
	
	count = details->len.a;
	moves = 0;
	if (details->half_to_b == 2)
		halflen = (details->len.a / 2) + (details->len.a % 2);
	else
		halflen = details->len.a / 2;
	stack->ordered = ft_arr_cpy(stack->a, details->len.a + 1);
	quickSort(stack->ordered, 0, count - 1);
	while (moves < halflen)
	{
		printf("pre stack a len %d\n", details->len.a);
		ft_print_stack(stack->a, details->len.a);
		printf("pre stack b len %d\n", details->len.b);
		ft_print_stack(stack->b, details->len.b);
		if (ft_is_half(stack, details->half_to_b, details->len.ordered_len) == 1)
		{
			ft_pb(stack, &details->len);
			moves++;
		}
		else if (ft_is_frombot(stack, details->half_to_b, details) == 1)
			ft_ra(stack, &details->len, 0);
		else
			ft_rra(stack, &details->len, 0);
		printf("post stack a len %d\n", details->len.a);
		ft_print_stack(stack->a, details->len.a);
		printf("post stack b len %d\n", details->len.b);
		ft_print_stack(stack->b, details->len.b);
	}
}

/*void	ft_phase_three(t_stack *stack,t_stackdetail *details)
{
	int i;
	
	i = 0;
	
	while (details->is_ordered != 1)
	{
		ft_check_swap_dist(stack, details);
		printf("is swap a %d swap dist %d from bot from top %d\n", details->a_is_swap, details->bot_a, details->top_a);
		printf("is swap b %d swap dist %d from bot from top %d\n", details->b_is_swap, details->bot_b, details->top_b);
		printf("fase in 3 stack a\n");
		printf("fase in 3 stack b\n");
		if (ft_check_move_cat(details) == 0)
			ft_swap_moves(stack, details);
		else
			ft_rotate_moves(stack, details);
		details->is_ordered = ft_check_orders(stack, details);
		i++;
	}
}*/

/*void	ft_phase_four(t_stack stack, t_stackdetail details)
{
	 REIMMISSIONE IN A valutare l-ordine di entrambi e ributtare stack b in a
}*/

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
	ft_phase_two(&stack, &details);
	//ft_phase_three(&stack, &details);
	/*printf("fase 3 stack a\n");
	ft_print_stack(stack.a, details.len.a);
	printf("fase 2 stack b\n");
	ft_print_stack(stack.b, details.len.b);*/
	
	free(stack.a);
	free(stack.b);
	free(stack.ordered);
	/*ft_phase_four(stack, details);*/
}
