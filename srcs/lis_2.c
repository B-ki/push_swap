/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:59:12 by rmorel            #+#    #+#             */
/*   Updated: 2022/02/23 14:35:07 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	best_index_lis(t_list **alst)
{
	int		i;
	int		j;
	int		max;
	t_list	*tmp;
	t_list	*copy;

	i = 0;
	j = 0;
	max = max_copy(*alst);
	copy = copy_list(alst);
	tmp = copy;
	while (i < ft_lstsize(*alst))
	{
		if (max_copy(copy) > max)
		{
			max = max_copy(copy);
			j = i;
		}
		i++;
		rotate(&copy);
	}
	ft_lstclear(&tmp);
	return (convert_position(alst, j));
}

int	max_copy(t_list *lst)
{
	t_lis	*lis;
	int		max;

	lis = lis_launch(lst);
	max = lis->max_length;
	free(lis);
	return (max);
}

void	rotate_for_lis(t_list **alst_a, int j)
{
	int		i;

	i = 0;
	if (j < 0)
	{
		while (i >= j)
		{
			rra(alst_a);
			i--;
		}
	}
	else
	{
		while (i <= j)
		{
			ra(alst_a);
			i++;
		}
	}
	return ;
}

void	final_lis(t_lis *lis, t_list **alst, int *array)
{
	int	i;
	int	j;

	i = lis->max_length - 1;
	j = lis->best_end;
	lis->final_lis = malloc(sizeof(int) * lis->max_length);
	if (!lis->final_lis)
		return ;
	while (i >= 0)
	{
		lis->final_lis[i] = array[j];
		belong_in_lis(alst, j);
		j = lis->prev[j];
		i--;
	}
}

void	belong_in_lis(t_list **alst, int j)
{
	t_list	*tmp;
	int		i;

	tmp = *alst;
	i = 0;
	while ((*alst)->next && i < j)
	{
		*alst = (*alst)->next;
		i++;
	}
	(*alst)->in_lis = 1;
	*alst = tmp;
}		
