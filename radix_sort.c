/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:51:19 by srikuto           #+#    #+#             */
/*   Updated: 2025/09/16 12:06:03 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calc_max_bits(int size);
static void	radix_pass(t_stack_node **a, t_stack_node **b, int size, int bit);
static void	drain_b(t_stack_node **a, t_stack_node **b);

void	radix_sort(t_stack_node **a, t_stack_node **b)
{
	int	size;
	int	max_bits;
	int	i;

	if (!a || !*a)
		return ;
	size = count_nodes(*a);
	max_bits = calc_max_bits(size);
	i = 0;
	while (i < max_bits)
	{
		radix_pass(a, b, size, (1 << i));
		drain_b(a, b);
		i++;
	}
}

static int	calc_max_bits(int size)
{
	int	bits;

	bits = 0;
	while ((size - 1) >> bits)
		bits++;
	return (bits);
}

static void	radix_pass(t_stack_node **a, t_stack_node **b, int size, int bit)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (((*a)->rank & bit) != 0)
			ra(a);
		else
			pb(a, b);
		j++;
	}
}

static void	drain_b(t_stack_node **a, t_stack_node **b)
{
	while (*b)
		pa(a, b);
}

// void	radix_sort(t_stack_node **a, t_stack_node **b)
// {
// 	int				max_bits;
// 	int				bit;
// 	int				size;
// 	int				i;
// 	int				j;

// 	max_bits = 0;
// 	size = count_nodes(*a);
// 	while ((size - 1) >> max_bits)
// 		max_bits++;
// 	i = 0;
// 	while (i < max_bits)
// 	{
// 		j = 0;
// 		bit = (1 << i);
// 		while (j < size)
// 		{
// 			if (((*a)->rank & bit) != 0)
// 				ra(a);
// 			else
// 				pb(a, b);
// 			j++;
// 		}
// 		while (*b)
// 			pa(a, b);
// 		i++;
// 	}
// }
