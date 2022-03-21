/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:39:24 by rmorel            #+#    #+#             */
/*   Updated: 2022/02/17 15:00:27 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(t_list **alst)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *alst;
	tmp2 = (*alst)->next;
	while ((*alst)->next)
		*alst = (*alst)->next;
	(*alst)->next = tmp;
	tmp->next = NULL;
	*alst = tmp2;
}

void	ra(t_list **alst_a)
{
	rotate(alst_a);
	ft_printf("ra\n");
}	

void	rb(t_list **alst_b)
{
	rotate(alst_b);
	ft_printf("rb\n");
}

void	rr(t_list **alst_a, t_list **alst_b)
{
	rotate(alst_a);
	rotate(alst_b);
	ft_printf("rr\n");
}
