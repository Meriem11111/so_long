/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meabdelk <meabdelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:43:07 by meabdelk          #+#    #+#             */
/*   Updated: 2024/04/06 01:06:34 by meabdelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_hook(int keycode, t_map **map)
{
	pos_player(*map);
	pos_enemy(*map);
	if (keycode == 2 || keycode == 124)
		to_right(map);
	else if (keycode == 0 || keycode == 123)
		to_left(map);
	else if (keycode == 13 || keycode == 126)
		to_up(map);
	else if (keycode == 1 || keycode == 125)
		to_down(map);
	else if (keycode == 53)
		close_win(map);
	mlx_clear_window((*map)->mlx, (*map)->win);
	print_window(*map);
	return (0);
}

void	check_file(char *file)
{
	int		i;
	int		j;
	char	*str;

	i = ft_strlen(file);
	str = ".ber";
	j = ft_strlen(str);
	if (i < j)
		err_file();
	while (j >= 0)
	{
		if (file[i] != str[j])
			err_file();
		i--;
		j--;
	}
	if (i >= 0 && file[i] == '/')
		err_file();
}

int	main(int ac, char **av)
{
	t_map	*data;

	if (ac <= 1)
		exit(0);
	if (ac != 2)
		ft_err();
	check_file(av[1]);
	data = malloc(sizeof(t_map));
	if (!data)
		return (1);
	read_map(av[1], &data);
	check_line(av[1]);
	check_error(data);
	free_memory(&data);
	read_map(av[1], &data);
	data->counter = 0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->len * 50, data->countlines * 50,
			"SO_LONG_BONUS");
	print_img(&data);
	mlx_loop_hook(data->mlx, print_window, data);
	mlx_hook(data->win, 2, 0L, key_hook, &data);
	mlx_hook(data->win, 17, 0, (void *)delete_window, &data);
	mlx_loop(data->mlx);
}
