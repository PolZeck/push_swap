/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:34:10 by pledieu           #+#    #+#             */
/*   Updated: 2024/12/16 14:07:43 by pledieu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* ********** SWAP ********** */
// Échange les deux premiers éléments d'une pile.
static void swap(t_stack **stack)
{
    if (!stack || !(*stack) || !(*stack)->next)
        return;
    int temp = (*stack)->value;
    (*stack)->value = (*stack)->next->value;
    (*stack)->next->value = temp;
}

void sa(t_stack **stack_a)
{
    swap(stack_a);
	write(1, "sa\n", 3);
}

void sb(t_stack **stack_b)
{
    swap(stack_b);
	write(1, "sb\n", 3);
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
    swap(stack_a);
    swap(stack_b);
	write(1, "ss\n", 3);
}

