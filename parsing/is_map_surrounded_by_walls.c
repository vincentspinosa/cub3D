/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_surrounded_by_walls.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:43:50 by vispinos          #+#    #+#             */
/*   Updated: 2024/12/11 10:23:59 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int	is_top_or_bottom_ok(char **map, int row)
{
	int	col;

	if (!map || !map[row] || !map[row][0])
		return (1);
	col = 0;
	while (map[row][col] == ' ')
		col++;
	while (map[row][col])
	{
		if (map[row][col] != '1')
			return (1);
		col++;
	}
	return (0);
}

int	is_map_surrounded_by_walls(t_map_state *map_state, char **map)
{
	int	row;

	if (is_top_or_bottom_ok(map, 0))
		return (1);
	row = 1;
	while (row < (map_state->height - 1))
	{
		if (map[row][0] != '1'
			|| map[row][(int)(ft_strlen(map[row]) - 1)] != '1')
			return (1);
		row++;
	}
	return (is_top_or_bottom_ok(map, row));
}
