/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meabdelk <meabdelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:18:15 by meabdelk          #+#    #+#             */
/*   Updated: 2024/04/05 22:46:45 by meabdelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
