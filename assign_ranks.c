/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_ranks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:52:18 by srikuto           #+#    #+#             */
/*   Updated: 2025/09/15 21:43:53 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		assign_ranks(t_stack_node *a);
int			count_nodes(t_stack_node *a);
static void	copy_array(t_stack_node *a, int *arr);
static void	quick_sort(int *n, int left, int right);
static int	find_rank(int *arr, int n, int key);

void	assign_ranks(t_stack_node *a)
{
	t_stack_node	*tmp;
	t_stack_node	*start;
	int				*arr;
	int				n;

	if (!a)
		return ;
	n = count_nodes(a);
	arr = (int *)malloc(sizeof(int) * n);
	if (!arr)
		return ;
	copy_array(a, arr);
	quick_sort(arr, 0, n - 1);
	start = a;
	tmp = a;
	while (tmp->next != start)
	{
		tmp->rank = find_rank(arr, n, tmp->value);
		tmp = tmp->next;
	}
	tmp->rank = find_rank(arr, n, tmp->value);
	free (arr);
}

static int	find_rank(int *arr, int n, int key)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = n - 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] == key)
			return (mid);
		else if (arr[mid] < key)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}

static void	quick_sort(int *n, int left, int right)
{
	int	i;
	int	j;
	int	pivot;
	int	tmp;

	i = left;
	j = right;
	pivot = n[(left + right) / 2];
	while (i <= j)
	{
		while (n[i] < pivot)
			i++;
		while (n[j] > pivot)
			j--;
		if (i <= j)
		{
			tmp = n[i];
			n[i] = n[j];
			n[j] = tmp;
			i++;
			j--;
		}
	}
	if (left < j)
		quick_sort(n, left, j);
	if (i < right)
		quick_sort(n, i, right);
}

static void	copy_array(t_stack_node *a, int *arr)
{
	t_stack_node	*head;
	int				i;

	if (!a)
		return ;
	i = 0;
	head = a;
	while (i == 0 || a != head)
	{
		arr[i] = a->value;
		a = a->next;
		i++;
	}
}

int	count_nodes(t_stack_node *a)
{
	int				cnt;
	t_stack_node	*cur;

	cnt = 1;
	if (!a)
		return (0);
	cur = a->next;
	while (cur != a)
	{
		cnt++;
		cur = cur->next;
	}
	return (cnt);
}
