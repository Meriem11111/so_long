/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printadrs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meabdelk <meabdelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:19:55 by meabdelk          #+#    #+#             */
/*   Updated: 2023/12/18 19:54:33 by meabdelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printadr_hex(unsigned long nb, int *len)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb < 16)
		ft_putchar(base[nb], len);
	else
	{
		ft_printadr_hex(nb / 16, len);
		ft_printadr_hex(nb % 16, len);
	}
}

void	ft_printadr(void *adr, int *len)
{
	unsigned long	ptr;

	ptr = (unsigned long)adr;
	ft_putstr("0x", len);
	ft_printadr_hex(ptr, len);
}
