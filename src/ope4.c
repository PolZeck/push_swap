/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:48:25 by pledieu           #+#    #+#             */
/*   Updated: 2024/12/16 13:48:40 by pledieu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* ********** REVERSE ROTATE ********** */
// Fait tourner tous les éléments d'une pile vers le bas.
void reverse_rotate(t_stack **stack)
{
    t_stack *last;
    t_stack *second_last;

    if (!stack || !(*stack) || !(*stack)->next)
        return;
    second_last = *stack;
    while (second_last->next->next)
        second_last = second_last->next;
    last = second_last->next;
    second_last->next = NULL;
    last->next = *stack;
    *stack = last;
}

void rra(t_stack **stack_a)
{
    reverse_rotate(stack_a);
}

void rrb(t_stack **stack_b)
{
    reverse_rotate(stack_b);
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
}
