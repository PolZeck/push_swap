/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:00:56 by pledieu           #+#    #+#             */
/*   Updated: 2024/12/17 15:01:00 by pledieu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void shift_stack(t_stack **a)
{
    int lowest_pos;
    int size;

    size = get_stack_size(*a);
    lowest_pos = get_lowest_index_position(a);
    if (lowest_pos > size / 2)
        while (lowest_pos++ < size)
            rra(a);
    else
        while (lowest_pos--)
            ra(a);
}

void sort(t_stack **a, t_stack **b)
{
    if (is_sorted(*a))
        return;
    push_all_save_three(a, b);
    tiny_sort(a);
    while (*b)
    {
        get_target_position(a, b);
        get_cost(a, b);
        do_cheapest_move(a, b);
    }
    shift_stack(a);
}
