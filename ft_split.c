/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 19:01:34 by srikuto           #+#    #+#             */
/*   Updated: 2025/07/26 21:11:33 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**free_all(char **split, size_t i)
{
	size_t	idx;

	idx = 0;
	while (idx < i)
	{
		free(split[idx]);
		idx++;
	}
	free (split);
	return (NULL);
}

static size_t	word_count(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			count++;
			while (*s != '\0' && *s != c)
				s++;
		}
	}
	return (count);
}

static char	**malloc_word_len(char **split, char const *s, char c)
{
	size_t	i;
	size_t	word_len;

	i = 0;
	word_len = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			word_len = 0;
			while (*s != c && *s != '\0')
			{
				s++;
				word_len++;
			}
			split[i] = (char *)malloc(sizeof(char) * (word_len + 1));
			if (!split[i])
				return (free_all(split, i));
			i++;
		}
		else
			s++;
	}
	split[i] = NULL;
	return (split);
}

static char	**assign_char(char **split, const char *s, char c)
{
	size_t	i;
	size_t	k;
	size_t	j;

	i = 0;
	k = 0;
	while (s[k] != '\0')
	{
		if (s[k] != c)
		{
			j = 0;
			while (s[k] != c && s[k] != '\0')
			{
				split[i][j] = s[k];
				k++;
				j++;
			}
			split[i][j] = '\0';
			i++;
		}
		else
			k++;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	size_t	num_words;
	char	**split;
	char	**str;

	if (s == NULL)
		return (NULL);
	num_words = word_count(s, c);
	str = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (str == NULL)
		return (NULL);
	split = malloc_word_len(str, s, c);
	if (split == NULL)
	{
		free(str);
		return (NULL);
	}
	return (assign_char(split, s, c));
}
