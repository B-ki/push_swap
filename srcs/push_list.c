/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:41:19 by rmorel            #+#    #+#             */
/*   Updated: 2022/02/17 15:02:28 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push(t_list **alst_a, t_list **alst_b)
{
	t_list	*tmp;

	tmp = (*alst_b)->next;
	(*alst_b)->next = *alst_a;
	*alst_a = *alst_b;
	*alst_b = tmp;
}

void	pa(t_list **alst_a, t_list **alst_b)
{
	push(alst_a, alst_b);
	ft_printf("pa\n");
}

void	pb(t_list **alst_a, t_list **alst_b)
{
	push(alst_b, alst_a);
	ft_printf("pb\n");
}
