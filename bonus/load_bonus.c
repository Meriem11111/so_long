/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meabdelk <meabdelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:18:12 by meabdelk          #+#    #+#             */
/*   Updated: 2024/04/21 16:09:05 by meabdelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	invalid_img(void)
{
	write(2, "Error\ninvalid image\n", 20);
	exit(0);
}

void	print_img(t_map **data)
{
	(*data)->img[0] = mlx_xpm_file_to_image((*data)->mlx, "./textures/1.xpm",
			&(*data)->win_width, &(*data)->win_height);
	(*data)->img[1] = mlx_xpm_file_to_image((*data)->mlx, "./textures/c2.xpm",
			&(*data)->win_width, &(*data)->win_height);
	(*data)->img[2] = mlx_xpm_file_to_image((*data)->mlx, "./textures/D1.xpm",
			&(*data)->win_width, &(*data)->win_height);
	(*data)->img[3] = mlx_xpm_file_to_image((*data)->mlx,
			"./textures/player.xpm", &(*data)->win_width, &(*data)->win_height);
	(*data)->img[4] = mlx_xpm_file_to_image((*data)->mlx,
			"./textures/floor.xpm", &(*data)->win_width, &(*data)->win_height);
	(*data)->img[5] = mlx_xpm_file_to_image((*data)->mlx, "./textures/D2.xpm",
			&(*data)->win_width, &(*data)->win_height);
	(*data)->img[6] = mlx_xpm_file_to_image((*data)->mlx, "./textures/D3.xpm",
			&(*data)->win_width, &(*data)->win_height);
	(*data)->img[7] = mlx_xpm_file_to_image((*data)->mlx, "./textures/D4.xpm",
			&(*data)->win_width, &(*data)->win_height);
	(*data)->img[8] = mlx_xpm_file_to_image((*data)->mlx, "./textures/D5.xpm",
			&(*data)->win_width, &(*data)->win_height);
	(*data)->img[9] = mlx_xpm_file_to_image((*data)->mlx, "./textures/N.xpm",
			&(*data)->win_width, &(*data)->win_height);
	if (!(*data)->img[0] || !(*data)->img[1] || !(*data)->img[2]
		|| !(*data)->img[3] || !(*data)->img[4] || !(*data)->img[5]
		|| !(*data)->img[6] || !(*data)->img[7] || !(*data)->img[8]
		|| !(*data)->img[9])
		invalid_img();
}

void	animation_exit(t_map *data)
{
	static int	i = 0;

	i++;
	if (i < 20)
		mlx_put_image_to_window(data->mlx, data->win, data->img[2],
			data->pos_e[1] * 50, data->pos_e[0] * 50);
	else if (i < 40)
		mlx_put_image_to_window(data->mlx, data->win, data->img[5],
			data->pos_e[1] * 50, data->pos_e[0] * 50);
	else if (i < 60)
		mlx_put_image_to_window(data->mlx, data->win, data->img[6],
			data->pos_e[1] * 50, data->pos_e[0] * 50);
	else if (i < 80)
		mlx_put_image_to_window(data->mlx, data->win, data->img[7],
			data->pos_e[1] * 50, data->pos_e[0] * 50);
	else if (i < 100)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img[8],
			data->pos_e[1] * 50, data->pos_e[0] * 50);
		i = 0;
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
	print_mvmnt(data);
	return (0);
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
			data->pos_e[0] = a;
			data->pos_e[1] = b;
			animation_exit(data);
		}
		else if (data->str[a][b] == 'P')
			mlx_put_image_to_window(data->mlx, data->win, data->img[3], y, x);
		else if (data->str[a][b] == 'C')
			mlx_put_image_to_window(data->mlx, data->win, data->img[1], y, x);
		else if (data->str[a][b] == 'N')
			mlx_put_image_to_window(data->mlx, data->win, data->img[9], y, x);
		y += 50;
		b++;
	}
}
