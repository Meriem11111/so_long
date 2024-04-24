/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meabdelk <meabdelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:25:38 by meabdelk          #+#    #+#             */
/*   Updated: 2023/12/18 19:55:08 by meabdelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int nbr, char Xx, int *len)
{
	char	*base;

	if (Xx == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbr < 16)
		ft_putchar(base[nbr], len);
	else
	{
		ft_putnbr_base(nbr / 16, Xx, len);
		ft_putnbr_base(nbr % 16, Xx, len);
	}
}
