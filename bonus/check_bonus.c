/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meabdelk <meabdelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:11:07 by meabdelk          #+#    #+#             */
/*   Updated: 2024/05/13 21:31:02 by meabdelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_error(t_map *data)
{
	if (data->e == 0)
	{
		write(2, "Error\nExit is missing\n", 23);
		free2(data);
	}
	else if (data->e > 1)
		exit_err(data);
	else if (data->c < 1)
	{
		write(2, "Error\ncollectible is missing\n", 30);
		free2(data);
	}
	else if (data->p == 0)
	{
		write(2, "Error\nPlayer is missing\n", 25);
		free2(data);
	}
	else if (data->n == 0)
		ennemy_error(data);
	else if (data->p > 1)
	{
		write(2, "Error\nthere's more than ONE player\n", 28);
		free2(data);
	}
}

void	flood_fill(t_map **data, int x, int y)
{
	if (x < 0 || y < 0 || x >= (*data)->len || y >= (*data)->countlines)
		return ;
	if ((*data)->str[y][x] == 'E')
		(*data)->str[y][x] = '1';
	if ((*data)->str[y][x] == 'P' || (*data)->str[y][x] == 'E'
		|| (*data)->str[y][x] == 'C' || (*data)->str[y][x] == '0')
	{
		(*data)->str[y][x] = 'X';
		flood_fill(data, x + 1, y);
		flood_fill(data, x, y + 1);
		flood_fill(data, x - 1, y);
		flood_fill(data, x, y - 1);
	}
}

int	check_valid_map(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->countlines)
	{
		j = 0;
		while (j < data->len)
		{
			if (data->str[i][j] == 'E' || data->str[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_size(t_map *data)
{
	if (data->len > 52 || data->countlines > 27)
	{
		write(2, "Error\nInvalid size window\n", 27);
		free_memory(&data);
		free(data);
		system("leaks so_long");
		exit(1);
	}
}

void	check_error(t_map *data)
{
	check_len(data);
	check_first_last(data, 0);
	check_first_last(data, data->countlines - 1);
	check_left_right(data);
	check_characters(data);
	check_size(data);
	pos_player(data);
	flood_fill(&data, data->x_p, data->y_p);
	if (check_valid_map(data) == 0)
	{
		free_memory(&data);
		write(2, "Error\nInvalid Map\n", 19);
		free(data);
		system("leaks so_long");
		exit(0);
	}
}
