/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_first_player_direction.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:12:42 by vispinos          #+#    #+#             */
/*   Updated: 2024/12/11 10:50:02 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int	set_if_north_or_south(t_player *player)
{
	if (player->first_direction == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -0.85;
		player->plane_y = 0;
		return (1);
	}
	else if (player->first_direction == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = 0.85;
		player->plane_y = 0;
		return (1);
	}
	return (0);
}

static void	set_if_east_or_west(t_player *player)
{
	if (player->first_direction == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.85;
	}
	else if (player->first_direction == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.85;
	}
}

void	set_first_player_direction(t_state *s)
{
	if (set_if_north_or_south(&(s->player)) == 0)
		set_if_east_or_west(&(s->player));
}
