/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meabdelk <meabdelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:18:15 by meabdelk          #+#    #+#             */
/*   Updated: 2024/05/13 21:41:34 by meabdelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_window(t_map **map)
{
	free_memory(map);
	mlx_destroy_window((*map)->mlx, (*map)->win);
	free(*map);
	system("leaks so_long");
	exit(0);
}

void	free2(t_map *data)
{
	free_memory(&data);
	free(data);
	system("leaks so_long");
	exit(1);
}
