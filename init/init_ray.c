/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:20:03 by vispinos          #+#    #+#             */
/*   Updated: 2024/12/11 11:38:04 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_ray(t_ray *ray)
{
	ray->camera_orientation = 0.0;
	ray->dir_x = 0.0;
	ray->dir_y = 0.0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->side_dist_x = 0.0;
	ray->side_dist_y = 0.0;
	ray->delta_dist_x = 0.0;
	ray->delta_dist_y = 0.0;
	ray->wall_dist = 0;
	ray->wall_x_offset = 0.0;
	ray->vertical_or_horiz_flag = HORIZONTAL_FLAG;
	ray->wall_height_on_screen = 0;
	ray->wall_top = 0;
	ray->wall_bottom = 0;
}
