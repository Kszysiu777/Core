/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbizon <kbizon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:59:25 by kbizon            #+#    #+#             */
/*   Updated: 2024/02/19 16:51:43 by kbizon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*new;

	if (nmemb == 0 || size == 0)
	{
		new = malloc(0);
		return (new);
	}
	new = (void *)malloc(nmemb * size);
	if (!new)
		return (NULL);
	ft_bzero(new, nmemb);
	return (new);
}
