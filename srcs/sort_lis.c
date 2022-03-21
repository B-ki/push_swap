/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:19:18 by rmorel            #+#    #+#             */
/*   Updated: 2022/02/23 14:35:04 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_one_lis_b(t_list **alst_a, t_list **alst_b, int lis_length, int ac)
{
	int	i;
	int	min_cost;
	int	max;

	i = 0;
	max = ft_lstsize(*alst_a) - lis_length;
	if (ac > 102)
		min_cost = min_cost_lis_to_top_med(alst_a, median(alst_a, max));
	else
		min_cost = min_cost_lis_to_top(alst_a);
	if (min_cost > 0 && min_cost < ft_lstsize(*alst_a))
	{	
		while (++i <= abs(min_cost))
			ra(alst_a);
	}
	if (min_cost < 0)
	{
		min_cost *= -1;
		while (++i <= abs(min_cost))
			rra(alst_a);
	}
	if (min_cost < ft_lstsize(*alst_a))
		pb(alst_a, alst_b);
}

void	push_all_lis_b(t_list **alst_a, t_list **alst_b, t_lis *lis, int ac)
{
	int	i;
	int	max;

	i = 0;
	max = ft_lstsize(*alst_a) - lis->max_length;
	while (i < max)
	{
		push_one_lis_b(alst_a, alst_b, lis->max_length, ac);
		i++;
	}
}

int	min_cost_lis_to_top(t_list **alst)
{
	int		min_cost;
	t_list	*tmp;

	min_cost = ft_lstsize(*alst) + 1;
	tmp = *alst;
	while (tmp->next)
	{
		if (abs(cost_to_top(alst, tmp->n)) < abs(min_cost)
			&& tmp->in_lis != 1)
			min_cost = cost_to_top(alst, tmp->n);
		tmp = tmp->next;
	}
	if (abs(cost_to_top(alst, tmp->n)) < abs(min_cost)
		&& tmp->in_lis != 1)
		min_cost = cost_to_top(alst, tmp->n);
	return (min_cost);
}
