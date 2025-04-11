/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbizon <kbizon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:35:22 by kbizon            #+#    #+#             */
/*   Updated: 2024/02/20 21:39:54 by kbizon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long	i;
	char			*c1;
	char			*c2;

	i = 0;
	c1 = (char *)s1;
	c2 = (char *)s2;
	while (i < n)
	{
		if (c1[i] != c2[i])
			return ((unsigned char)c1[i] - (unsigned char)c2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
//    	char str1[50] = "string1";
// 	printf("%s\n", str1);

// 	char str2[50] = "string2";
// 	printf("%s\n", str2);

// 	int x;
// 	x = ft_memcmp(str1, str2, 4);
// 	printf("%s\n", str1);
// 	printf("%s\n", str2);
// 	printf("%d", x);

//    	return(0);
// }