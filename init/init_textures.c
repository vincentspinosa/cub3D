/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:54:59 by vispinos          #+#    #+#             */
/*   Updated: 2024/12/11 12:17:26 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_texture_img(t_state *s, t_img *m, char *path)
{
	int	sz;

	sz = TEXTURE_SIZE;
	init_raw_img(m);
	m->img = mlx_xpm_file_to_image(s->mlx, path, &sz, &sz);
	if (!(m->img))
		exit_game(s, error_msg("Error creating an image."));
	m->addr = (int *)mlx_get_data_addr(m->img, &(m->bpp), &(m->sl), &(m->nd));
	return ;
}

void	init_txt_state(t_txt_state *txt_state)
{
	txt_state->north = NULL;
	txt_state->south = NULL;
	txt_state->west = NULL;
	txt_state->east = NULL;
	txt_state->floor = NULL;
	txt_state->ceiling = NULL;
	txt_state->f_hx = 0;
	txt_state->c_hx = 0;
	txt_state->step = 0.0;
	txt_state->col = 0;
	txt_state->rank_address = 0.0;
	txt_state->rank = 0;
}

static int	*fetch_pixels_from_xpm_file(t_state *s, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		i;
	int		buffer_len;

	init_texture_img(s, &tmp, path);
	buffer_len = pow(TEXTURE_SIZE, 2);
	buffer = ft_calloc(1, (sizeof * buffer * buffer_len));
	if (!buffer)
		exit_game(s, error_msg("Calloc error."));
	i = 0;
	while (i < buffer_len)
	{
		buffer[i] = tmp.addr[i];
		i++;
	}
	mlx_destroy_image(s->mlx, tmp.img);
	return (buffer);
}

void	init_textures(t_state *s)
{
	s->textures = ft_calloc(5, sizeof * s->textures);
	if (!s->textures)
		exit_game(s, error_msg("Calloc error."));
	s->textures[NORTH_TXT] = fetch_pixels_from_xpm_file(s, s->txt_state.north);
	s->textures[SOUTH_TXT] = fetch_pixels_from_xpm_file(s, s->txt_state.south);
	s->textures[EAST_TXT] = fetch_pixels_from_xpm_file(s, s->txt_state.east);
	s->textures[WEST_TXT] = fetch_pixels_from_xpm_file(s, s->txt_state.west);
}
