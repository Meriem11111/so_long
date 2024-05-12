/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meabdelk <meabdelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:18:12 by meabdelk          #+#    #+#             */
/*   Updated: 2024/05/11 19:09:41 by meabdelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	invalid_img(void)
{
	write(2, "Error\ninvalid image\n", 20);
	exit(0);
}

void	print_img(t_map **data)
{
	(*data)->counter = 0;
	(*data)->img[0] = mlx_xpm_file_to_image((*data)->mlx, "./textures/1.xpm",
			&(*data)->win_width, &(*data)->win_height);
	(*data)->img[1] = mlx_xpm_file_to_image((*data)->mlx, "./textures/c2.xpm",
			&(*data)->win_width, &(*data)->win_height);
	(*data)->img[2] = mlx_xpm_file_to_image((*data)->mlx, "./textures/Door.xpm",
			&(*data)->win_width, &(*data)->win_height);
	(*data)->img[3] = mlx_xpm_file_to_image((*data)->mlx,
			"./textures/player.xpm", &(*data)->win_width, &(*data)->win_height);
	(*data)->img[4] = mlx_xpm_file_to_image((*data)->mlx,
			"./textures/floor.xpm", &(*data)->win_width, &(*data)->win_height);
	(*data)->img[5] = mlx_xpm_file_to_image((*data)->mlx,
			"./textures/OpenDoor.xpm", &(*data)->win_width,
			&(*data)->win_height);
	if (!(*data)->img[0] || !(*data)->img[1] || !(*data)->img[2]
		|| !(*data)->img[3] || !(*data)->img[4] || !(*data)->img[5])
	{
		write(2, "Error\ninvalid image\n", 20);
		free_memory(data);
		free(*data);
		exit(0);
	}
}

int	print_window(t_map *data)
{
	int	a;
	int	x;

	a = 0;
	x = 0;
	while (a < data->countlines)
	{
		print_map_line(data, a, x);
		a++;
		x += 50;
	}
	return (0);
}

void	print_image_for_e(t_map *data, int y, int x)
{
	if (data->c != 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img[2], y, x);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img[5], y, x);
}

void	print_map_line(t_map *data, int a, int x)
{
	int	b;
	int	y;

	b = 0;
	y = 0;
	while (data->str[a][b])
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img[4], y, x);
		if (data->str[a][b] == '1')
			mlx_put_image_to_window(data->mlx, data->win, data->img[0], y, x);
		else if (data->str[a][b] == 'E')
		{
			print_image_for_e(data, y, x);
		}
		else if (data->str[a][b] == 'P')
			mlx_put_image_to_window(data->mlx, data->win, data->img[3], y, x);
		else if (data->str[a][b] == 'C')
			mlx_put_image_to_window(data->mlx, data->win, data->img[1], y, x);
		y += 50;
		b++;
	}
}
