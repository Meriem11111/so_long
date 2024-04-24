/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_check_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meabdelk <meabdelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:40:59 by meabdelk          #+#    #+#             */
/*   Updated: 2024/04/05 23:04:58 by meabdelk         ###   ########.fr       */
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
	exit(1);
}

void	ft_err(void)
{
	write(2, "Error\nnumbers of args\n", 23);
	exit(0);
}

void	print_mvmnt(t_map *data_img)
{
	char	move_str[50];

	sprintf(move_str, "MOVE : %d", data_img->counter);
	mlx_string_put(data_img->mlx, data_img->win, 15, 6, 0xFFFFFF, move_str);
}
