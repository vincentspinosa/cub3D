/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:14:14 by vispinos          #+#    #+#             */
/*   Updated: 2024/12/11 12:11:48 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	init_map_state(t_map_state *map_state)
{
	map_state->fd = 0;
	map_state->nb_lines = 0;
	map_state->path = NULL;
	map_state->file = NULL;
	map_state->height = 0;
	map_state->width = 0;
	map_state->eom = 0;
}

static void	init_player(t_player *player)
{
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	player->left_or_right_flag = 0;
	player->forward_or_backward_flag = 0;
	player->rotation_flag = 0;
	player->first_direction = '\0';
}

void	init_state(t_state *s)
{
	s->mlx = NULL;
	s->window = NULL;
	s->window_height = DISPLAY_HEIGHT;
	s->window_width = DISPLAY_WIDTH;
	init_player(&(s->player));
	s->textures = NULL;
	init_txt_state(&(s->txt_state));
	s->map = NULL;
	init_map_state(&(s->map_state));
}
