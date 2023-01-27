/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 12:14:03 by mechane           #+#    #+#             */
/*   Updated: 2023/01/26 18:45:22 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "./gnl/get_next_line.h"

typedef struct t_stackNode {
	int					data;
	struct t_stackNode	*next;
}	t_stackNode;

typedef t_stackNode*	t_stack;

typedef struct t_vars {
	int	min;
	int	len;
}	t_vars;

t_stackNode		*ft_prv_last(t_stack *myt_stack);
t_stackNode		*ft_last(t_stack *myt_stack);
t_stack			*push(int value, t_stack *head);
long			pop(t_stack *head);
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
int				ft_atoi(const char *str);
int				check_args(char **av, int *i);
int				check_double(char **av);
void			ft_putstr_fd(char *s, int fd);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strdup(const char *source);
char			**get_args(int ac, char **av);
char			**ft_split(const char *str, char c);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s11, const char *s22, size_t n);
int				ft_abort(void);
int				check_if_sorted(char **args);
int				*sortarray(int *a, int len);
int				*tronsfer_array(char **array, int argc);
int				*array_to_chuncks(int *arr, int *len, int *min);
void			small_number(t_stack *a, t_stack *b, int len);
int				min_number(t_stack a, int *position, int *len);
void			push_min_number(t_stack *a, t_stack *b, int lens);
void			push_swap_three(t_stack *a);
void			go_push(t_stack *a, t_stack *b, int *arr, t_vars var);
int				find_max(t_stack a, int *index, int min);
int				position(t_stack a, int number, int *index);
int				len_stack(t_stack a);
void			free_stack(t_stack *a);
int				find_bf_max(t_stack a, int *index, int max, int min);
void			small_number(t_stack *a, t_stack *b, int len);
int				calcul_numinstr(t_stack *a, int index1, int index2);
void			push_one_a_to_b(t_stack *a, int index, int number);
void			push_one_b_to_a(t_stack *a, t_stack *b, int index, int number);
int				calcul_best(t_stack *a, int index1, int index2);
#endif