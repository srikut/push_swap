/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:41:27 by srikuto           #+#    #+#             */
/*   Updated: 2025/09/16 10:50:01 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_mins_until_three(t_stack_node **a, t_stack_node **b);
static void	restore_from_b(t_stack_node **a, t_stack_node **b);

void	sort_small(t_stack_node **a, t_stack_node **b)
{
	int	n;

	if (!a || !*a)
		return ;
	n = count_nodes(*a);
	if (is_sorted(*a))
		return ;
	if (n == 2)
	{
		if ((*a)->rank > (*a)->next->rank)
			sa(a);
		return ;
	}
	if (n == 3)
	{
		sort_three(a);
		return ;
	}
	push_mins_until_three(a, b);
	sort_three(a);
	restore_from_b(a, b);
}

static void	push_mins_until_three(t_stack_node **a, t_stack_node **b)
{
	int	size;
	int	pos;

	while (count_nodes(*a) > 3)
	{
		size = count_nodes(*a);
		pos = index_of_min(*a);
		rotate_to_top(a, pos, size);
		pb(a, b);
	}
}

static void	restore_from_b(t_stack_node **a, t_stack_node **b)
{
	while (*b)
		pa(a, b);
}
