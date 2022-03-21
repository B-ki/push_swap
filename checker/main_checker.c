/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:32:39 by rmorel            #+#    #+#             */
/*   Updated: 2022/03/01 14:29:57 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;
	char	*str;
	int		ret;

	lst_a = NULL;
	lst_b = NULL;
	if (check_args(ac, av) == 0)
		return (error());
	else if (check_args(ac, av) == -1)
		return (0);
	lst_a = create_list(ac, av);
	str = get_next_line(0);
	ret = 0;
	while (str)
	{
		ret = do_op(str, &lst_a, &lst_b);
		if (ret == 0)
			return (0);
		free(str);
		str = get_next_line(0);
	}
	return (end_checker(&lst_a, lst_b));
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

int	do_op(char *str, t_list **alst_a, t_list **alst_b)
{
	if (!ft_strncmp(str, "ra\n", 3))
		rotate(alst_a);
	else if (!ft_strncmp(str, "rra\n", 4))
		reverse_rotate(alst_a);
	else if (!ft_strncmp(str, "rb\n", 3))
		rotate(alst_b);
	else if (!ft_strncmp(str, "rrb\n", 4))
		reverse_rotate(alst_b);
	else if (!ft_strncmp(str, "rr\n", 3))
		rotate_both(alst_a, alst_b);
	else if (!ft_strncmp(str, "rrr\n", 4))
		reverse_rotate_both(alst_a, alst_b);
	else if (!ft_strncmp(str, "pa\n", 3))
		push(alst_a, alst_b);
	else if (!ft_strncmp(str, "pb\n", 3))
		push(alst_b, alst_a);
	else if (!ft_strncmp(str, "sa\n", 3))
		swap(alst_a);
	else if (!ft_strncmp(str, "sb\n", 3))
		swap(alst_b);
	else
		return (error());
	return (1);
}

int	check_if_sorted(t_list **alst)
{
	int		check;
	t_list	*tmp;

	tmp = *alst;
	check = tmp->n;
	tmp = tmp->next;
	if (!tmp)
		return (1);
	if (tmp->n < check)
		return (0);
	while (tmp->next)
	{
		if (tmp->n < check)
			return (0);
		check = tmp->n;
		tmp = tmp->next;
	}
	if (tmp->n < check)
		return (0);
	return (1);
}

int	error(void)
{
	write (2, "Error\n", 6);
	return (0);
}
