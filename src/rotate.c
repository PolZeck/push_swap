/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:12:07 by pledieu           #+#    #+#             */
/*   Updated: 2024/12/16 14:48:18 by pledieu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
/* ********** ROTATE ********** */
// Fait tourner tous les éléments d'une pile vers le haut.
void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = temp;
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
