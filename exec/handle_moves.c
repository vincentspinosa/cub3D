/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:19:41 by vispinos          #+#    #+#             */
/*   Updated: 2024/12/11 11:17:33 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	move_player_forward(t_state *s)
{
	float	new_pos_x;
	float	new_pos_y;

	new_pos_x = s->player.pos_x + (s->player.dir_x * PLAYER_SPEED);
	new_pos_y = s->player.pos_y + (s->player.dir_y * PLAYER_SPEED);
	make_move(s, new_pos_x, new_pos_y);
}

static void	move_player_backward(t_state *s)
{
	float	new_pos_x;
	float	new_pos_y;

	new_pos_x = s->player.pos_x - (s->player.dir_x * PLAYER_SPEED);
	new_pos_y = s->player.pos_y - (s->player.dir_y * PLAYER_SPEED);
	make_move(s, new_pos_x, new_pos_y);
}

static void	move_player_left(t_state *s)
{
	float	new_pos_x;
	float	new_pos_y;

	new_pos_x = s->player.pos_x + (s->player.dir_y * PLAYER_SPEED);
	new_pos_y = s->player.pos_y - (s->player.dir_x * PLAYER_SPEED);
	make_move(s, new_pos_x, new_pos_y);
}

static void	move_player_right(t_state *s)
{
	float	new_pos_x;
	float	new_pos_y;

	new_pos_x = s->player.pos_x - (s->player.dir_y * PLAYER_SPEED);
	new_pos_y = s->player.pos_y + (s->player.dir_x * PLAYER_SPEED);
	make_move(s, new_pos_x, new_pos_y);
}

void	handle_moves(t_state *s)
{
	if (s->player.forward_or_backward_flag == 1)
		move_player_forward(s);
	else if (s->player.forward_or_backward_flag == -1)
		move_player_backward(s);
	else if (s->player.left_or_right_flag == -1)
		move_player_left(s);
	else if (s->player.left_or_right_flag == 1)
		move_player_right(s);
	if (s->player.rotation_flag != 0)
		rotate_player(s, s->player.rotation_flag);
}
