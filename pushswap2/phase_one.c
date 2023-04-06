#include "push_swap.h"

int ft_check_order(int *stack, int count)
{
	int i;
	int high;
	
	
	high = ft_highest(stack, count);
	i = 0;
	while(i + 1 < count)
	{
		if (stack[i] > stack[i + 1] && stack[i] != high)
			return(0);
		i++;
	}
	return(1);
}

int ft_is_first(int *arr, int to_check, int count)
{
	int i;
	
	i = 0;
	while(i < (count / 2))
	{
		if (arr[i] == to_check)
			return(1);
		i++;
	}
	return (0);
}

void ft_check_first_quart(t_stack stack, t_count *counter, int count)
{
	int start;
	int end;
	int *control_arr;
	
	start = 0;
	if (count > 4)
		end = (count / 4);
	else
		end = 1;
	control_arr = ft_arr_cpy(stack.a, count);
	quickSort(control_arr, 0, count - 1);
	while(start < end)
	{	
		if (ft_is_first(control_arr, stack.a[start], count) == 1)
			counter->first++;
		else
			counter->second++;
		start++;
	}
	free(control_arr);
}

void ft_check_last_quart(t_stack stack, t_count *counter, int count)
{
	int start;
	int end;
	int *control_arr;
	
	if (count > 4)
		start = count - (count / 4);
	else
		start = 2;
	end = count - 1;
	control_arr = ft_arr_cpy(stack.a, count);
	quickSort(control_arr, 0, count - 1);
	while(start <= end)
	{
		if (ft_is_first(control_arr, stack.a[start], count) == 1)
			counter->first++;
		else
			counter->second++;
		start++;
	}
	free(control_arr);
}
