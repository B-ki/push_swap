/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:09:19 by rmorel            #+#    #+#             */
/*   Updated: 2022/02/15 11:23:31 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	both_neg(t_list **alst_a, t_list **alst_b, t_cost *cost, int i)
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
		rrr(alst_a, alst_b);
	while (++y < ma - mi)
	{
		if (abs(cost[i].a_cost) < abs(cost[i].b_cost))
			rrb(alst_b);
		else
			rra(alst_a);
	}
	return ;
}

void	null_case(t_list **alst_a, t_list **alst_b, t_cost *cost, int i)
{
	if (cost[i].a_cost == 0 && cost[i].b_cost == 0)
		pa(alst_a, alst_b);
	else if (cost[i].a_cost == 0)
		a_null(alst_a, alst_b, cost, i);
	else if (cost[i].b_cost == 0)
		b_null(alst_a, alst_b, cost, i);
	return ;
}

void	a_null(t_list **alst_a, t_list **alst_b, t_cost *cost, int i)
{
	int	b;

	b = -1;
	if (cost[i].b_cost < 0)
	{
		while (++b < abs(cost[i].b_cost))
			rrb(alst_b);
	}
	else
	{
		while (++b < cost[i].b_cost)
			rb(alst_b);
	}
	pa(alst_a, alst_b);
	return ;
}

void	b_null(t_list **alst_a, t_list **alst_b, t_cost *cost, int i)
{
	int	a;

	a = -1;
	if (cost[i].a_cost < 0)
	{
		while (++a < abs(cost[i].a_cost))
			rra(alst_a);
	}
	else
	{
		while (++a < cost[i].a_cost)
			ra(alst_a);
	}
	pa(alst_a, alst_b);
	return ;
}

void	sort_a(t_list **alst_a)
{
	int	i;
	int	cost;

	i = -1;
	cost = cost_to_top(alst_a, min_list(alst_a));
	if (cost < 0)
	{
		while (++i < abs(cost))
			rra(alst_a);
	}
	else if (cost > 0)
	{
		while (++i < abs(cost))
			ra(alst_a);
	}
	return ;
}
