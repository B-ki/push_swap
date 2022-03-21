/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:59:12 by rmorel            #+#    #+#             */
/*   Updated: 2022/02/23 14:35:08 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	*array_from_list(t_list *lst)
{
	int	*array;
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(lst);
	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	while (i < size)
	{
		array[i] = lst->n;
		lst = lst->next;
		i++;
	}
	return (array);
}

int	*empty_array(t_list *lst)
{
	int	*array;
	int	n;
	int	i;

	i = 0;
	if (lst)
		n = ft_lstsize(lst);
	else
		return (NULL);
	array = malloc(sizeof(int) * n);
	if (array)
	{
		while (i < n)
		{
			array[i] = 0;
			i++;
		}
		return (array);
	}
	else
		return (NULL);
}

t_lis	*lis_launch(t_list *lst)
{
	int		*array;
	t_lis	*lis;

	array = array_from_list(lst);
	lis = initialize_lis(lst);
	if (!array || !lis->dp || !lis->prev)
		return (NULL);
	search_lis(lis, array);
	final_lis(lis, &lst, array);
	free(array);
	return (lis);
}

t_lis	*initialize_lis(t_list *lst)
{
	t_lis	*lis;

	lis = malloc(sizeof(*lis));
	if (!lis)
		return (NULL);
	lis->size = ft_lstsize(lst);
	lis->max_length = 1;
	lis->best_end = 0;
	lis->i = 1;
	lis->j = 0;
	lis->dp = empty_array(lst);
	lis->prev = empty_array(lst);
	lis->final_lis = NULL;
	if (lis->dp && lis->prev)
		return (lis);
	else
		return (NULL);
}

/* On défini la LIS : On cherche pour chaque intervalle [0;i] (1 à max) 
quelle est la LIS en parcourant de j = i - 1 à 0
On enregistre DP[i] = taille de LIS calculée à l'index i, et prev[i] = indice 
du précédent nombre dans la LIS */
/* lgth,LIS[j] + 1 > lgth,LIS[i]  (ie la LIS s'agrandit) 
	ET  array[j] < array[i] (avec j < i) */
void	search_lis(t_lis *lis, int *array)
{
	lis->dp[0] = 1;
	lis->prev[0] = -1;
	while (lis->i < lis->size)
	{
		lis->dp[lis->i] = 1;
		lis->prev[lis->i] = -1;
		while (lis->j >= 0)
		{
			if (lis->dp[lis->j] + 1 > lis->dp[lis->i]
				&& array[lis->j] <= array[lis->i])
			{
				lis->dp[lis->i] = lis->dp[lis->j] + 1;
				lis->prev[lis->i] = lis->j;
			}
			lis->j--;
		}
		if (lis->dp[lis->i] > lis->max_length)
		{
			lis->best_end = lis->i;
			lis->max_length = lis->dp[lis->i];
		}
		lis->i++;
		lis->j = lis->i - 1;
	}
	return ;
}
