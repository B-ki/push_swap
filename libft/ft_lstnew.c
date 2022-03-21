/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:15:53 by rmorel            #+#    #+#             */
/*   Updated: 2022/02/07 10:29:56 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int n)
{
	t_list	*lstnew;

	lstnew = malloc(sizeof(*lstnew));
	if (lstnew)
	{
		lstnew->n = n;
		lstnew->next = NULL;
		lstnew->in_lis = 0;
		return (lstnew);
	}
	return (NULL);
}
