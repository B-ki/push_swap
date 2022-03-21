/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:33:07 by rmorel            #+#    #+#             */
/*   Updated: 2022/03/01 14:16:42 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_few(t_list **alst_a, t_list **alst_b)
{
	if (ft_lstsize(*alst_a) <= 3)
		sort_3(alst_a);
	else
	{
		if (check_if_sorted(alst_a))
			return ;
		sort_5(alst_a, alst_b);
	}
}

void	sort_3(t_list **alst_a)
{
	if (check_if_sorted(alst_a))
		return ;
	if (int_index(alst_a, 0) < int_index(alst_a, 1))
	{
		rra(alst_a);
		if (!check_if_sorted(alst_a))
			sa(alst_a);
		return ;
	}
	if (int_index(alst_a, 0) == max_list(alst_a))
	{
		ra(alst_a);
		if (!check_if_sorted(alst_a))
			sa(alst_a);
		return ;
	}
	else
		sa(alst_a);
	return ;
}

void	sort_5(t_list **alst_a, t_list **alst_b)
{
	pb(alst_a, alst_b);
	pb(alst_a, alst_b);
	sort_3(alst_a);
	push_all_b_to_a(alst_a, alst_b);
	return ;
}

int	int_index(t_list **alst, int i)
{
	t_list	*tmp;

	tmp = *alst;
	while (i > 0)
	{
		tmp = tmp->next;
		i--;
	}
	return (tmp->n);
}

int	get_index(t_list **alst, int n)
{
	t_list	*tmp;
	int		i;

	tmp = *alst;
	i = 0;
	while (tmp->next)
	{
		if (tmp->n == n)
			return (i);
		else
		{
			i++;
			tmp = tmp->next;
		}
	}
	if (tmp->n == n)
		return (i);
	else
		return (-1);
}
