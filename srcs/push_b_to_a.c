/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:09:19 by rmorel            #+#    #+#             */
/*   Updated: 2022/02/23 14:35:09 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_all_b_to_a(t_list **alst_a, t_list **alst_b)
{
	int	i;
	int	max;

	i = 0;
	max = ft_lstsize(*alst_b);
	while (i < max)
	{
		push_b_to_a(alst_a, alst_b);
		i++;
	}
	sort_a(alst_a);
	return ;
}

void	push_b_to_a(t_list **alst_a, t_list **alst_b)
{
	t_cost	*cost;
	int		i;

	cost = cost_all_b_to_a(alst_a, alst_b);
	if (!cost)
		return ;
	i = index_min_cost(cost, *alst_b);
	if (cost[i].a_cost * cost[i].b_cost > 0)
		positive_case(alst_a, alst_b, cost, i);
	else if (cost[i].a_cost * cost[i].b_cost < 0)
		negative_case(alst_a, alst_b, cost, i);
	else
		null_case(alst_a, alst_b, cost, i);
	free(cost);
	return ;
}

void	negative_case(t_list **alst_a, t_list **alst_b, t_cost *cost, int i)
{
	int	a;
	int	b;

	a = -1;
	b = -1;
	if (cost[i].a_cost < 0)
	{
		while (++a < abs(cost[i].a_cost))
			rra(alst_a);
		while (++b < abs(cost[i].b_cost))
			rb(alst_b);
	}
	else
	{
		while (++a < abs(cost[i].a_cost))
			ra(alst_a);
		while (++b < abs(cost[i].b_cost))
			rrb(alst_b);
	}
	pa(alst_a, alst_b);
	return ;
}

void	positive_case(t_list **alst_a, t_list **alst_b, t_cost *cost, int i)
{
	if (cost[i].a_cost < 0)
		both_neg(alst_a, alst_b, cost, i);
	else
		both_pos(alst_a, alst_b, cost, i);
	pa(alst_a, alst_b);
	return ;
}

void	both_pos(t_list **alst_a, t_list **alst_b, t_cost *cost, int i)
{
	int	x;
	int	y;
	int	mi;
	int	ma;

	x = -1;
	y = -1;
	mi = min(abs(cost[i].a_cost), abs(cost[i].b_cost));
	ma = max(abs(cost[i].a_cost), abs(cost[i].b_cost));
	while (++x < mi)
		rr(alst_a, alst_b);
	while (++y < ma - mi)
	{
		if (cost[i].a_cost < cost[i].b_cost)
			rb(alst_b);
		else
			ra(alst_a);
	}
	return ;
}
