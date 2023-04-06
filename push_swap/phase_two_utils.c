#include "push_swap.h"


int	ft_the_needed_b(int max, int size)
{
	if (max > (size / 2))
		max = max - size;
	return (max);
}

int	ft_the_needed_a(t_stack *stack, t_stackdetail *details, int cont, int size)
{
	int		i;
	int		j;

	i = ft_max_or_min(stack, details, cont, size);
	j = 0;
	if (i != size + 1)
		return (ft_the_needed_b(i, size));
	while (j < details->len.a - 1)
		j++;
	if (cont < stack->a[0] && cont > stack->a[j])
		return (0);
	i = 1;
	j = 0;
	while (!(cont > stack->a[j] && cont < stack->a[j + 1]))
	{
		j++;
		i++;
	}
	return (ft_the_needed_b(i, size));
}

int	*ft_intcpy(int	*arr, int size)
{
	int	i;
	int	*cpy;

	i = 0;
	cpy = (int *) malloc (sizeof(int) * size);
	while (i < size)
	{
		cpy[i] = arr[i];
		i++;
	}
	return (cpy);
}

int	ft_max_or_min(t_stack *stack, t_stackdetail *details, int cont, int size)
{
	int	max_n_min[5];
	int i;

	max_n_min[0] = stack->a[0];
	max_n_min[1] = stack->a[0];
	max_n_min[2] = 0;
	max_n_min[3] = 0;
	max_n_min[4] = 1;
	i = 0;
	while (i < details->len.a)
	{
		if (stack->a[i] >= max_n_min[0])
		{
			max_n_min[0] = stack->a[i];
			max_n_min[2] = max_n_min[4];
		}
		if (stack->a[i] < max_n_min[1])
		{
			max_n_min[1] = stack->a[i];
			max_n_min[3] = max_n_min[4] - 1;
		}
		i++;
		max_n_min[4]++;
	}
	return (return_max_or_min(cont, max_n_min, size));
}

int	return_max_or_min(int cont, int *max_n_min, int size)
{
	if (cont > max_n_min[0])
		return (max_n_min[2]);
	if (cont < max_n_min[1])
		return (max_n_min[3]);
	return (size + 1);
}
