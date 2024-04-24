/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meabdelk <meabdelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:04:34 by meabdelk          #+#    #+#             */
/*   Updated: 2024/04/06 01:57:16 by meabdelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	allocate_memory(t_map **data)
{
	(*data)->str = malloc(sizeof(char *) * ((*data)->countlines + 1));
	if (!(*data)->str)
		return ;
}

int	count_lines(int *fd, char *name)
{
	char	*line;
	int		counter;

	counter = 0;
	line = get_next_line(*fd);
	while (line)
	{
		counter++;
		free(line);
		line = get_next_line(*fd);
	}
	close(*fd);
	*fd = open(name, O_RDONLY);
	return (counter);
}

void	read_lines(int fd, t_map **data)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line == NULL)
		{
			write(1, "Error\nreading map file\n", 24);
			close(fd);
			return ;
		}
		(*data)->str[i] = line;
		line = get_next_line(fd);
		i++;
	}
	free(line);
}

void	read_map(char *av, t_map **data)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error opening file\n", 19);
		exit(0);
	}
	(*data)->countlines = count_lines(&fd, av);
	if ((*data)->countlines == 0)
	{
		write(2, "Error\nMap is empty !\n", 22);
		close(fd);
		exit(0);
	}
	allocate_memory(data);
	read_lines(fd, data);
	(*data)->str[(*data)->countlines] = NULL;
	close(fd);
}
