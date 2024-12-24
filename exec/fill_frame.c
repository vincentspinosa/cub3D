/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 23:10:45 by vispinos          #+#    #+#             */
/*   Updated: 2024/12/24 02:52:31 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	set_ceiling(t_state *s, t_ray *ray, int col)
{
	int	rank;

	rank = 0;
	while (rank < ray->wall_top)
	{
		s->image.addr[(rank * (s->image.sl >> 2)) + col] = s->txt_state.c_hx;
		rank++;
	}
}

static void	set_floor(t_state *s, t_ray *ray, int col)
{
	int	rank;

	rank = ray->wall_bottom;
	while (rank < DISPLAY_HEIGHT)
	{
		s->image.addr[(rank * (s->image.sl >> 2)) + col] = s->txt_state.f_hx;
		rank++;
	}
}

static void	fetch_texture_index(t_state *s, t_ray *ray)
{
	if (ray->vertical_or_horiz_flag == HORIZONTAL_FLAG && ray->dir_x < 0)
		s->txt_state.curr_txt_index = WEST_TXT;
	else if (ray->vertical_or_horiz_flag == HORIZONTAL_FLAG)
		s->txt_state.curr_txt_index = EAST_TXT;
	else if (ray->dir_y > 0)
		s->txt_state.curr_txt_index = SOUTH_TXT;
	else
		s->txt_state.curr_txt_index = NORTH_TXT;
}

void	fill_frame(t_state *s, t_txt_state *txt_state, t_ray *ray, int col)
{
	int	y;
	int	rank_mask;
	int	color;

	set_ceiling(s, ray, col);
	fetch_texture_index(s, ray);
	txt_state->col = (int)(ray->wall_x_offset * TEXTURE_SIZE);
	if ((ray->vertical_or_horiz_flag == HORIZONTAL_FLAG && ray->dir_x < 0)
		|| (ray->vertical_or_horiz_flag == VERTICAL_FLAG && ray->dir_y > 0))
		txt_state->col = TEXTURE_SIZE - txt_state->col - 1;
	txt_state->step = (float)TEXTURE_SIZE / ray->wall_height_on_screen;
	txt_state->rank_address = (ray->wall_top - (DISPLAY_HEIGHT >> 1) \
	+ (ray->wall_height_on_screen >> 1)) * txt_state->step;
	rank_mask = TEXTURE_SIZE - 1;
	y = ray->wall_top;
	while (y < ray->wall_bottom)
	{
		txt_state->rank = (int)txt_state->rank_address & rank_mask;
		color = s->textures[txt_state->curr_txt_index][(TEXTURE_SIZE \
		* txt_state->rank) + txt_state->col];
		s->image.addr[(y * (s->image.sl >> 2)) + col] = color;
		txt_state->rank_address += txt_state->step;
		y++;
	}
	set_floor(s, ray, col);
}
