/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_ok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:00:17 by vispinos          #+#    #+#             */
/*   Updated: 2024/12/11 21:52:15 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int	are_map_elems_ok(t_state *s, char **map)
{
	int	row;
	int	col;

	s->player.first_direction = '0';
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			while (s->map[row][col] == ' ')
				col++;
			if (!(ft_strchr("NSEW10", map[row][col])))
				return (error_msg("Invalid char in map."));
			else if (ft_strchr("NSEW", map[row][col])
				&& s->player.first_direction != '0')
				return (error_msg("More than one player orientation."));
			else if (ft_strchr("NSEW", map[row][col])
				&& s->player.first_direction == '0')
				s->player.first_direction = map[row][col];
			col++;
		}
		row++;
	}
	return (0);
}

static int	check_and_set_player_pos(t_state *s, char **map)
{
	int	row;
	int	col;

	if (s->player.first_direction == '0')
		return (error_msg("Missing player."));
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (ft_strchr("NSEW", map[row][col]))
			{
				s->player.pos_x = (float)col + 0.5;
				s->player.pos_y = (float)row + 0.5;
				map[row][col] = '0';
			}
			col++;
		}
		row++;
	}
	return (0);
}

static int	is_map_at_the_end(t_map_state *map_state)
{
	int	row;

	row = map_state->eom;
	if (map_state->file[row])
		return (1);
	return (0);
}

int	is_map_ok(t_state *s, char **map)
{
	if (!(s->map))
		return (error_msg("No map provided."));
	if (is_map_surrounded_by_walls(&(s->map_state), map) != 0)
		return (error_msg("Map not surrounded by walls."));
	if (are_map_elems_ok(s, map) != 0)
		return (1);
	if (check_and_set_player_pos(s, map) != 0)
		return (1);
	if (is_map_at_the_end(&(s->map_state)) != 0)
		return (error_msg("Content after map."));
	return (0);
}
