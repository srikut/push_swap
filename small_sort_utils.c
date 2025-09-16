/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:22:30 by srikuto           #+#    #+#             */
/*   Updated: 2025/09/16 10:50:45 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack_node *a)
{
	t_stack_node	*cur;

	if (!a || a->next == a)
		return (1);
	cur = a;
	while (cur->next != a)
	{
		if (cur->rank > cur->next->rank)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	index_of_min(t_stack_node *a)
{
	int				pos;
	int				best_pos;
	int				best;
	t_stack_node	*cur;

	pos = 0;
	best_pos = 0;
	best = a->rank;
	cur = a->next;
	while (cur != a)
	{
		pos++;
		if (cur->rank < best)
		{
			best = cur->rank;
			best_pos = pos;
		}
		cur = cur->next;
	}
	return (best_pos);
}

void	rotate_to_top(t_stack_node **a, int pos, int size)
{
	int	i;

	i = 0;
	if (pos <= size / 2)
	{
		while (i < pos)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		while (i < size - pos)
		{
			rra(a);
			i++;
		}
	}
}

void	sort_three(t_stack_node **a)
{
	int	x;
	int	y;
	int	z;

	if (is_sorted(*a))
		return ;
	x = (*a)->rank;
	y = (*a)->next->rank;
	z = (*a)->next->next->rank;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

// void	sort_small(t_stack_node **a, t_stack_node **b)
// {
// 	int	n;
// 	int	size;
// 	int	pos;

// 	n = count_nodes(*a);
// 	if (is_sorted(*a))
// 		return ;
// 	if (n == 2)
// 	{
// 		if ((*a)->rank > (*a)->next->rank)
// 			sa(a);
// 		return ;
// 	}
// 	if (n == 3)
// 	{
// 		sort_three(a);
// 		return ;
// 	}
// 	while (count_nodes(*a) > 3)
// 	{
// 		size = count_nodes(*a);
// 		pos = index_of_min(*a);
// 		rotate_to_top(a, pos, size);
// 		pb(a, b);
// 	}
// 	sort_three(a);
// 	while (*b)
// 		pa(a, b);
// }
