/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meabdelk <meabdelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:40:59 by meabdelk          #+#    #+#             */
/*   Updated: 2024/05/11 21:34:45 by meabdelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	data->y = 0;
	data->e = 0;
	data->c = 0;
	data->p = 0;
}

void	counter_print_move(t_map *map)
{
	(map->counter)++;
	ft_printf("Move : %d\n", map->counter);
}

void	err_file(void)
{
	ft_printf("Error\nInvalid file\n");
	exit(1);
}

void	ft_err(void)
{
	write(2, "Error\nnumber of args\n", 22);
	exit(0);
}
