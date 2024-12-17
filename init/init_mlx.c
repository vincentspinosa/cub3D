/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:51:14 by vispinos          #+#    #+#             */
/*   Updated: 2024/11/20 23:53:21 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_mlx(t_state *s)
{
	s->mlx = mlx_init();
	if (!(s->mlx))
		exit_game(s, error_msg("Error creating the MLX instance."));
	s->window = mlx_new_window(s->mlx, DISPLAY_WIDTH, DISPLAY_HEIGHT, "cub3D");
	if (!(s->window))
		exit_game(s, error_msg("Error creating the MLX window."));
}
