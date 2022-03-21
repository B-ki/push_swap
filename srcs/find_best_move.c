/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 01:15:52 by rmorel            #+#    #+#             */
/*   Updated: 2022/02/23 14:35:09 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	int_after_in_lst(t_list **alst, int n)
{
	t_list	*tmp;
	int		int_a;

	tmp = *alst;
	int_a = max_list(alst);
	while (tmp->next)
	{
		if (tmp->n == n)
			return (n);
		else if (tmp->n <= int_a && tmp->n > n)
			int_a = tmp->n;
		tmp = tmp->next;
	}
	if (tmp->n <= int_a && tmp->n > n)
		int_a = tmp->n;
	return (int_a);
}

int	position_in_list(t_list **alst_a, int n, int int_a, int i)
{
	t_list	*tmp;

	tmp = *alst_a;
	while (tmp->next)
	{
		if (int_a == tmp->n && int_a >= n)
			return (convert_position(alst_a, i));
		else if (int_a == tmp->n && int_a < n)
		{
			while (tmp->next && tmp->next->n == int_a)
			{
				i++;
				tmp = tmp->next;
			}
			return (convert_position(alst_a, i + 1));
		}
		i++;
		tmp = tmp->next;
	}
	if (int_a == tmp->n && int_a >= n)
		return (convert_position(alst_a, i));
	else if (int_a == tmp->n && int_a < n)
		return (convert_position(alst_a, i + 1));
	return (convert_position(alst_a, 0));
}

int	convert_position(t_list **alst, int i)
{
	int	size;

	size = ft_lstsize(*alst);
	if (i < (size + 1) / 2)
		return (i);
	else
		return (i - size);
}

t_cost	*cost_all_b_to_a(t_list **alst_a, t_list **alst_b)
{
	t_cost	*cost;
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *alst_b;
	cost = malloc(sizeof(*cost) * ft_lstsize(*alst_b));
	if (!cost)
		return (NULL);
	while ((*alst_b)->next)
	{
		cost[i].b_cost = cost_to_top(&tmp, (*alst_b)->n);
		cost[i].a_cost = position_in_list(alst_a, (*alst_b)->n,
				int_after_in_lst(alst_a, (*alst_b)->n), 0);
		cost[i].t_cost = abs(cost[i].a_cost) + abs(cost[i].b_cost);
		*alst_b = (*alst_b)->next;
		i++;
	}
	cost[i].b_cost = cost_to_top(&tmp, (*alst_b)->n);
	cost[i].a_cost = position_in_list(alst_a, (*alst_b)->n,
			int_after_in_lst(alst_a, (*alst_b)->n), 0);
	cost[i].t_cost = abs(cost[i].a_cost) + abs(cost[i].b_cost);
	*alst_b = tmp;
	return (cost);
}

int	index_min_cost(t_cost *cost, t_list *lst_b)
{
	int	i;
	int	index_min;
	int	size;
	int	min;

	i = 0;
	index_min = 0;
	min = cost[0].t_cost;
	size = ft_lstsize(lst_b);
	while (i < size)
	{
		if (cost[i].t_cost < min)
		{
			min = cost[i].t_cost;
			index_min = i;
		}
		i++;
	}
	return (index_min);
}
