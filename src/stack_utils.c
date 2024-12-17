/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:33:46 by pledieu           #+#    #+#             */
/*   Updated: 2024/12/17 08:56:59 by pledieu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	push(t_stack **stack, int value)
{
	t_stack	*node;

	node = new_node(value);
	if (!node)
		return ;
	node->next = *stack;
	*stack = node;
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

// Attribue des indices croissants à chaque élément
void assign_indices(t_stack *stack)
{
    t_stack *current;
    t_stack *compare;

    current = stack;
    while (current)
    {
        int index = 0;
        compare = stack;
        while (compare)
        {
            if (compare->value < current->value)
                index++;
            compare = compare->next;
        }
        current->index = index;
        current = current->next;
    }
}


#include "../inc/push_swap.h"

// Retourne le nombre d'éléments dans une pile
int get_stack_size(t_stack *stack)
{
    int size = 0;

    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return (size);
}
#include "../inc/push_swap.h"

// Retourne la position de l'élément avec l'index le plus bas dans la pile
int get_lowest_index_position(t_stack **stack)
{
    t_stack *tmp;
    int lowest_index;
    int lowest_pos;
    int pos;

    tmp = *stack;
    lowest_index = INT_MAX;
    lowest_pos = 0;
    pos = 0;

    while (tmp)
    {
        if (tmp->index < lowest_index)
        {
            lowest_index = tmp->index;
            lowest_pos = pos;
        }
        tmp = tmp->next;
        pos++;
    }
    return (lowest_pos);
}

