/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:25:40 by mechane           #+#    #+#             */
/*   Updated: 2023/01/26 18:50:00 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "../gnl/get_next_line.h"

typedef struct t_stackNode {
	int					data;
	struct t_stackNode	*next;
}	t_stackNode;

typedef t_stackNode*	t_stack;

char			**get_args(int ac, char **av);
int				check_args(char **av, int *p);
int				check_double(char **av);
int				ft_abort_stack(t_stack *a, t_stack *b);
int				ft_abort(void);
void			free_stack(t_stack *a);
void			sa(t_stack *a);
void			sb(t_stack *b);
void			ss(t_stack *a, t_stack *b);
int				pa(t_stack *a, t_stack *b);
int				pb(t_stack *a, t_stack *b);
void			ra(t_stack *a);
void			rb(t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			rra(t_stack *a);
void			rrb(t_stack *b);
void			rrr(t_stack *a, t_stack *b);
t_stackNode		*ft_prv_last(t_stack *myt_stack);
t_stackNode		*ft_last(t_stack *myt_stack);
t_stack			*push(int value, t_stack *head);
long			pop(t_stack *head);
int				len_stack(t_stack a);
int				ft_atoi(const char *str);
int				check_is_sorted(t_stack a);
char			*ft_strjoin_c(const char *s1, const char *s2);
char			*ft_strdup_c(const char *source);
char			**get_args(int ac, char **av);
char			**ft_split_c(const char *str, char c);
size_t			ft_strlen_c(const char *s);
int				ft_strncmp_c(const char *s11, const char *s22, size_t n);
char			*ft_substr_c(char const *s, unsigned int start, size_t len);
#endif