/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:59:38 by pledieu           #+#    #+#             */
/*   Updated: 2024/12/17 15:00:00 by pledieu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
        if ((*a)->index <= 2)
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
