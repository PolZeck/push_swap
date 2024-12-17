/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:10:19 by pledieu           #+#    #+#             */
/*   Updated: 2024/12/17 14:50:28 by pledieu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>


int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    if (argc < 2)
        return (0);

    stack_a = parse_input(argc, argv);
    if (!stack_a)
    {
        ft_putstr_fd("Error\n", 2);
        return (1);
    }

    assign_indices(stack_a); // Attribue des indices
    sort(&stack_a, &stack_b);

    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}

