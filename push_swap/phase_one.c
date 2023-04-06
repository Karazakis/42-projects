#include "push_swap.h"

int	ft_best_nbr_a(int *stack, int size, int *arr, int max)
{
	int	pos;
	int j;
	int	i;
	
	j = 0;
	pos = 0;
	i = 0;
	while (j < size)
	{
		i = 0;
		while (stack[j] != arr[i] && i < max)
		{
			if (i == max - 1)
				return (pos);
			i++;
		}
		j++;
		pos++;
	}
	return (-1);
}
