/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:56:41 by bluque-l          #+#    #+#             */
/*   Updated: 2023/07/18 22:46:28 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack, int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
	{
		return ;
	}
	new_node->value = value;
	new_node->index = -1;
	new_node->next = *stack;
	*stack = new_node;
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*temp;

	current = *stack;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*stack = NULL;
}
