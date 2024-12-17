/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 23:14:52 by vispinos          #+#    #+#             */
/*   Updated: 2024/12/05 16:34:11 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	parsing(t_state *s, char **av)
{
	if (is_file_ok(av[1], 0) != 0
		|| fetch_raw_file(av[1], s) != 0
		|| fetch_scene_descr_content(s, s->map_state.file) != 0
		|| is_map_ok(s, s->map) != 0
		|| are_textures_ok(&(s->txt_state)) != 0)
		exit_game(s, 1);
}
