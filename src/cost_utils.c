/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:00:23 by pledieu           #+#    #+#             */
/*   Updated: 2024/12/18 10:48:08 by pledieu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	get_target_position(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	assign_position(a);
	assign_position(b);
	tmp = *b;
	while (tmp)
	{
		tmp->target_pos = find_target_position(a, tmp->index);
		tmp = tmp->next;
	}
}

void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	size_a = get_stack_size(*stack_a);
	size_b = get_stack_size(*stack_b);
	tmp_b = *stack_b;
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}
