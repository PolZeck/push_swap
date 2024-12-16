/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:34:43 by pledieu           #+#    #+#             */
/*   Updated: 2024/12/16 15:18:49 by pledieu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

// Main functions
t_stack	*parse_input(int argc, char **argv);
void	free_stack(t_stack **stack);

// Operations
void	sa(t_stack **stack);
void	pb(t_stack **stack_a, t_stack **stack_b);
// Ajoute les autres opérations ici...

// Utils
void	ft_putstr_fd(char *str, int fd);
int		ft_isdigit(int c);
int		ft_atoi_safe(const char *str, int *result);
void	push(t_stack **stack, int value);

/* SWAP */
void	push_s(t_stack **src, t_stack **dest);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

/* PUSH */
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

/* ROTATE */
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

/* REVERSE ROTATE */
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

#endif
