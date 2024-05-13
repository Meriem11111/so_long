/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_check_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meabdelk <meabdelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:40:59 by meabdelk          #+#    #+#             */
/*   Updated: 2024/05/13 21:31:50 by meabdelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strchar(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return (1);
	return (0);
}

void	ft_initialize(t_map *data)
{
	data->x = 0;
	data->e = 0;
	data->c = 0;
	data->p = 0;
	data->n = 0;
}

void	err_file(void)
{
	ft_printf("Error\nInvalid file\n");
	system("leaks so_long");
	exit(1);
}

void	ft_err(void)
{
	write(2, "Error\nnumbers of args\n", 23);
	system("leaks so_long");
	exit(0);
}
