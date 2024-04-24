/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meabdelk <meabdelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 00:00:15 by meabdelk          #+#    #+#             */
/*   Updated: 2024/04/05 03:32:21 by meabdelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	pos_enemy(t_map *data)
{
	int	i;
	int	j;

	data->x_n = 0;
	data->y_n = 0;
	i = 0;
	while (i < data->countlines)
	{
		j = 0;
		while (j < data->len)
		{
			if (data->str[i][j] == 'N')
			{
				data->x_n = j;
				data->y_n = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
