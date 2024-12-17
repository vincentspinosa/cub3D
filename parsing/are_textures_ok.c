/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_textures_ok.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:44:15 by vispinos          #+#    #+#             */
/*   Updated: 2024/12/11 12:22:10 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int	is_rgb_valid(int *rgb_array)
{
	if (rgb_array[0] < 0 || rgb_array[0] > 255 || rgb_array[1] < 0
		|| rgb_array[1] > 255 || rgb_array[2] < 0 || rgb_array[2] > 255)
		return (error_msg("RGB value has to be between 0 and 255."));
	return (0);
}

static unsigned long	rgb_to_hex(int *r)
{
	return (((r[0] & 0xff) << 16) + ((r[1] & 0xff) << 8) + (r[2] & 0xff));
}

int	are_textures_ok(t_txt_state *textures)
{
	if (!textures->north || !textures->south
		|| !textures->west || !textures->east)
		return (error_msg("Missing texture."));
	if (!textures->floor || !textures->ceiling)
		return (error_msg("Missing color."));
	if (is_file_ok(textures->north, 1) != 0
		|| is_file_ok(textures->south, 1) != 0
		|| is_file_ok(textures->west, 1) != 0
		|| is_file_ok(textures->east, 1) != 0
		|| is_rgb_valid(textures->floor) != 0
		|| is_rgb_valid(textures->ceiling) != 0)
		return (1);
	textures->f_hx = rgb_to_hex(textures->floor);
	textures->c_hx = rgb_to_hex(textures->ceiling);
	return (0);
}
