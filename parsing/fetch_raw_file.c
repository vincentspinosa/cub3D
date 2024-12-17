/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_raw_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:18:53 by vispinos          #+#    #+#             */
/*   Updated: 2024/12/05 17:36:49 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int	fetch_number_of_lines(char *file)
{
	int		nb;
	int		fd;
	char	*line;

	nb = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		error_msg("Could not open file.");
		return (0);
	}
	line = get_next_line(fd);
	while (line)
	{
		nb++;
		line = get_next_line(fd);
	}
	close(fd);
	return (nb);
}

static void	fetch_file_content(t_state *s)
{
	int		row;
	char	*line;

	row = 0;
	line = get_next_line(s->map_state.fd);
	while (line)
	{
		s->map_state.file[row] = line;
		row++;
		line = get_next_line(s->map_state.fd);
	}
	s->map_state.file[row] = NULL;
}

int	fetch_raw_file(char *path, t_state *s)
{
	s->map_state.nb_lines = fetch_number_of_lines(path);
	s->map_state.path = path;
	s->map_state.file = ft_calloc((s->map_state.nb_lines + 1), sizeof(char *));
	if (!(s->map_state.file))
		return (error_msg("Calloc error."));
	s->map_state.fd = open(path, O_RDONLY);
	if (s->map_state.fd == -1)
		return (error_msg("Could not open file."));
	fetch_file_content(s);
	close(s->map_state.fd);
	return (0);
}
