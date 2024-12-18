/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:34:43 by pledieu           #+#    #+#             */
/*   Updated: 2024/12/18 11:43:54 by pledieu          ###   ########lyon.fr   */
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
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}				t_stack;

/* 		PARSE_INPUT 			*/
t_stack	*parse_input(int argc, char **argv);
void	free_stack(t_stack **stack);

/* 		PARSE_INPUT_UTILS 		*/
int		ft_isdigit(int c);
int		ft_atoi_safe(const char *str, int *result);
int		has_duplicates(t_stack *stack);
int		is_number(char *str);

/* 		UTILS 					*/
int		is_sorted(t_stack *stack);
int		nb_abs(int nb);
void	ft_putstr_fd(char *str, int fd);
t_stack	*get_stack_bottom(t_stack *stack);
t_stack	*get_stack_before_bottom(t_stack *stack);

/* 		TINY_SORT 				*/
int		get_lowest_index(t_stack *stack);
void	tiny_sort(t_stack **a);
void	push_all_save_three(t_stack **a, t_stack **b);
void	sort_four_five(t_stack **a, t_stack **b);

/* 		TINY_SORT_UTILS 		*/
int		highest_index(t_stack *stack);
int		get_stack_size(t_stack *stack);
void	push_two_min_to_b(t_stack **a, t_stack **b);

/* 		STACK_UTILS 			*/
void	assign_indices(t_stack *stack);
void	free_stack(t_stack **stack);
int		get_lowest_index_position(t_stack **stack);
t_stack	*new_node(int value);

/* 		SWAP 					*/
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

/* 		PUSH 					*/
void	push_s(t_stack **src, t_stack **dest);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

/* 		ROTATE 					*/
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

/* 		REVERSE ROTATE 			*/
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/* 		FINAL_SORT 				*/
void	sort(t_stack **a, t_stack **b);
void	shift_stack(t_stack **a);

/* 		COST 					*/
void	get_target_position(t_stack **a, t_stack **b);
void	get_cost(t_stack **a, t_stack **b);

/* 		BEST_MOVE 				*/
void	best_move(t_stack **a, t_stack **b);

/* 		POSITION 				*/
int		find_target_position(t_stack **a, int index_b);
void	assign_position(t_stack **stack);

#endif