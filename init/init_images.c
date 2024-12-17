/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:39:55 by vispinos          #+#    #+#             */
/*   Updated: 2024/12/11 12:14:11 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_raw_img(t_img *image)
{
	image->img = NULL;
	image->addr = NULL;
	image->bpp = 0;
	image->sl = 0;
	image->nd = 0;
}

void	init_img(t_state *s, t_img *m, int width, int height)
{
	init_raw_img(m);
	m->img = mlx_new_image(s->mlx, width, height);
	if (!(m->img))
		exit_game(s, error_msg("Error creating a new image."));
	m->addr = (int *)mlx_get_data_addr(m->img, &(m->bpp), &(m->sl), &(m->nd));
	return ;
}
