#include "push_swap.h"

void ft_pb(t_stack *stack, t_len *len)
{
	int to_push;
	
	to_push = stack->a[0];
	ft_rmv_frst_el(stack, len, 1);
	len->a--;
	ft_push_elem_in_front(stack, to_push, len, 2);
	len->b++;
	ft_putstr("pb\n");
}

void ft_pa(t_stack *stack, t_len *len)
{
	int to_push;
	
	to_push = stack->b[0];
	ft_rmv_frst_el(stack, len, 2);
	len->b--;
	ft_push_elem_in_front(stack, to_push, len, 1);
	len->a++;
	ft_putstr("pa\n");
}

void ft_rb(t_stack *stack, t_len *len, int flg)
{
	int to_shift;
	
	to_shift = stack->b[0];
	ft_rmv_frst_el(stack, len, 2);
	len->b--;
	ft_push_elem_in_tail(stack, to_shift, len, 2);
	len->b++;
	if (flg == 0)
		ft_putstr("rb\n");
}

void ft_ra(t_stack *stack, t_len *len, int flg)
{
	int to_shift;
	
	to_shift = stack->a[0];
	ft_rmv_frst_el(stack, len, 1);
	len->a--;
	ft_push_elem_in_tail(stack, to_shift, len, 1);
	len->a++;
	if (flg == 0)
		ft_putstr("ra\n");
}

void ft_rr(t_stack *stack, t_len *len)
{
	ft_ra(stack, len, 1);
	ft_rb(stack, len, 1);
	ft_putstr("rr\n");
}

void ft_rrb(t_stack *stack, t_len *len, int flg)
{
	int to_shift;
	
	to_shift = stack->b[len->b - 1];
	ft_rmv_lst_el(stack, len, 2);
	ft_push_elem_in_front(stack, to_shift, len, 2);
	if (flg == 0)
		ft_putstr("rrb\n");
}

void ft_rra(t_stack *stack, t_len *len, int flg)
{
	int to_shift;
	
	to_shift = stack->a[len->a - 1];
	ft_rmv_lst_el(stack, len, 1);
	len->a--;
	ft_push_elem_in_front(stack, to_shift, len, 1);
	len->a++;
	if (flg == 0)
		ft_putstr("rra\n");
}

void ft_rrr(t_stack *stack, t_len *len)
{
	ft_rra(stack, len, 1);
	ft_rrb(stack, len, 1);
	ft_putstr("rrr\n");
}

void ft_sa(t_stack *stack, int flg)
{
	int swap;
	
	swap = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = swap;
	if (flg == 0)
		ft_putstr("sa\n");
}

void ft_sb(t_stack *stack, int flg)
{
	int swap;
	
	swap = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = swap;
	if (flg == 0)
		ft_putstr("sb\n");
}

void ft_ss(t_stack *stack)
{
	ft_sa(stack, 1);
	ft_sb(stack, 1);
	ft_putstr("ss\n");
}
