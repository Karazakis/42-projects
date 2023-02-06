#include "push_swap.h"

void ft_rmv_frst_el(t_stack *stack, t_len *len, int side)
{
	int *cpy;
	
	if (side == 1)
		cpy = ft_arr_cpy(stack->a + 1, len->a - 1);
	else
		cpy = ft_arr_cpy(stack->b + 1, len->b - 1);
	if (side == 1)
	{
		free(stack->a);
		stack->a = cpy;
	}
	else
	{
		free(stack->b);
		stack->b = cpy;
	}
}

void ft_rmv_lst_el(t_stack *stack, t_len *len, int side)
{
	int *cpy;
	
	if (side == 1)
		cpy = ft_arr_cpy(stack->a, len->a - 1);
	else
		cpy = ft_arr_cpy(stack->b, len->b - 1);
	if (side == 1)
	{
		free(stack->a);
		stack->a = cpy;
	}
	else
	{
		free(stack->b);
		stack->b = cpy;
	}
}

void ft_push_elem_in_front(t_stack *stack, int to_shift, t_len *len, int side)
{
	int *cpy;
	
	if (side == 1)
		cpy = ft_arr_cat(stack->a, to_shift, len->a, 1);
	else
		cpy = ft_arr_cat(stack->b, to_shift, len->b, 1);
	if (side == 1)
	{
		free(stack->a);
		stack->a = cpy;
	}
	else
	{
		if (len->b != 0)
			free(stack->b);
		stack->b = cpy;
	}
}

void ft_push_elem_in_tail(t_stack *stack, int to_shift, t_len *len, int side)
{
	int *cpy;
	
	if (side == 1)
		cpy = ft_arr_cat(stack->a, to_shift, len->a, 2);
	else
		cpy = ft_arr_cat(stack->b, to_shift, len->b, 2);
	if (side == 1)
	{
		free(stack->a);
		stack->a = cpy;
	}
	else
	{
		free(stack->b);
		stack->b = cpy;
	}
}
