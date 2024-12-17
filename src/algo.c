/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:44:06 by pledieu           #+#    #+#             */
/*   Updated: 2024/12/17 09:44:00 by pledieu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Tri une pile de 3 éléments
void tiny_sort(t_stack **a)
{
    int highest;

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
        if ((*a)->index <= 2) // On déplace les plus petits indices dans B
        {
            pb(a, b);
            pushed++;
        }
        else
            ra(a); // On fait tourner la pile pour accéder aux bons éléments
        i++;
    }

    // Si nécessaire, on ajuste pour s'assurer qu'il ne reste que 3 éléments
    while (get_stack_size(*a) > 3)
        pb(a, b);
}


void get_position(t_stack **stack)
{
    t_stack *tmp;
    int pos = 0;

    tmp = *stack;
    while (tmp)
    {
        tmp->pos = pos++;
        tmp = tmp->next;
    }
}

int find_target_position(t_stack **a, int index_b)
{
    t_stack *tmp = *a;
    int target_index = INT_MAX;
    int target_pos = 0;

    while (tmp)
    {
        if (tmp->index > index_b && tmp->index < target_index)
        {
            target_index = tmp->index;
            target_pos = tmp->pos;
        }
        tmp = tmp->next;
    }
    return (target_index == INT_MAX) ? get_lowest_index_position(a) : target_pos;
}

void get_target_position(t_stack **a, t_stack **b)
{
    t_stack *tmp = *b;

    get_position(a);
    get_position(b);
    while (tmp)
    {
        tmp->target_pos = find_target_position(a, tmp->index);
        tmp = tmp->next;
    }
}

void get_cost(t_stack **a, t_stack **b)
{
    t_stack *tmp_b = *b;
    int size_a = get_stack_size(*a);
    int size_b = get_stack_size(*b);

    while (tmp_b)
    {
        tmp_b->cost_b = tmp_b->pos;
        tmp_b->cost_a = tmp_b->target_pos;
        if (tmp_b->pos > size_b / 2)
            tmp_b->cost_b = tmp_b->pos - size_b;
        if (tmp_b->target_pos > size_a / 2)
            tmp_b->cost_a = tmp_b->target_pos - size_a;
        tmp_b = tmp_b->next;
    }
}
void do_cheapest_move(t_stack **a, t_stack **b)
{
    t_stack *tmp = *b;
    int cheapest = INT_MAX;
    int cost_a = 0, cost_b = 0;

    while (tmp)
    {
        int total_cost = abs(tmp->cost_a) + abs(tmp->cost_b);
        if (total_cost < cheapest)
        {
            cheapest = total_cost;
            cost_a = tmp->cost_a;
            cost_b = tmp->cost_b;
        }
        tmp = tmp->next;
    }
    move_elements(a, b, cost_a, cost_b);
}
void shift_stack(t_stack **a)
{
    int lowest_pos = get_lowest_index_position(a);
    int size = get_stack_size(*a);

    if (lowest_pos > size / 2)
        while (lowest_pos++ < size)
            rra(a);
    else
        while (lowest_pos--)
            ra(a);
}
void sort(t_stack **a, t_stack **b)
{
    if (is_sorted(*a)) // Si la pile est déjà triée
        return;

    push_all_save_three(a, b); // Réduit A à 3 éléments
    tiny_sort(a);              // Trie les 3 éléments restants

    while (*b) // Déplace les éléments de B vers A
    {
        get_target_position(a, b);
        get_cost(a, b);
        do_cheapest_move(a, b);
    }
    shift_stack(a); // Réaligne A pour mettre le plus petit élément en haut
}


// Déplace les éléments en fonction des coûts calculés
void move_elements(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
    while (cost_a > 0 && cost_b > 0)
    {
        rr(a, b);
        cost_a--;
        cost_b--;
    }
    while (cost_a < 0 && cost_b < 0)
    {
        rrr(a, b);
        cost_a++;
        cost_b++;
    }
    while (cost_a > 0)
    {
        ra(a);
        cost_a--;
    }
    while (cost_a < 0)
    {
        rra(a);
        cost_a++;
    }
    while (cost_b > 0)
    {
        rb(b);
        cost_b--;
    }
    while (cost_b < 0)
    {
        rrb(b);
        cost_b++;
    }
    pa(a, b);
}
