/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:59:38 by pledieu           #+#    #+#             */
/*   Updated: 2024/12/18 06:46:43 by pledieu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void tiny_sort(t_stack **a)
{
    int highest;

    if (get_stack_size(*a) == 2) // Gérer 2 éléments
    {
        if ((*a)->index > (*a)->next->index)
            sa(a);
        return;
    }

    highest = (*a)->index;
    if ((*a)->next->index > highest)
        highest = (*a)->next->index;
    if ((*a)->next->next->index > highest)
        highest = (*a)->next->next->index;

    if ((*a)->index == highest)
        ra(a);
    else if ((*a)->next->index == highest)
        rra(a);

    if ((*a)->index > (*a)->next->index)
        sa(a);
}



void push_all_save_three(t_stack **a, t_stack **b)
{
    int size = get_stack_size(*a);
    int pushed = 0;
    int i = 0;

    while (size > 3 && i < size)
    {
        if ((*a)->index == get_lowest_index(*a)) // Trouve le plus petit élément

        {
            pb(a, b);
            pushed++;
        }
        else
            ra(a);
        i++;
    }
    while (get_stack_size(*a) > 3)
        pb(a, b);
}

int get_lowest_index(t_stack *stack)
{
    int lowest = stack->index;

    while (stack)
    {
        if (stack->index < lowest)
            lowest = stack->index;
        stack = stack->next;
    }
    return lowest;
}
void sort_four_five(t_stack **a, t_stack **b)
{
    assign_indices(*a);
    get_position(a);

    push_two_min_to_b(a, b); // Pousse les deux plus petits éléments dans stack_b
    tiny_sort(a); // Trie les 3 éléments restants dans stack_a

    // Vérifie l'ordre de stack_b avant de les ramener
    if ((*b) && (*b)->next && (*b)->index > (*b)->next->index)
        sb(b);

    pa(a, b); // Ramène le plus petit élément
    pa(a, b); // Ramène le deuxième plus petit élément
}




void push_two_min_to_b(t_stack **a, t_stack **b)
{
    int min_index;

    for (int i = 0; i < 2; i++) // Répéter pour les deux plus petits éléments
    {
        assign_indices(*a); // Recalcule les indices après chaque push
        get_position(a); // Met à jour les positions

        min_index = get_lowest_index(*a); // Trouve l'index du plus petit élément

        while ((*a)->index != min_index) // Ramène le plus petit en haut
        {
            if ((*a)->pos <= get_stack_size(*a) / 2)
                ra(a);
            else
                rra(a);
            get_position(a); // Mise à jour après chaque mouvement
        }
        pb(a, b); // Push vers stack_b
    }
}






