/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalkan <ikalkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:48:00 by ikalkan           #+#    #+#             */
/*   Updated: 2025/06/18 13:05:46 by ikalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	word_count(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static void	free_all(char **tab, int i)
{
	while (i--)
		free(tab[i]);
	free(tab);
}

static char	*fill_next_word(const char **s, char c)
{
	int		len;
	char	*word;

	while (**s == c)
		(*s)++;
	len = 0;
	while ((*s)[len] && (*s)[len] != c)
		len++;
	word = ft_substr(*s, 0, len);
	*s += len;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		words;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	tab = malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < words)
	{
		tab[i] = fill_next_word(&s, c);
		if (!tab[i])
			return (free_all(tab, i), NULL);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
