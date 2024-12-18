/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:37:31 by pledieu           #+#    #+#             */
/*   Updated: 2024/12/18 10:54:13 by pledieu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi_safe(const char *str, int *result)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		res = res * 10 + (*str++ - '0');
		if ((sign == 1 && res > INT_MAX) || ((sign == -1) && (-res < INT_MIN)))
			return (0);
	}
	*result = (int)(res * sign);
	return (1);
}

int	has_duplicates(t_stack *stack)
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

int	is_number(char *str)
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
