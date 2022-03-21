/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:05:03 by rmorel            #+#    #+#             */
/*   Updated: 2022/02/09 12:43:59 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_add_tlist_back(t_list **start, int n)
{
	t_list	*new;

	new = ft_lstnew(n);
	if (!new)
		return (0);
	ft_lstadd_back(start, new);
	return (1);
}

t_list	*ft_lstmap(t_list *lst, int (*f)(int n))
{
	t_list	*start;

	if (!lst)
		return (NULL);
	start = NULL;
	while (lst)
	{
		if (!(ft_add_tlist_back(&start, (*f)(lst->n))))
		{
			ft_lstclear(&start);
			return (NULL);
		}
		lst = lst->next;
	}
	return (start);
}
