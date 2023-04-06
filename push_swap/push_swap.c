#include "push_swap.h"

void	ft_phase_one(t_stack *stack, t_stackdetail *details, int *arr, int max)
{
	int	i;

	i = ft_best_nbr_a(stack->a, details->len.a, arr, max);
	while (i != -1)
	{
		if (i > 0)
		{
			while (i-- > 0)
				ft_ra(stack, &details->len, 0);
		}
		ft_pb(stack, &details->len);
		i = ft_best_nbr_a(stack->a, details->len.a, arr, max);
	}
}


void	ft_phase_two(t_stack *stack, t_stackdetail *details)
{
	int	i;
	int	size_a;
	int	size_b;

	i = 0;

	while (details->len.b != 0)
	{
		i = ft_best_nbr_b(stack, details);
		if (i < 0)
			while (i++ < 0)
				ft_rrb(stack, &details->len, 0);
		else if (i > 0)
			while (i-- > 0)
				ft_rb(stack, &details->len, 0);
		ft_pa(stack, &details->len);
	}
}

void	ft_phase_three(t_stack *stack,t_stackdetail *details)
{	
	int		pos;
	int		pos_min;
	int		min;

	pos_min = 0;
	pos = 0;
	min = stack->a[pos];
	while (pos < details->len.a)
	{
		if (min > stack->a[pos])
		{
			min = stack->a[pos];
			pos_min = pos;
		}
		pos++;
	}
	pos = ft_the_needed_b(pos_min, details->len.a);
	ft_move_a(pos, 0, stack, details);
}

void	ft_push_swap(char **str, int count)
{
	t_stack stack;
	t_stackdetail details;
	int *arr;
	int i;
	
	
	details.len.a = count - 1;
	details.len.b = 0;
	i = 0;
	stack.a = ft_takelist(str, count - 1);
	arr = ft_create_lis(stack.a, count - 1, &i);
	ft_phase_one(&stack, &details, arr, i);
	ft_phase_two(&stack, &details);
	ft_phase_three(&stack, &details);
	free(stack.a);
	free(stack.b);
	free(arr);
}
