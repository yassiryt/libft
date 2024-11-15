/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatanagh <yatanagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:17:58 by yatanagh          #+#    #+#             */
/*   Updated: 2024/11/15 16:17:18 by yatanagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_memory(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

static int	count_words(const char *str, char c)
{
	int	i;
	int	count_word;

	i = 0;
	count_word = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			count_word++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count_word);
}

static char	*extract_word(const char *str, int *index, char c)
{
	char	*word;
	int		start;
	int		len;

	while (str[*index] == c)
		(*index)++;
	start = *index;
	len = 0;
	while (str[*index] && str[*index] != c)
	{
		(*index)++;
		len++;
	}
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	word[len] = '\0';
	while (len--)
		word[len] = str[start + len];
	return (word);
}

char	**ft_split(char const *str, char c)
{
	char	**result;
	int		count_word;
	int		i;
	int		index;

	if (!str)
		return (NULL);
	count_word = count_words(str, c);
	result = (char **)malloc(sizeof(char *) * (count_word + 1));
	if (!result)
		return (NULL);
	i = 0;
	index = 0;
	while (i < count_word)
	{
		result[i] = extract_word(str, &index, c);
		if (!result[i])
		{
			free_memory(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
