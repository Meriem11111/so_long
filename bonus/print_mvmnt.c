/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mvmnt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meabdelk <meabdelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:08:57 by meabdelk          #+#    #+#             */
/*   Updated: 2024/05/09 18:16:48 by meabdelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_length(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	str = (char *)malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		dgt;
	long	nbr;

	dgt = check_length(n);
	nbr = n;
	if (n < 0)
	{
		nbr *= -1;
		dgt++;
	}
	res = malloc(sizeof(char) * (dgt + 1));
	if (!res)
		return (NULL);
	res[dgt] = '\0';
	while (dgt > 0)
	{
		dgt--;
		res[dgt] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}

void	print_mvmnt(t_map *data_img)
{
	char	*str;
	char	*result;

	str = ft_itoa(data_img->counter);
	result = ft_strjoin2("MOVE : ", str);
	mlx_string_put(data_img->mlx, data_img->win, 15, 6, 0xFFFFFF, result);
	free(str);
	free(result);
}
