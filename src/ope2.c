/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:12:09 by pledieu           #+#    #+#             */
/*   Updated: 2024/12/16 14:16:46 by pledieu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
/* ********** PUSH ********** */
// Prend le premier élément de src et le place sur dest.
void push_s(t_stack **src, t_stack **dest)
{
    t_stack *temp;

    if (!src || !(*src))
        return;
    temp = *src;
    *src = (*src)->next;
    temp->next = *dest;
    *dest = temp;
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
    push_s(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
    push_s(stack_a, stack_b);
	write(1, "pb\n", 3);
}

