/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meabdelk <meabdelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 03:38:41 by meabdelk          #+#    #+#             */
/*   Updated: 2024/05/12 10:39:05 by meabdelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../get_next_line/get_next_line.h"
# include "../printf/ft_printf.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_map
{
	int		counter;
	char	pos_e[2];
	char	**str;
	int		len;
	int		countlines;
	int		e;
	int		c;
	int		p;
	int		n;
	int		x;
	int		y;
	int		x_p;
	int		y_p;
	int		x_n;
	int		y_n;
	int		state;
	void	*mlx;
	void	*win;
	int		win_height;
	int		win_width;
	void	*img[11];
}			t_map;

int			ft_strchar(char *s, int c);
void		check_len(t_map *data);
void		check_first_last(t_map *data, int j);
void		check_left_right(t_map *data);
void		check_characters(t_map *data);
void		check_error(t_map *data);
void		ft_error(t_map *data);
void		to_right(t_map **data);
int			print_window(t_map *data);
void		pos_player(t_map *data);
void		to_left(t_map **data);
void		to_down(t_map **data);
void		to_up(t_map **data);
void		delete_window(t_map **map);
void		check_size(t_map *data);
void		print_img(t_map **data);
void		read_map(char *av, t_map **data);
int			check_valid_map(t_map *data);
void		flood_fill(t_map **data, int x, int y);
void		check_line(char *argv);
void		exit_err(t_map *data);
void		invalid_img(t_map **data);
void		print_map_line(t_map *data, int a, int x);
void		print_mvmnt(t_map *data_img);
void		ft_initialize(t_map *data);
void		ft_err(void);
void		free_memory(t_map **data);
void		err_file(void);
void		ennemy_error(t_map *data);
char		*ft_strjoin2(char *s1, char *s2);
int			ft_strlen(char *str);
void		free2(t_map *data);
void		mlx_win(t_map *data);

#endif