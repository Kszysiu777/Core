/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbizon <kbizon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:44:32 by kbizon            #+#    #+#             */
/*   Updated: 2024/02/19 16:15:09 by kbizon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[len])
	{
		len++;
	}
	dest = (char *)malloc(len + 1);
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// #include <string.h>
// #include <stdio.h>

// int	main()
// {
// 	char text[] = "bcqwertyuioguygb";
// 	char *dup;
// 	dup = ft_strdup(text);
// 	printf ("OG 	%s", text);
// 	printf ("\nCOPY 	%s", dup);
// 	free (dup);
// 	return (0);
// }