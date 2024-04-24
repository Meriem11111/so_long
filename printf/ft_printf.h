/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meabdelk <meabdelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:13:27 by meabdelk          #+#    #+#             */
/*   Updated: 2024/04/03 23:48:11 by meabdelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *s, int *len);
void	ft_putnbr_base(unsigned int nbr, char Xx, int *len);
void	ft_putnbr(int nbr, int *len);
void	ft_printadr(void *adr, int *len);
void	ft_putnbr_unsigned(unsigned int nbr, int *len);
char	*ft_strchr(const char *s, int c);
#endif