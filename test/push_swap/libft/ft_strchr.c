/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbizon <kbizon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:35:22 by kbizon            #+#    #+#             */
/*   Updated: 2024/03/13 17:12:57 by kbizon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		++i;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	int c = 'y';
// 	printf("%s",ft_strchr("qwdfyvbnm", c));
// }