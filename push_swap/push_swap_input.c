#include "push_swap.h"

int ft_atoi(char *str)
{
	int i;
	int nb;
	
	i = 0;
	nb = 0;
	while(str[i])
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return(nb);
}

int *ft_takelist(char **str, int count)
{
	int *stack;
	int i;
	
	i = 1;
	stack = (int *)malloc(sizeof(int) * count);
	while(i <= count)
	{
		stack[i - 1] = ft_atoi(str[i]);
		i++;
	}
	return(stack);
}
