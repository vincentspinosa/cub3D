/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_scene_descr_content.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:34:34 by vispinos          #+#    #+#             */
/*   Updated: 2024/12/13 13:39:20 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static char	*fetch_texture_path(char *line, int c)
{
	char	*path;
	int		total_len;
	int		i;

	while (line[c] && line[c] == ' ')
		c++;
	total_len = c;
	while (line[total_len] && (line[total_len] != ' ' && line[c] != '\n'))
		total_len++;
	path = g_malloc(sizeof(char) * (total_len - c + 1));
	if (!path)
	{
		error_msg("Malloc error.");
		return (NULL);
	}
	i = 0;
	while (line[c] && (line[c] != ' ' && line[c] != '\n'))
		path[i++] = line[c++];
	path[i] = '\0';
	while (line[c] && line[c] == ' ')
		c++;
	if (line[c] && line[c] != '\n')
		path = NULL;
	return (path);
}

static int	fetch_textures_paths(t_txt_state *textures, char *line, int c)
{
	if (line[c + 1] && line[c + 2] && ft_isprint_nospace(line[c + 2]))
		return (1);
	if (!ft_strncmp(&(line[c]), "NO", 2) && !(textures->north))
		textures->north = fetch_texture_path(line, c + 2);
	else if (!ft_strncmp(&(line[c]), "SO", 2) && !(textures->south))
		textures->south = fetch_texture_path(line, c + 2);
	else if (!ft_strncmp(&(line[c]), "EA", 2) && !(textures->east))
		textures->east = fetch_texture_path(line, c + 2);
	else if (!ft_strncmp(&(line[c]), "WE", 2) && !(textures->west))
		textures->west = fetch_texture_path(line, c + 2);
	else
		return (1);
	return (0);
}

static int	fetch_content(t_state *s, char **file, int line, int c)
{
	if (ft_isprint_nospace(file[line][c]) && !ft_isdigit(file[line][c]))
	{
		if (file[line][c + 1] && ft_isprint_nospace(file[line][c + 1])
			&& !ft_isdigit(file[line][c]))
		{
			if (fetch_textures_paths(&(s->txt_state), file[line], c) == 1)
				return (error_msg("Invalid texture."));
			return (2);
		}
		else
		{
			if (set_colors(&(s->txt_state), file[line], c) == 1)
				return (1);
			return (2);
		}
	}
	else if (ft_isdigit(file[line][c]))
	{
		if (make_map(s, file, line) == 1)
			return (error_msg("Error in map."));
		return (0);
	}
	return (3);
}

int	fetch_scene_descr_content(t_state *s, char **file)
{
	int	line;
	int	c;
	int	to_return;

	line = 0;
	while (file[line])
	{
		c = 0;
		while (file[line][c])
		{
			to_return = fetch_content(s, file, line, c);
			if (to_return == 2)
				break ;
			else if (to_return == 1 || to_return == 0)
				return (to_return);
			else
				c++;
		}
		line++;
	}
	return (0);
}
