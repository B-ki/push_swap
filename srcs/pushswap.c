/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:46:32 by rmorel            #+#    #+#             */
/*   Updated: 2022/03/01 14:26:59 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	error(void)
{
	write (2, "Error\n", 6);
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;
	t_lis	*lis;

	lst_a = NULL;
	lst_b = NULL;
	if (check_args(ac, av) == 0)
		return (error());
	else if (check_args(ac, av) == -1)
		return (0);
	else
		lst_a = create_list(ac, av);
	if (ac <= 6)
		sort_few(&lst_a, &lst_b);
	else
	{
		lis = lis_launch(lst_a);
		push_all_lis_b(&lst_a, &lst_b, lis, ac);
		free_lis(lis);
		push_all_b_to_a(&lst_a, &lst_b);
	}
	ft_lstclear(&lst_a);
	ft_lstclear(&lst_b);
	return (0);
}

void	print_list(t_list *lst, char *str)
{
	ft_putstr_fd(str, 1);
	if (!lst)
	{
		write (1, " \n", 2);
		return ;
	}
	while (lst->next)
	{
		ft_putnbr_fd(lst->n, 1);
		write (1, " ", 1);
		lst = lst->next;
	}
	ft_putnbr_fd(lst->n, 1);
	write (1, "\n", 1);
}

void	print_list_info(t_list *lst)
{
	if (!lst)
	{
		write (1, " \n", 2);
		return ;
	}
	while (lst->next)
	{
		ft_putnbr_fd(lst->in_lis, 1);
		write (1, " ", 1);
		lst = lst->next;
	}
	ft_putnbr_fd(lst->in_lis, 1);
	write (1, "\n", 1);
}

void	print_lis(t_lis *lis)
{
	int	i;

	i = 0;
	write (1, "lis : ", 6);
	while (i < lis->max_length)
	{
		ft_putnbr_fd(lis->final_lis[i], 1);
		write (1, " ", 1);
		i++;
	}
	write (1, "\n", 1);
	return ;
}	
