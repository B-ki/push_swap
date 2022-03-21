/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:39:26 by rmorel            #+#    #+#             */
/*   Updated: 2022/02/17 15:00:26 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_list **alst)
{
	int	tmp;

	tmp = (*alst)->n;
	(*alst)->n = (*alst)->next->n;
	(*alst)->next->n = tmp;
}

void	sa(t_list **alst_a)
{
	if (*alst_a && (*alst_a)->next)
	{
		swap(alst_a);
		ft_printf("sa\n");
	}
}

void	sb(t_list **alst_b)
{
	if (*alst_b && (*alst_b)->next)
	{
		swap(alst_b);
		ft_printf("sb\n");
	}
}

void	ss(t_list **alst_a, t_list **alst_b)
{
	if (*alst_a && (*alst_a)->next && *alst_b && (*alst_b)->next)
	{
		swap(alst_a);
		swap(alst_b);
		ft_printf("ss\n");
	}
}
