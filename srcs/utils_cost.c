/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:33:59 by rmorel            #+#    #+#             */
/*   Updated: 2022/02/17 15:25:51 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	cost_to_top(t_list **alst, int m)
{
	int		i;
	int		size;
	t_list	*tmp;

	i = 0;
	size = ft_lstsize(*alst);
	tmp = *alst;
	while ((*alst)->next && (*alst)->n != m)
	{
		i++;
		(*alst) = (*alst)->next;
	}
	*alst = tmp;
	if (i < (size + 1) / 2)
		return (i);
	else
		return (i - size);
}

int	belong_to_lis(int n, t_lis *lis)
{
	int	i;

	i = 0;
	while (i < lis->max_length)
	{
		if (n == lis->final_lis[i])
			return (1);
		else
			i++;
	}
	return (0);
}

int	min_cost_lis_to_top_med(t_list **alst, int median)
{
	int		min_cost;
	t_list	*tmp;

	min_cost = ft_lstsize(*alst) + 1;
	tmp = *alst;
	while (tmp->next)
	{
		if (abs(cost_to_top(alst, tmp->n)) < abs(min_cost)
			&& tmp->in_lis != 1 && tmp->n >= median)
			min_cost = cost_to_top(alst, tmp->n);
		tmp = tmp->next;
	}
	if (abs(cost_to_top(alst, tmp->n)) < abs(min_cost)
		&& tmp->in_lis != 1 && tmp->n >= median)
		min_cost = cost_to_top(alst, tmp->n);
	return (min_cost);
}

void	print_cost(t_cost *cost, t_list **alst_b)
{
	int	i;

	i = 0;
	while (i < ft_lstsize(*alst_b))
	{
		ft_printf("a_cost[%d] = %d\n", i, cost[i].a_cost);
		ft_printf("b_cost[%d] = %d\n", i, cost[i].b_cost);
		ft_printf("t_cost[%d] = %d\n", i, cost[i].t_cost);
		i++;
	}
}

int	check_if_sorted(t_list **alst)
{
	int		check;
	t_list	*tmp;

	tmp = *alst;
	check = tmp->n;
	tmp = tmp->next;
	if (!tmp)
		return (1);
	if (tmp->n < check)
		return (0);
	while (tmp->next)
	{
		if (tmp->n < check)
			return (0);
		check = tmp->n;
		tmp = tmp->next;
	}
	if (tmp->n < check)
		return (0);
	return (1);
}
