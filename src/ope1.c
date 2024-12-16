/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:34:10 by pledieu           #+#    #+#             */
/*   Updated: 2024/12/16 13:49:21 by pledieu          ###   ########lyon.fr   */
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
}

void sb(t_stack **stack_b)
{
    swap(stack_b);
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
    swap(stack_a);
    swap(stack_b);
}

