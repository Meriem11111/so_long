/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meabdelk <meabdelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:34:04 by meabdelk          #+#    #+#             */
/*   Updated: 2024/05/13 23:08:01 by meabdelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_characters(t_map *data)
{
	ft_initialize(data);
	while (data->x < data->countlines)
	{
		data->y = data->len - 1;
		while (data->y >= 0)
		{
			if (data->str[data->x][data->y] == 'E')
				data->e++;
			else if (data->str[data->x][data->y] == 'P')
				data->p++;
			else if (data->str[data->x][data->y] == 'C')
				data->c++;
			else if (data->str[data->x][data->y] != '1'
				&& data->str[data->x][data->y] != '0')
			{
				write(2, "Error\n unknown character\n", 25);
				free_memory(&data);
				free(data);
				exit(0);
			}
			data->y--;
		}
		data->x++;
	}
	ft_error(data);
}

void	check_len(t_map *data)
{
	int	i;

	i = 0;
	data->len = ft_strlen(data->str[i]) - 1;
	while (data->str[i])
	{
		if (ft_strchar(data->str[i], '\n') == 1)
		{
			if (data->len != ft_strlen(data->str[i]) - 1)
			{
				write(2, "Error\nLength\n", 14);
				free_memory(&data);
				free(data);
				exit(0);
			}
		}
		else if (data->len != ft_strlen(data->str[i]))
		{
			write(2, "Error\nLength\n", 14);
			free_memory(&data);
			free(data);
			exit(0);
		}
		i++;
	}
}

void	check_first_last(t_map *data, int j)
{
	int	i;

	i = 0;
	while (data->str[j][i] && i < data->len)
	{
		if (data->str[j][i] != '1')
		{
			write(2, "Error\ninvalid row\n", 19);
			free_memory(&data);
			free(data);
			exit(0);
		}
		i++;
	}
}

void	check_left_right(t_map *data)
{
	int	i;

	i = 0;
	while (data->str[i])
	{
		if (data->str[i][0] != '1' || data->str[i][data->len - 1] != '1')
		{
			write(2, "Error\nmap not surrounded by walls\n", 35);
			free_memory(&data);
			free(data);
			exit(0);
		}
		i++;
	}
}

void	check_line(char *argv)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error opening file\n", 19);
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n')
		{
			write(2, "Error\nEmpty line\n", 18);
			free(line);
			close(fd);
			exit(1);
		}
		free(line);
		line = get_next_line(fd);
	}
}
