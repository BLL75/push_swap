/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:55:28 by bluque-l          #+#    #+#             */
/*   Updated: 2023/07/19 12:06:56 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	*input;
	int		size;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	input = concatenate_arguments(argc, argv);
	process_arguments(input, &a);
	free(input);
	a = reverse_stack(a);
	if (is_sorted(a))
	{
		cleanup(&a, &b);
		return (0);
	}
	size = get_stack_size(a);
	sort_stack(&a, &b, size);
	cleanup(&a, &b);
	return (0);
}
