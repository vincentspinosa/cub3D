/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:20:58 by vispinos          #+#    #+#             */
/*   Updated: 2024/12/11 11:38:02 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int	render_frame(t_state *s)
{
	handle_moves(s);
	init_ray(&(s->ray));
	init_img(s, &(s->image), s->window_width, s->window_height);
	raycasting(&(s->player), s);
	mlx_put_image_to_window(s->mlx, s->window, s->image.img, 0, 0);
	mlx_destroy_image(s->mlx, s->image.img);
	return (0);
}

void	exec(t_state *s)
{
	set_first_player_direction(s);
	init_mlx(s);
	init_textures(s);
	mlx_hook(s->window, DESTROY, 0, exit_game_success, s);
	mlx_hook(s->window, KeyPress, KeyPressMask, handle_key_press, s);
	mlx_hook(s->window, KeyRelease, KeyReleaseMask, handle_key_release, s);
	mlx_loop_hook(s->mlx, render_frame, s);
	mlx_loop(s->mlx);
}
