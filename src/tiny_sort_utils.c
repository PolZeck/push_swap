/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:23:59 by pledieu           #+#    #+#             */
/*   Updated: 2024/12/18 11:00:54 by pledieu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	highest_index(t_stack *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

void	push_two_min_to_b(t_stack **a, t_stack **b)
{
	int	min_index;
	int	i;

	i = 0;
	while (i < 2)
	{
		assign_indices(*a);
		assign_position(a);
		min_index = get_lowest_index(*a);
		while ((*a) && (*a)->index != min_index)
		{
			if ((*a)->pos <= get_stack_size(*a) / 2)
				ra(a);
			else
				rra(a);
			assign_position(a);
		}
		pb(a, b);
		i++;
	}
}

int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
