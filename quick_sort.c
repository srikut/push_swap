/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:18:40 by srikuto           #+#    #+#             */
/*   Updated: 2025/09/16 11:37:00 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	qs_loop(int *n, int *i, int *j, int pivot);

void	quick_sort(int *n, int left, int right)
{
	int	i;
	int	j;
	int	pivot;

	i = left;
	j = right;
	pivot = n[(left + right) / 2];
	qs_loop(n, &i, &j, pivot);
	if (left < j)
		quick_sort(n, left, j);
	if (i < right)
		quick_sort(n, i, right);
}

static void	qs_loop(int *n, int *i, int *j, int pivot)
{
	int	tmp;

	while (*i <= *j)
	{
		while (n[*i] < pivot)
			(*i)++;
		while (n[*j] > pivot)
			(*j)--;
		if (*i <= *j)
		{
			tmp = n[*i];
			n[*i] = n[*j];
			n[*j] = tmp;
			(*i)++;
			(*j)--;
		}
	}
}
