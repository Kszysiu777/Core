/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbizon <kbizon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:44:41 by kbizon            #+#    #+#             */
/*   Updated: 2024/02/19 16:15:13 by kbizon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*join;
	unsigned int	i;
	unsigned int	j;

	join = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		join[j++] = s1[i++];
	i = 0;
	while (s2[i])
		join[j++] = s2[i++];
	join[j] = 0;
	return (join);
}

// #include <stdio.h>
// #include <bsd/string.h>

// int main()
// {
// 	char str1[] = "del";
// 	char str2[] = "ulu";
// 	printf("%s\n", str1);
// 	printf("%s\n", str2);
// 	printf("%s\n", ft_strjoin(str1, str2));
// 	return 0;
// }