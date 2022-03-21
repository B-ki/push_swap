/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:49:00 by rmorel            #+#    #+#             */
/*   Updated: 2022/03/01 14:32:40 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*create_list(int ac, char **av)
{
	t_list	*lst;
	t_list	*tmp;

	lst = NULL;
	while (ac > 1)
	{
		tmp = ft_lstnew(ft_atoi(av[ac - 1]));
		if (tmp)
			ft_lstadd_front(&lst, tmp);
		ac--;
	}
	return (lst);
}

t_list	*create_list_str(char **str)
{
	int		i;
	t_list	*lst;
	t_list	*tmp;

	i = 0;
	lst = NULL;
	while (str[i])
	{
		tmp = ft_lstnew(ft_atoi(str[i]));
		if (tmp)
			ft_lstadd_back(&lst, tmp);
		i++;
	}
	return (lst);
}

t_list	*copy_list(t_list **alst)
{
	t_list	*lst;
	t_list	*tmp;
	t_list	*tmp_alst;

	lst = NULL;
	tmp_alst = *alst;
	while (tmp_alst->next)
	{
		tmp = ft_lstnew(tmp_alst->n);
		if (tmp)
			ft_lstadd_back(&lst, tmp);
		tmp_alst = tmp_alst->next;
	}
	tmp = ft_lstnew(tmp_alst->n);
	if (tmp)
		ft_lstadd_back(&lst, tmp);
	return (lst);
}

int	end_checker(t_list **alst_a, t_list *lst_b)
{
	if (check_if_sorted(alst_a) && !lst_b)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	return (0);
}
