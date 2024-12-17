/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:00:08 by pledieu           #+#    #+#             */
/*   Updated: 2024/12/17 15:00:15 by pledieu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
    t_stack *tmp;
    int target_index;
    int target_pos;

    tmp = *a;
    target_index = INT_MAX;
    target_pos = 0;
    while (tmp)
    {
        if (tmp->index > index_b && tmp->index < target_index)
        {
            target_index = tmp->index;
            target_pos = tmp->pos;
        }
        tmp = tmp->next;
    }
    if (target_index == INT_MAX)
        return (get_lowest_index_position(a));
    return (target_pos);
}
