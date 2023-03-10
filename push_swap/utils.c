#include "push_swap.h"

void ft_putstr(char *str)
{
	int i;
	
	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void ft_print_stack(int *stack, int count)
{
	int i;
	
	i = 0;
	while(i < count)
	{
		printf("%d\n", stack[i]);
		i++;
	}
}

int ft_arrlen(int *arr)
{
	int i;
	
	i = 0;
	while(arr[i])
		i++;
	return(i);
}

int *ft_arr_cpy(int *arr, int count)
{
	int *cpy;
	int i;
	
	i = 0;
	cpy = (int *)malloc(sizeof(int) * count);
	while (i < count)
	{
		cpy[i] = arr[i];
		i++;
	}
	return (cpy);
}

int *ft_arr_cat(int *arr, int to_cat, int count, int side)
{
	int *cpy;
	
	if (side == 1)
		cpy = ft_arr_cat_front(arr, to_cat, count);
	else
		cpy = ft_arr_cat_tail(arr, to_cat, count);
	return (cpy);
}

int *ft_arr_cat_front(int *arr, int to_cat, int count)
{
	int *cpy;
	int i;
	
	i = 0;
	cpy = (int *)malloc(sizeof(int) * count + 1);
	cpy[0] = to_cat;
	while (i <= count && count != 0)
	{
		cpy[i + 1] = arr[i];
		i++;
	}
	return (cpy);
}

int *ft_arr_cat_tail(int *arr, int to_cat, int count)
{
	int *cpy;
	int i;
	
	i = 0;
	cpy = (int *)malloc(sizeof(int) * count + 1);
	while (i < count)
	{
		cpy[i] = arr[i];
		i++;
	}
	cpy[i] = to_cat;
	return (cpy);
}
