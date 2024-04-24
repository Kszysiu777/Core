/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbizon <kbizon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:21:29 by kbizon            #+#    #+#             */
/*   Updated: 2024/04/24 11:00:31 by kbizon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *str1)
{
	char	*str2;
	int		length;
	size_t	i;

	i = 0;
	length = ft_strlen(str1);
	str2 = malloc(sizeof(char) * (length + 1));
	if (!str2)
		return (0);
	while (str1[i])
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substring;
	int		i;

	i = 0;
	if (!s || !len)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (ft_strlen(s) <= (size_t)start)
		return (ft_strdup(""));
	if (ft_strlen(s) <= len + (size_t)start)
		len = ft_strlen(s) - start;
	substring = (char *)malloc((len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	while (len-- > 0)
		substring[i++] = s[start++];
	substring[i] = '\0';
	return (substring);
}

char	*ft_strjoin(char *buff, char *new)
{
	char	*string;
	int		length;
	int		i;
	int		j;

	length = 0;
	i = 0;
	j = 0;
	if (!buff || !new)
		return (NULL);
	length = ft_strlen(buff) + ft_strlen(new);
	string = (char *)malloc((sizeof(char) * (length + 1)));
	if (!string)
		return (NULL);
	while (buff[i])
		string[j++] = buff[i++];
	i = 0;
	while (new[i])
		string[j++] = new[i++];
	string[j] = '\0';
	if (buff)
		free(buff);
	buff = NULL;
	return (string);
}

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (c == 0)
		return ((char *)(s + i));
	return (NULL);
}
