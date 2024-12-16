/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:34:22 by pledieu           #+#    #+#             */
/*   Updated: 2024/12/16 15:16:28 by pledieu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	has_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*runner;

	current = stack;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->value == runner->value)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
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
