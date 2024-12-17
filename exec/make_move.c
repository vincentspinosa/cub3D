/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:31:32 by vispinos          #+#    #+#             */
/*   Updated: 2024/12/05 16:43:01 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int	is_pos_valid(t_state *s, float col_pos, float rank_pos)
{
	if (col_pos <= 0.2 || col_pos >= s->map_state.width - 1.2
		|| rank_pos <= 0.2 || rank_pos >= s->map_state.height - 0.2
		|| s->map[(int)rank_pos][(int)col_pos] == '1'
		|| s->map[(int)(rank_pos + 0.2)][(int)col_pos] == '1'
		|| s->map[(int)(rank_pos - 0.2)][(int)col_pos] == '1'
		|| s->map[(int)rank_pos][(int)(col_pos + 0.2)] == '1'
		|| s->map[(int)rank_pos][(int)(col_pos - 0.2)] == '1')
		return (1);
	return (0);
}

void	make_move(t_state *s, float new_col_pos, float new_rank_pos)
{
	if (is_pos_valid(s, new_col_pos, s->player.pos_y) == 0)
		s->player.pos_x = new_col_pos;
	if (is_pos_valid(s, s->player.pos_x, new_rank_pos) == 0)
		s->player.pos_y = new_rank_pos;
}
