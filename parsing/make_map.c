/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:51:23 by vispinos          #+#    #+#             */
/*   Updated: 2024/12/11 12:22:51 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int	count_map_lines(t_state *s, char **map, int start)
{
	int	row;
	int	col;

	row = start;
	while (map[row])
	{
		col = 0;
		while (map[row][col] == ' ')
			col++;
		if (map[row][col] != '1')
			break ;
		row++;
	}
	s->map_state.eom = row;
	return (row - start);
}

static int	fill_map(t_map_state *map_state, char **map, int start)
{
	int		row;
	int		col;

	map_state->width = max_row_len(map_state, start);
	row = 0;
	while (row < map_state->height)
	{
		col = 0;
		map[row] = g_malloc(sizeof(char) * (map_state->width + 1));
		if (!(map[row]))
			return (error_msg("Malloc error."));
		while (map_state->file[start + row][col]
			&& map_state->file[start + row][col] != '\n')
		{
			map[row][col] = map_state->file[start + row][col];
			col++;
		}
		while (col < map_state->width)
			map[row][col++] = '\0';
		row++;
	}
	map[row] = NULL;
	return (0);
}

static int	fetch_map_info(t_state *s, char **file, int start)
{
	s->map_state.height = count_map_lines(s, file, start);
	s->map = g_malloc(sizeof(char *) * (s->map_state.height + 1));
	if (!(s->map))
		return (error_msg("Malloc error."));
	return (fill_map(&(s->map_state), s->map, start));
}

static int	change_spaces_into_walls(t_state *s)
{
	int	row;
	int	col;

	row = 0;
	while (s->map[row])
	{
		col = 0;
		while (s->map[row][col])
		{
			if (s->map[row][col] == ' ')
				s->map[row][col] = '1';
			col++;
		}
		row++;
	}
	return (0);
}

int	make_map(t_state *s, char **file, int start)
{
	if (fetch_map_info(s, file, start) != 0)
		return (1);
	return (change_spaces_into_walls(s));
}
