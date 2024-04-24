/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meabdelk <meabdelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 03:39:08 by meabdelk          #+#    #+#             */
/*   Updated: 2024/04/06 01:46:23 by meabdelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "printf/ft_printf.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_map
{
	int		counter;
	char	**str;
	int		len;
	int		countlines;
	int		e;
	int		c;
	int		p;
	int		x;
	int		y;
	int		x_p;
	int		y_p;
	void	*mlx;
	void	*win;
	int		win_height;
	int		win_width;
	void	*img[7];
}			t_map;

int			ft_strchar(char *s, int c);
void		check_len(t_map *data);
void		check_first_last(t_map *data, int j);
void		check_left_right(t_map *data);
void		check_characters(t_map *data);
void		check_error(t_map *data);
void		ft_error(t_map *data);
void		check_file(char *file);
void		err_file(void);
void		to_right(t_map **data);
int			print_window(t_map *data);
void		pos_player(t_map *data);
void		to_left(t_map **data);
void		to_down(t_map **data);
void		to_up(t_map **data);
void		delete_window(t_map **map);
void		close_win(t_map **map);
void		print_img(t_map **data);
void		read_map(char *av, t_map **data);
int			check_valid_map(t_map *data);
void		flood_fill(t_map **data, int x, int y);
void		free_memory(t_map **data);
void		check_line(char *argv);
void		invalid_img(void);
void		print_map_line(t_map *data, int a, int x);
void		ft_initialize(t_map *data);
void		counter_print_move(t_map *map);
void		ft_err(void);
void		print_image_for_e(t_map *data, int y, int x);

#endif