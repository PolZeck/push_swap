/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:34:22 by pledieu           #+#    #+#             */
/*   Updated: 2024/12/18 09:53:25 by pledieu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push(t_stack **stack, int value)
{
	t_stack	*node;

	node = new_node(value);
	if (!node)
		return ;
	node->next = *stack;
	*stack = node;
}

t_stack	*parse_input(int argc, char **argv)
{
	t_stack	*stack;
	int		value;
	int		i;

	stack = NULL;
	i = argc - 1;
	while (i >= 1)
	{
		if (!is_number(argv[i]) || !ft_atoi_safe(argv[i], &value))
		{
			free_stack(&stack);
			return (NULL);
		}
		push(&stack, value);
		i--;
	}
	if (has_duplicates(stack))
	{
		free_stack(&stack);
		return (NULL);
	}
	return (stack);
}
