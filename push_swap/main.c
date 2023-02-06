/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:59:32 by akoutsou          #+#    #+#             */
/*   Updated: 2023/01/10 12:44:13 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_isnumber(char *str)
{
	int i;
	
	i = 0;
	while(str[i])
	{
		if(!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int ft_checkinput(char **input)
{
	int i;
	
	i = 1;
	while (input[i])
	{
		if (ft_isnumber(input[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (ft_checkinput(argv) == 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	ft_push_swap(argv, argc);
	return (0);
}
