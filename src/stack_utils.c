/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:33:46 by pledieu           #+#    #+#             */
/*   Updated: 2024/12/16 13:53:25 by pledieu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack *new_node(int value)
{
    t_stack *node = malloc(sizeof(t_stack));
    if (!node)
        return (NULL);
    node->value = value;
    node->next = NULL;
    return (node);
}

void push(t_stack **stack, int value)
{
    t_stack *node = new_node(value);
    if (!node)
        return;
    node->next = *stack;
    *stack = node;
}

void free_stack(t_stack **stack)
{
    t_stack *temp;

    while (*stack)
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}
