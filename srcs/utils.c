/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:33:59 by rmorel            #+#    #+#             */
/*   Updated: 2022/02/08 17:11:08 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	abs(int i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

int	max_list(t_list **alst)
{
	t_list	*tmp;
	int		max;

	max = -2147483648;
	tmp = *alst;
	while ((*alst)->next)
	{	
		if ((*alst)->n > max)
			max = (*alst)->n;
		*alst = (*alst)->next;
	}
	if (*alst && (*alst)->n > max)
		max = (*alst)->n;
	*alst = tmp;
	return (max);
}

int	min_list(t_list **alst)
{
	t_list	*tmp;
	int		min;

	min = 2147483647;
	tmp = *alst;
	while ((*alst)->next)
	{	
		if ((*alst)->n < min)
			min = (*alst)->n;
		*alst = (*alst)->next;
	}
	if (*alst && (*alst)->n < min)
		min = (*alst)->n;
	*alst = tmp;
	return (min);
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
