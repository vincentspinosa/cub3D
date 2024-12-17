/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:18:13 by vispinos          #+#    #+#             */
/*   Updated: 2024/12/11 22:47:28 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_isprint_nospace(int c)
{
	return (c > 32 && c < 127);
}

size_t	max_row_len(t_map_state *map_state, int start)
{
	size_t	len;

	len = 0;
	while (map_state->file[start])
	{
		if (ft_strlen(map_state->file[start]) > len)
			len = ft_strlen(map_state->file[start]);
		start++;
	}
	return (len);
}
