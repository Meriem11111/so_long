/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meabdelk <meabdelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 01:24:15 by meabdelk          #+#    #+#             */
/*   Updated: 2024/04/05 03:32:38 by meabdelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_memory(t_map **data)
{
	int	i;

	i = 0;
	while (i < (*data)->countlines)
	{
		free((*data)->str[i]);
		i++;
	}
	free((*data)->str);
}
