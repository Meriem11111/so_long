/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meabdelk <meabdelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:59:03 by meabdelk          #+#    #+#             */
/*   Updated: 2024/04/06 01:50:03 by meabdelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_type(va_list args, const char format, int *len)
{
	if (format == '%')
		ft_putchar('%', len);
	else if (format == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (format == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (format == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), len);
	else if (format == 'p')
		ft_printadr(va_arg(args, void *), len);
	else if (format == 'x' || format == 'X')
		ft_putnbr_base(va_arg(args, int), format, len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) && ft_strchr("cidsupxX%", *(format + 1)))
			{
				format++;
				check_type(args, *format, &len);
			}
		}
		else
			ft_putchar(*format, &len);
		format++;
	}
	va_end(args);
	return (len);
}
