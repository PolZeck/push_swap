/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:00:37 by pledieu           #+#    #+#             */
/*   Updated: 2024/12/18 10:53:06 by pledieu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	move_elements_single(t_stack **a, t_stack **b,
												int cost_a, int cost_b)
{
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

static void	move_elements_combined(t_stack **a, t_stack **b,
													int cost_a, int cost_b)
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
	move_elements_single(a, b, cost_a, cost_b);
}

void	best_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;
	int		total_cost;

	cost_a = 0;
	cost_b = 0;
	cheapest = INT_MAX;
	tmp = *stack_b;
	while (tmp)
	{
		total_cost = nb_abs(tmp->cost_a) + nb_abs(tmp->cost_b);
		if (total_cost < cheapest)
		{
			cheapest = total_cost;
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	move_elements_combined(stack_a, stack_b, cost_a, cost_b);
}
