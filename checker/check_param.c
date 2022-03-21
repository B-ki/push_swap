/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:08:07 by rmorel            #+#    #+#             */
/*   Updated: 2022/03/01 14:27:03 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_str_is_int(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == '-' && str[i + 1])
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		if (j > 11)
			return (0);
		else if (ft_isdigit(str[i]))
			j++;
		i++;
	}
	if (ft_atol(str) > 2147483647 || ft_atol(str) < -2147483648)
		return (0);
	return (1);
}

int	check_no_double(int ac, char **av)
{
	int	i;
	int	j;

	i = 2;
	j = 1;
	while (i <= ac - 1)
	{
		while (j < i)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		j = 1;
		i++;
	}
	return (1);
}

int	check_multiple_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!check_str_is_int(av[i]) || !av[i])
			return (0);
		if (!check_no_double(ac, av))
			return (0);
		else
			i++;
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	if (ac < 2)
		return (-1);
	else
	{
		if (!check_multiple_args(ac, av))
			return (0);
		else
			return (1);
	}
}
