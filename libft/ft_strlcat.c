/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbizon <kbizon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:35:22 by kbizon            #+#    #+#             */
/*   Updated: 2024/02/20 18:19:43 by kbizon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;

	i = 0;
	j = 0;
	src_len = ft_strlen(src);
	while (dst[i] != '\0' && i < size)
		++i;
	while (src[j] != '\0' && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		++j;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (src_len + i);
}

// #include <stdio.h>
// #include <bsd/string.h>

// int main()
// {
// 	char src[] = "dgoul";
// 	char dst[50] = "qwerty";
// 	printf("%zu",ft_strlcat(dst, src, 50));
// }