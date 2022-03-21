/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:09:57 by rmorel            #+#    #+#             */
/*   Updated: 2022/02/15 11:00:20 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	median(t_list **alst, int max)
{
	int		i;
	int		median;

	i = 0;
	median = min_list_not_in_lis(alst);
	while (i < max / 2)
	{
		median = int_after_not_in_lis(alst, median);
		i++;
	}
	return (median);
}

int	int_after_not_in_lis(t_list **alst, int n)
{
	t_list	*tmp;
	int		int_a;

	tmp = *alst;
	int_a = max_list(alst);
	while (tmp->next)
	{
		if (tmp->n < int_a && tmp->n > n && tmp->in_lis == 0)
			int_a = tmp->n;
		tmp = tmp->next;
	}
	if (tmp->n < int_a && tmp->n > n && tmp->in_lis == 0)
		int_a = tmp->n;
	return (int_a);
}

int	min_list_not_in_lis(t_list **alst)
{
	t_list	*tmp;
	int		min;

	min = 2147483647;
	tmp = *alst;
	while (tmp->next)
	{	
		if (tmp->n < min && tmp->in_lis != 1)
			min = tmp->n;
		tmp = tmp->next;
	}
	if (tmp && tmp->n < min && tmp->in_lis != 1)
		min = tmp->n;
	return (min);
}
