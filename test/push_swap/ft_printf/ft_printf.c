/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbizon <kbizon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:34:04 by kbizon            #+#    #+#             */
/*   Updated: 2024/02/24 18:01:07 by kbizon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nullptr(void *ptr)
{
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + ft_putptr(ptr));
}

static int	ft_formats(va_list args, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (format == '%')
		return (ft_putchar('%'));
	if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (format == 'u')
		return (ft_putstr(ft_conv(va_arg(args, unsigned int), "0123456789")));
	if (format == 'x')
		return (ft_putstr(
				ft_conv(va_arg(args, unsigned int), "0123456789abcdef")));
	if (format == 'X')
		return (ft_putstr(
				ft_conv(va_arg(args, unsigned int), "0123456789ABCDEF")));
	if (format == 'p')
		return (ft_nullptr(va_arg(args, void *)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
			len += ft_formats(args, str[++i]);
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
