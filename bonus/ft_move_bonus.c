/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meabdelk <meabdelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:18:09 by meabdelk          #+#    #+#             */
/*   Updated: 2024/04/05 03:32:51 by meabdelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	pos_player(t_map *data)
{
	int	i;
	int	j;

	data->x_p = 0;
	data->y_p = 0;
	i = 0;
	while (i < data->countlines)
	{
		j = 0;
		while (j < data->len)
		{
			if (data->str[i][j] == 'P')
			{
				data->x_p = j;
				data->y_p = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	to_down(t_map **data)
{
	int	x;
	int	y;

	x = (*data)->x_p;
	y = (*data)->y_p;
	if ((*data)->str[y + 1][x] != '1' && ((*data)->c == 0 || (*data)->str[y
			+ 1][x] != 'E'))
	{
		if ((*data)->str[y + 1][x] == 'N')
		{
			write(1, "YOU LOST!\n", 11);
			delete_window(data);
		}
		if ((*data)->str[y + 1][x] == 'C' && (*data)->c != 0)
			(*data)->c--;
		if ((*data)->str[y + 1][x] == 'E' && (*data)->c == 0)
		{
			(*data)->counter++;
			write(1, "YOU WIN !!", 11);
			delete_window(data);
		}
		(*data)->str[y][x] = '0';
		(*data)->str[y + 1][x] = 'P';
		(*data)->counter++;
	}
}

void	to_up(t_map **data)
{
	int	x;
	int	y;

	x = (*data)->x_p;
	y = (*data)->y_p;
	if ((*data)->str[y - 1][x] != '1' && ((*data)->c == 0 || (*data)->str[y
			- 1][x] != 'E'))
	{
		if ((*data)->str[y - 1][x] == 'N')
		{
			write(1, "YOU LOST!\n", 11);
			delete_window(data);
		}
		if ((*data)->str[y - 1][x] == 'C' && (*data)->c != 0)
			(*data)->c--;
		if ((*data)->str[y - 1][x] == 'E' && (*data)->c == 0)
		{
			(*data)->counter++;
			write(1, "YOU WIN !!", 11);
			delete_window(data);
		}
		(*data)->str[y][x] = '0';
		(*data)->str[y - 1][x] = 'P';
		(*data)->counter++;
	}
}

void	to_right(t_map **data)
{
	int	x;
	int	y;

	x = (*data)->x_p;
	y = (*data)->y_p;
	if ((*data)->str[y][x + 1] != '1' && ((*data)->c == 0 || (*data)->str[y][x
			+ 1] != 'E'))
	{
		if ((*data)->str[y][x + 1] == 'N')
		{
			write(1, "YOU LOST!\n", 11);
			delete_window(data);
		}
		if ((*data)->str[y][x + 1] == 'C' && (*data)->c != 0)
			(*data)->c--;
		if ((*data)->str[y][x + 1] == 'E' && (*data)->c == 0)
		{
			(*data)->counter++;
			write(1, "YOU WIN !!", 11);
			delete_window(data);
		}
		(*data)->str[y][x] = '0';
		(*data)->str[y][x + 1] = 'P';
		(*data)->counter++;
	}
}

void	to_left(t_map **data)
{
	int	x;
	int	y;

	x = (*data)->x_p;
	y = (*data)->y_p;
	if ((*data)->str[y][x - 1] != '1' && ((*data)->c == 0 || (*data)->str[y][x
			- 1] != 'E'))
	{
		if ((*data)->str[y][x - 1] == 'N')
		{
			write(1, "YOU LOST!\n", 11);
			delete_window(data);
		}
		if ((*data)->str[y][x - 1] == 'C' && (*data)->c != 0)
			(*data)->c--;
		if ((*data)->str[y][x - 1] == 'E' && (*data)->c == 0)
		{
			(*data)->counter++;
			write(1, "YOU WIN !!", 11);
			delete_window(data);
		}
		(*data)->str[y][x] = '0';
		(*data)->str[y][x - 1] = 'P';
		(*data)->counter++;
	}
}
