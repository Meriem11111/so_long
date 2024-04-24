/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meabdelk <meabdelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:18:15 by meabdelk          #+#    #+#             */
/*   Updated: 2024/04/06 01:30:38 by meabdelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	delete_window(t_map **map)
{
	free_memory(map);
	mlx_destroy_window((*map)->mlx, (*map)->win);
	exit(0);
}

void	close_win(t_map **map)
{
	free_memory(map);
	mlx_destroy_window((*map)->mlx, (*map)->win);
	exit(0);
}
