/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:59:38 by pledieu           #+#    #+#             */
/*   Updated: 2024/12/19 12:49:50 by pledieu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	small_sort(t_stack **stack)
{
	int	highest;

	if (is_sorted(*stack))
		return ;
	highest = highest_index(*stack);
	if ((*stack)->index == highest)
		ra(stack);
	else if ((*stack)->next->index == highest)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

void	push_all_save_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = get_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

int	get_lowest_index(t_stack *stack)
{
	int	lowest;

	if (!stack)
		return (0);
	lowest = stack->index;
	while (stack)
	{
		if (stack->index < lowest)
			lowest = stack->index;
		stack = stack->next;
	}
	return (lowest);
}

void	sort_four_five(t_stack **a, t_stack **b)
{
	assign_indices(*a);
	assign_position(a);
	push_two_min_to_b(a, b);
	small_sort(a);
	if ((*b) && (*b)->next && (*b)->index > (*b)->next->index)
		sb(b);
	pa(a, b);
	pa(a, b);
}
