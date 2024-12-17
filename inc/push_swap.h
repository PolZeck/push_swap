/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:34:43 by pledieu           #+#    #+#             */
/*   Updated: 2024/12/17 15:54:40 by pledieu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
    int value;              // Valeur de l'élément
    int index;              // Index (pour le tri par ordre croissant)
    int pos;                // Position actuelle dans la pile
    int target_pos;         // Position cible dans l'autre pile
    int cost_a;             // Coût pour déplacer dans A
    int cost_b;             // Coût pour déplacer dans B
    struct s_stack *next;   // Pointeur vers le prochain élément
} t_stack;


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
int is_sorted(t_stack *stack);


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

// Fonctions principales
void    sort(t_stack **a, t_stack **b);
void    tiny_sort(t_stack **a);
void    push_all_save_three(t_stack **a, t_stack **b);
void    shift_stack(t_stack **a);

// Assignation et coûts
void    assign_indices(t_stack *stack);
void    get_target_position(t_stack **a, t_stack **b);
void    get_cost(t_stack **a, t_stack **b);
void    do_cheapest_move(t_stack **a, t_stack **b);

// Fonctions utilitaires pour les positions
void    get_position(t_stack **stack);
int     get_lowest_index_position(t_stack **stack);
int     find_target_position(t_stack **a, int index_b);
void move_elements_combined(t_stack **a, t_stack **b, int cost_a, int cost_b);
void move_elements_single(t_stack **a, t_stack **b, int cost_a, int cost_b);
void push_all_save_three(t_stack **a, t_stack **b);



// Gestion de la stack
int     get_stack_size(t_stack *stack);
t_stack *new_node(int value);
void    free_stack(t_stack **stack);
void    push(t_stack **stack, int value);
t_stack	*get_stack_bottom(t_stack *stack);
t_stack	*get_stack_before_bottom(t_stack *stack);

#endif