/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 02:41:09 by vispinos          #+#    #+#             */
/*   Updated: 2024/12/24 02:54:20 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	set_raycasting(int col, t_ray *ray, t_player *player)
{
	init_ray(ray);
	ray->camera_orientation = (col * 2 / (float)DISPLAY_WIDTH) - 1;
	ray->dir_x = player->dir_x + (player->plane_x * ray->camera_orientation);
	ray->dir_y = player->dir_y + (player->plane_y * ray->camera_orientation);
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->delta_dist_x = fabs(1 / ray->dir_x);
	ray->delta_dist_y = fabs(1 / ray->dir_y);
}

static void	set_dda(t_ray *ray, t_player *p)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (p->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - p->pos_x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (p->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - p->pos_y) * ray->delta_dist_y;
	}
}

static void	digital_differential_analizer(t_state *s, t_ray *ray)
{
	while (1)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->vertical_or_horiz_flag = HORIZONTAL_FLAG;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->vertical_or_horiz_flag = VERTICAL_FLAG;
		}
		if (s->map[ray->map_y][ray->map_x] == '1')
			break ;
	}
}

static void	compute_wall_height(t_ray *ray, t_player *player)
{
	if (ray->vertical_or_horiz_flag == HORIZONTAL_FLAG)
		ray->wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->wall_dist = ray->side_dist_y - ray->delta_dist_y;
	ray->wall_height_on_screen = (int)(DISPLAY_HEIGHT / ray->wall_dist);
	ray->wall_top = ((ray->wall_height_on_screen * -1) >> 1) \
	+ (DISPLAY_HEIGHT >> 1);
	if (ray->wall_top < 0)
		ray->wall_top = 0;
	ray->wall_bottom = (ray->wall_height_on_screen >> 1) + \
	(DISPLAY_HEIGHT >> 1);
	if (ray->wall_bottom > DISPLAY_HEIGHT)
		ray->wall_bottom = DISPLAY_HEIGHT;
	if (ray->vertical_or_horiz_flag == HORIZONTAL_FLAG)
		ray->wall_x_offset = player->pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x_offset = player->pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_x_offset -= floor(ray->wall_x_offset);
}

void	raycasting(t_player *player, t_state *s)
{
	int		col;

	col = 0;
	while (col < DISPLAY_WIDTH)
	{
		set_raycasting(col, &(s->ray), player);
		set_dda(&(s->ray), player);
		digital_differential_analizer(s, &(s->ray));
		compute_wall_height(&(s->ray), player);
		fill_frame(s, &(s->txt_state), &(s->ray), col);
		col++;
	}
}
