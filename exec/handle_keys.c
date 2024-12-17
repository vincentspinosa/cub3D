/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:54:07 by vispinos          #+#    #+#             */
/*   Updated: 2024/12/11 11:16:30 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	handle_key_press(int key, t_state *s)
{
	if (key == ESC)
		exit_game_success(s);
	else if (key == KEY_A && s->player.left_or_right_flag == 0)
		s->player.left_or_right_flag = -1;
	else if (key == KEY_W && s->player.left_or_right_flag == 0)
		s->player.forward_or_backward_flag = 1;
	else if (key == KEY_S && s->player.forward_or_backward_flag == 0)
		s->player.forward_or_backward_flag = -1;
	else if (key == KEY_D && s->player.forward_or_backward_flag == 0)
		s->player.left_or_right_flag = 1;
	else if (key == KEY_LEFT && s->player.rotation_flag == 0)
		s->player.rotation_flag = -1;
	else if (key == KEY_RIGHT && s->player.rotation_flag == 0)
		s->player.rotation_flag = 1;
	return (0);
}

int	handle_key_release(int key, t_state *s)
{
	if (key == ESC)
		exit_game_success(s);
	else if (key == KEY_A && s->player.left_or_right_flag == -1)
		s->player.left_or_right_flag = 0;
	else if (key == KEY_W && s->player.forward_or_backward_flag == 1)
		s->player.forward_or_backward_flag = 0;
	else if (key == KEY_S && s->player.forward_or_backward_flag == -1)
		s->player.forward_or_backward_flag = 0;
	else if (key == KEY_D && s->player.left_or_right_flag == 1)
		s->player.left_or_right_flag = 0;
	else if (key == KEY_LEFT && s->player.rotation_flag == -1)
		s->player.rotation_flag = 0;
	else if (key == KEY_RIGHT && s->player.rotation_flag == 1)
		s->player.rotation_flag = 0;
	return (0);
}
