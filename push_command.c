/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:49:14 by srikuto           #+#    #+#             */
/*   Updated: 2025/09/16 12:53:51 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			push_command(t_stack_node **from, t_stack_node **to);
void				pa(t_stack_node **a, t_stack_node **b);
void				pb(t_stack_node **a, t_stack_node **b);
static t_stack_node	*extract_head(t_stack_node **s);
static void			insert_front(t_stack_node **s, t_stack_node *node);

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

void	push_command(t_stack_node **from, t_stack_node **to)
{
	t_stack_node	*node;

	node = extract_head(from);
	if (!node)
		return ;
	insert_front(to, node);
}

static t_stack_node	*extract_head(t_stack_node **s)
{
	t_stack_node	*node;

	if (!s || !*s)
		return (NULL);
	node = *s;
	if (node->next == node)
	{
		*s = NULL;
		return (node);
	}
	node->prev->next = node->next;
	node->next->prev = node->prev;
	*s = node->next;
	return (node);
}

static void	insert_front(t_stack_node **s, t_stack_node *node)
{
	t_stack_node	*head;
	t_stack_node	*tail;

	if (!node || !s)
		return ;
	if (!*s)
	{
		node->next = node;
		node->prev = node;
		*s = node;
		return ;
	}
	head = *s;
	tail = head->prev;
	node->next = head;
	node->prev = tail;
	tail->next = node;
	head->prev = node;
	*s = node;
}
