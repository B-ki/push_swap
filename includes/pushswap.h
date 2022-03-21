/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:49:45 by rmorel            #+#    #+#             */
/*   Updated: 2022/03/01 14:30:20 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include "libft.h"

typedef struct s_lis
{
	int	size;
	int	max_length;
	int	best_end;
	int	i;
	int	j;
	int	*dp;
	int	*prev;
	int	*final_lis;
}	t_lis;

typedef struct s_cost
{
	int	a_cost;
	int	b_cost;
	int	t_cost;
}	t_cost;

/* check_param.c */
int		check_str_is_int(char *str);
int		check_multiple_args(int ac, char **av);
int		check_no_double(int ac, char **av);
int		check_args(int ac, char **av);

/* find_best_move */
int		int_after_in_lst(t_list **alst, int n);
int		position_in_list(t_list **alst, int n, int int_a, int i);
int		convert_position(t_list **alst, int n);
t_cost	*cost_all_b_to_a(t_list **alst, t_list **alst_b);
int		index_min_cost(t_cost *cost, t_list *lst_b);

/* lis.c */
int		*array_from_list(t_list *lst);
int		*empty_array(t_list *lst);
t_lis	*lis_launch(t_list *lst);
t_lis	*initialize_lis(t_list *lst);
void	search_lis(t_lis *lis, int *array);

/* lis_2.c */
int		best_index_lis(t_list **alst);
int		max_copy(t_list *lst);
void	rotate_for_lis(t_list **alst_a, int j);
void	final_lis(t_lis *lis, t_list **alst, int *array);
void	belong_in_lis(t_list **alst, int j);

/* list.c */
t_list	*create_list(int ac, char **av);
t_list	*create_list_str(char **str);
t_list	*copy_list(t_list **alst);
void	free_lis(t_lis *lis);

/* median.c */
int		median(t_list **alst, int median);
int		int_after_not_in_lis(t_list **alst, int n);
int		min_list_not_in_lis(t_list **alst);

/* operations.c */
void	swap(t_list **alst);
void	sa(t_list **alst_a);
void	sb(t_list **alst_b);
void	ss(t_list **alst_a, t_list **alst_b);

/* pushswap.c */
void	print_list(t_list *lst, char *str);
void	print_list_info(t_list *lst);
void	print_lis(t_lis *lis);
int		error(void);

/* push_b_to_a.c */
void	push_all_b_to_a(t_list **alst_a, t_list **alst_b);
void	push_b_to_a(t_list **alst_a, t_list **alst_b);
void	negative_case(t_list **alst_a, t_list **alst_b, t_cost *cost, int i);
void	positive_case(t_list **alst_a, t_list **alst_b, t_cost *cost, int i);
void	both_pos(t_list **alst_a, t_list **alst_b, t_cost *cost, int i);

/* push_b_to_a_2.c */
void	both_neg(t_list **alst_a, t_list **alst_b, t_cost *cost, int i);
void	null_case(t_list **alst_a, t_list **alst_b, t_cost *cost, int i);
void	a_null(t_list **alst_a, t_list **alst_b, t_cost *cost, int i);
void	b_null(t_list **alst_a, t_list **alst_b, t_cost *cost, int i);
void	sort_a(t_list **alst_a);

/* push_list.c */
void	push(t_list **alst_a, t_list **alst_b);
void	pa(t_list **alst_a, t_list **alst_b);
void	pb(t_list **alst_a, t_list **alst_b);

/* reverse_rotations.c */
void	reverse_rotate(t_list **alst);
void	rra(t_list **alst_a);
void	rrb(t_list **alst_b);
void	rrr(t_list **alst_a, t_list **alst_b);

/* rotations.c */
void	rotate(t_list **alst);
void	ra(t_list **alst_a);
void	rb(t_list **alst_b);
void	rr(t_list **alst_a, t_list **alst_b);

/*short_sorting.c */
void	sort_few(t_list **alst_a, t_list **alst_b);
void	sort_3(t_list **alst_a);
void	sort_5(t_list **alst_a, t_list **alst_b);
int		int_index(t_list **alst, int i);
int		get_index(t_list **alst, int n);

/* sort_lis.c */
void	push_one_lis_b(t_list **alst_a, t_list **alst_b, int lis_length,
			int ac);
void	push_all_lis_b(t_list **alst_a, t_list **alst_b, t_lis *lis, int ac);
int		min_cost_lis_to_top(t_list **alst);

/* utils.c */
int		abs(int i);
int		max_list(t_list **alst);
int		min_list(t_list **alst);
int		min(int a, int b);
int		max(int a, int b);

/* utils_cost.c */
int		cost_to_top(t_list **alst, int n);
int		belong_to_lis(int n, t_lis *lis);
int		min_cost_lis_to_top_med(t_list **alst, int median);
void	print_cost(t_cost *cost, t_list **alst_b);
int		check_if_sorted(t_list **alst);

#endif
