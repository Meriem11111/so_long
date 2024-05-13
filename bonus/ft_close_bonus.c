/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meabdelk <meabdelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:18:15 by meabdelk          #+#    #+#             */
/*   Updated: 2024/05/13 23:09:07 by meabdelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	delete_window(t_map **map)
{
	free_memory(map);
	mlx_destroy_window((*map)->mlx, (*map)->win);
	free(*map);
	exit(0);
}

void	exit_err(t_map *data)
{
	write(2, "Error\nthere's more than ONE exit\n", 34);
	free2(data);
}

void	free2(t_map *data)
{
	free_memory(&data);
	free(data);
	exit(1);
}
