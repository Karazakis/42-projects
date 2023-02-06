#include "push_swap.h"

int ft_far_from_top(int *control_arr, t_stack *stack, int count, int half_to_b)
{
	int i;
	
	i = 0;
	while(i < count)
	{
		if ((ft_is_first(control_arr, stack->a[i], count) == 1 && half_to_b == 1)
		 || (ft_is_first(control_arr, stack->a[i], count) == 0 && half_to_b == 2))
			return (i);
		i++;
	}
}

int ft_far_from_bot(int *control_arr, t_stack *stack, int count, int half_to_b)
{
	int i;
	
	i = count - 1;
	while(0 <= i)
	{
		if ((ft_is_first(control_arr, stack->a[i], count) == 1 && half_to_b == 1)
		 || (ft_is_first(control_arr, stack->a[i], count) == 0 && half_to_b == 2))
			return (count - i);
		i--;
	}
}

int ft_is_half(t_stack *stack, int half_to_b, int count)
{
	if (ft_is_first(stack->ordered, stack->a[0], count) == 1 && half_to_b == 1)
		return(1);
	else if((ft_is_first(stack->ordered, stack->a[0], count) == 0) && (half_to_b == 2))
		return(1);
	else
		return (0);
}

int ft_is_frombot(t_stack *stack, int half_to_b, int count)
{
	t_count counter;
	
	counter.first = ft_far_from_top(stack->ordered, stack, count, half_to_b);
	counter.second = ft_far_from_bot(stack->ordered, stack, count, half_to_b);
	if(counter.first <= counter.second)
		return (1);
	else
		return (0);
}
