/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:40:22 by rmorel            #+#    #+#             */
/*   Updated: 2022/03/01 14:27:40 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverse_rotate(t_list **alst)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *alst;
	if (!tmp || !tmp->next)
		return ;
	while ((*alst)->next->next)
		*alst = (*alst)->next;
	tmp2 = (*alst)->next;
	(*alst)->next->next = tmp;
	(*alst)->next = NULL;
	*alst = tmp2;
}

void	rra(t_list **alst_a)
{
	reverse_rotate(alst_a);
	ft_printf("rra\n");
}	

void	rrb(t_list **alst_b)
{
	reverse_rotate(alst_b);
	ft_printf("rrb\n");
}

void	rrr(t_list **alst_a, t_list **alst_b)
{
	reverse_rotate(alst_a);
	reverse_rotate(alst_b);
	ft_printf("rrr\n");
}	

void	reverse_rotate_both(t_list **alst_a, t_list **alst_b)
{
	reverse_rotate(alst_a);
	reverse_rotate(alst_b);
}
