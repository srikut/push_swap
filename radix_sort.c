/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:51:19 by srikuto           #+#    #+#             */
/*   Updated: 2025/09/15 21:47:27 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack_node **a, t_stack_node **b)
{
	int				max_bits;
	int				bit;
	int				size;
	int				i;
	int				j;

	max_bits = 0;
	size = count_nodes(*a);
	while ((size - 1) >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		bit = (1 << i);
		while (j < size)
		{
			if (((*a)->rank & bit) != 0)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
