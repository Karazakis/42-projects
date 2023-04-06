#include "push_swap.h"

int	ft_best_nbr_b(t_stack *stack, t_stackdetail *details)
{
	int		*arr_b;
	int		*arr_a;
	int		i;
	int		j;

	i = -1;
	j = 0;
	arr_a = (int *) malloc (sizeof(int) * (details->len.a + 100));
	arr_b = (int *) malloc (sizeof(int) * (details->len.b + 100));
	while (++i < details->len.b)
	{
		arr_b[i] = ft_the_needed_b(i, details->len.b);
	}
	i = -1;
	while (++i < details->len.b && j < details->len.b)
	{
		arr_a[i] = ft_the_needed_a(stack, details, stack->b[j], details->len.a);
		j++;
	}
	i = ft_best_comb(ft_intcpy(arr_a, details->len.b),
			ft_intcpy(arr_b, details->len.b), details->len.b);
	i = ft_move_a(arr_a[i], arr_b[i], stack, details);
	free(arr_a);
	free(arr_b);
	return (i);
}

int	ft_best_comb_helper(int *arr_a, int *arr_b, int *tmp, int size)
{
	int	i;
	int	pos;

	pos = 0;
	i = -1;
	while (++i < size)
	{
		if (tmp[i] < tmp[pos])
			pos = i;
	}
	free(arr_a);
	free(arr_b);
	free(tmp);
	return (pos);
}

int	ft_best_comb(int *arr_a, int *arr_b, int size)
{
	int	*tmp;
	int	i;

	i = -1;
	tmp = (int *) malloc (sizeof(int) * size);
	while (++i < size)
	{
		if ((arr_a[i] > 0 && arr_b[i] > 0)
			|| (arr_a[i] < 0 && arr_b[i] < 0))
			tmp[i] = ft_max_nbr(arr_a[i], arr_b[i]);
		else
		{
			if (arr_a[i] < 0)
				arr_a[i] *= -1;
			if (arr_b[i] < 0)
				arr_b[i] *= -1;
			tmp[i] = arr_a[i] + arr_b[i];
		}
	}
	return (ft_best_comb_helper(arr_a, arr_b, tmp, size));
}

int	ft_move_a(int a, int b, t_stack *stack, t_stackdetail *details)
{
	while (a < 0 && b < 0)
	{
		ft_rrr(stack, &details->len);
		a++;
		b++;
	}
	while (a > 0 && b > 0)
	{
		ft_rr(stack, &details->len);
		a--;
		b--;
	}
	if (a < 0)
		while (a++ < 0)
			ft_rra(stack, &details->len, 0);
	else if (a > 0)
		while (a-- > 0)
			ft_ra(stack, &details->len, 0);
	return (b);
}
