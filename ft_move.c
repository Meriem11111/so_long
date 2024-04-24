/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meabdelk <meabdelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:18:09 by meabdelk          #+#    #+#             */
/*   Updated: 2024/04/05 06:07:37 by meabdelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		if ((*data)->str[y + 1][x] == 'C' && (*data)->c != 0)
			(*data)->c--;
		if ((*data)->str[y + 1][x] == 'E' && (*data)->c == 0)
		{
			(*data)->counter++;
			ft_printf("Move : %d\n", (*data)->counter);
			write(1, "YOU WIN !!", 11);
			delete_window(data);
		}
		(*data)->str[y][x] = '0';
		(*data)->str[y + 1][x] = 'P';
		counter_print_move(*data);
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
		if ((*data)->str[y - 1][x] == 'C' && (*data)->c != 0)
			(*data)->c--;
		if ((*data)->str[y - 1][x] == 'E' && (*data)->c == 0)
		{
			(*data)->counter++;
			ft_printf("Move : %d\n", (*data)->counter);
			write(1, "YOU WIN !!", 11);
			delete_window(data);
		}
		(*data)->str[y][x] = '0';
		(*data)->str[y - 1][x] = 'P';
		counter_print_move(*data);
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
		if ((*data)->str[y][x + 1] == 'C' && (*data)->c != 0)
			(*data)->c--;
		if ((*data)->str[y][x + 1] == 'E' && (*data)->c == 0)
		{
			(*data)->counter++;
			ft_printf("Move : %d\n", (*data)->counter);
			write(1, "YOU WIN !!", 11);
			delete_window(data);
		}
		(*data)->str[y][x] = '0';
		(*data)->str[y][x + 1] = 'P';
		counter_print_move(*data);
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
		if ((*data)->str[y][x - 1] == 'C' && (*data)->c != 0)
			(*data)->c--;
		if ((*data)->str[y][x - 1] == 'E' && (*data)->c == 0)
		{
			(*data)->counter++;
			ft_printf("Move : %d\n", (*data)->counter);
			write(1, "YOU WIN !!", 11);
			delete_window(data);
		}
		(*data)->str[y][x] = '0';
		(*data)->str[y][x - 1] = 'P';
		counter_print_move(*data);
	}
}
