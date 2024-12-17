/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:32:20 by vispinos          #+#    #+#             */
/*   Updated: 2024/12/11 11:03:54 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	rotate_player(t_state *s, int direction)
{
	t_player			*p;
	t_rotation_helper	r;

	p = &(s->player);
	r.rotation_value = direction * ROTATION_SPEED;
	r.cos_r = cos(r.rotation_value);
	r.sin_r = sin(r.rotation_value);
	r.save_dir_x = p->dir_x;
	r.save_plane_x = p->plane_x;
	p->dir_x = (p->dir_x * r.cos_r) - (p->dir_y * r.sin_r);
	p->dir_y = (r.save_dir_x * r.sin_r) + (p->dir_y * r.cos_r);
	p->plane_x = (p->plane_x * r.cos_r) - (p->plane_y * r.sin_r);
	p->plane_y = (r.save_plane_x * r.sin_r) + (p->plane_y * r.cos_r);
}
