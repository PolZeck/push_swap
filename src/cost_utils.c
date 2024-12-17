/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:00:23 by pledieu           #+#    #+#             */
/*   Updated: 2024/12/17 15:43:29 by pledieu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void get_target_position(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	get_position(a);
	get_position(b);
	tmp = *b;
	while (tmp)
	{
		tmp->target_pos = find_target_position(a, tmp->index);
		tmp = tmp->next;
	}
}

void get_cost(t_stack **a, t_stack **b)
{
	t_stack *tmp_b;
	int size_a;
	int size_b;

	tmp_b = *b;
	size_a = get_stack_size(*a);
	size_b = get_stack_size(*b);
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
