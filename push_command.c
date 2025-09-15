/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:49:14 by srikuto           #+#    #+#             */
/*   Updated: 2025/09/15 14:50:30 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_command(t_stack_node **from, t_stack_node **to);
void		pa(t_stack_node **a, t_stack_node **b);
void		pb(t_stack_node **a, t_stack_node **b);

void	pa(t_stack_node **a, t_stack_node **b)
{
	push_command(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push_command(a, b);
	write(1, "pb\n", 3);
}

static void	push_command(t_stack_node **from, t_stack_node **to)
{
	t_stack_node	*node;
	t_stack_node	*tail;
	t_stack_node	*head;

	if (!*from)
		return ;
	node = *from;
	if (node->next == node)
		*from = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		*from = node->next;
	}
	if (!*to)
	{
		node->next = node;
		node->prev = node;
		*to = node;
	}
	else
	{
		head = *to;
		tail = head->prev;
		node->next = head;
		node->prev = tail;
		tail->next = node;
		head->prev = node;
		*to = node;
	}
}
