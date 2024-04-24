/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meabdelk <meabdelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:02:49 by meabdelk          #+#    #+#             */
/*   Updated: 2023/12/18 19:55:15 by meabdelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nbr, int *len)
{
	if (nbr == -2147483648)
		ft_putstr("-2147483648", len);
	else if (nbr < 0)
	{
		ft_putchar('-', len);
		nbr = -nbr;
		ft_putnbr(nbr, len);
	}
	else if (nbr > 9)
	{
		ft_putnbr(nbr / 10, len);
		ft_putnbr(nbr % 10, len);
	}
	else
		ft_putchar((nbr + 48), len);
}
