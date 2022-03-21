/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:33:51 by rmorel            #+#    #+#             */
/*   Updated: 2022/03/01 14:32:40 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include "libft.h"

/* check_args.c */
int				check_str_is_int(char *str);
int				check_multiple_args(int ac, char **av);
int				check_no_double(int ac, char **av);
int				check_args(int ac, char **av);
int				error(void);

/* gnl.c */
char			*get_next_line(int fd);
char			*gnl_substr(char *str, unsigned int start, size_t len);
char			*gnl_strchr(char *str);
char			*ft_join(char *buff, char *prev);
char			*ft_newline(char **prev);

/* list.c */
t_list			*create_list(int ac, char **av);
t_list			*create_list_str(char **str);
t_list			*copy_list(t_list **alst);
int				end_checker(t_list **alst_a, t_list *lst_b);

/* main_checker */
void			print_list(t_list *lst, char *str);
int				do_op(char *str, t_list **alst_a, t_list **alst_b);
int				check_if_sorted(t_list **alst);
int				error(void);

/* operations.c */
void			swap(t_list **alst);
void			sa(t_list **alst_a);
void			sb(t_list **alst_b);
void			ss(t_list **alst_a, t_list **alst_b);
unsigned int	strlen_gnl(char *str);

/* push_list.c */
void			push(t_list **alst_a, t_list **alst_b);
void			pa(t_list **alst_a, t_list **alst_b);
void			pb(t_list **alst_a, t_list **alst_b);

/* reverse_rotations.c */
void			reverse_rotate(t_list **alst);
void			rra(t_list **alst_a);
void			rrb(t_list **alst_b);
void			rrr(t_list **alst_a, t_list **alst_b);
void			reverse_rotate_both(t_list **alst_a, t_list **alst_b);

/* rotations.c */
void			rotate(t_list **alst);
void			ra(t_list **alst_a);
void			rb(t_list **alst_b);
void			rr(t_list **alst_a, t_list **alst_b);
void			rotate_both(t_list **alst_a, t_list **alst_b);

#endif
