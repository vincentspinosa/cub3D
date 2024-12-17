/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:37:47 by vispinos          #+#    #+#             */
/*   Updated: 2024/12/11 10:33:41 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	error_msg(char *error_msg)
{
	ft_putendl_fd("cub3D: Error", 2);
	ft_putendl_fd(error_msg, 2);
	return (1);
}

void	exit_game(t_state *s, int ext)
{
	if (s)
	{
		if (s->mlx)
		{
			if (s->window)
				mlx_destroy_window(s->mlx, s->window);
			mlx_destroy_display(s->mlx);
			free(s->mlx);
		}
		if (s->map_state.fd > 0)
			close(s->map_state.fd);
	}
	garbage_destroy();
	exit(ext);
}

int	exit_game_success(t_state *s)
{
	exit_game(s, 0);
	return (0);
}
