/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbizon <kbizon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:31:34 by kbizon            #+#    #+#             */
/*   Updated: 2024/02/24 15:26:07 by kbizon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	if (!str)
		return (ft_putstr("(null)"));
	return (write(1, str, ft_strlen(str)));
}

int	ft_putnbr(int nbr)
{
	char	*num;
	int		len;

	len = 0;
	num = ft_itoa(nbr);
	len += ft_putstr(num);
	free(num);
	return (len);
}

int	ft_putptr(void *ptr)
{
	unsigned long	put;
	int				len;

	put = (unsigned long)ptr;
	len = 0;
	if (put > 15)
		len += ft_putptr((void *)(put / 16));
	len += ft_putchar("0123456789abcdef"[put % 16]);
	return (len);
}

char	*ft_conv(unsigned int num, char *set)
{
	static char	buffer[50];
	char		*ptr;
	int			base;

	base = ft_strlen(set);
	ptr = &buffer[49];
	*ptr = '\0';
	*--ptr = set[num % base];
	num /= base;
	while (num != 0)
	{
		*--ptr = set[num % base];
		num /= base;
	}
	return (ptr);
}
