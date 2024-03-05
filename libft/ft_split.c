/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbizon <kbizon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:59:57 by kbizon            #+#    #+#             */
/*   Updated: 2024/02/19 16:18:10 by kbizon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counting_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			++i;
		else
		{
			++count;
			while (str[i] && str[i] != c)
				++i;
		}
	}
	return (count);
}

static char	*ft_putword(char *word, char const *s, int i, int word_len)
{
	int	j;

	j = 0;
	while (word_len > 0)
	{
		word[j] = s[i - word_len];
		++j;
		word_len--;
	}
	word[j] = '\0';
	return (word);
}

static char	**free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (NULL);
}

static char	**split_words(char const *s, char c, char **s2, int num_words)
{
	int	i;
	int	word;
	int	word_len;

	i = 0;
	word = 0;
	word_len = 0;
	while (word < num_words)
	{
		while (s[i] && s[i] == c)
			++i;
		while (s[i] && s[i] != c)
		{
			++i;
			++word_len;
		}
		s2[word] = (char *)malloc((word_len + 1) * sizeof(char));
		if (!s2)
			return (free_array(s2, word));
		ft_putword(s2[word], s, i, word_len);
		word_len = 0;
		++word;
	}
	s2[word] = 0;
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	char			**strings;
	unsigned int	wordcount;

	if (!s)
		return (0);
	wordcount = counting_words(s, c);
	strings = (char **)malloc((wordcount + 1) * sizeof(char *));
	if (!strings)
		return (0);
	strings = split_words(s, c, strings, wordcount);
	return (strings);
}

// int main()
// {
// 	char *str = "   lorem   ipsum dolor     sit amet, consectetur   
// 				adipiscing elit. Sed non risus. Suspendisse  ";
// 	char c = ' ';
// 	int i = 0;
// 	char **new_str = ft_split(str, c);
// 	while (new_str[i] != NULL)
// 	{
// 		printf("%s\n", new_str[i]);
// 		++i;
// 	}
// }