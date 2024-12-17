/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_ok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 03:39:51 by vispinos          #+#    #+#             */
/*   Updated: 2024/12/05 17:24:10 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int	is_cub_file(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (len < 5)
		return (1);
	if (path[len - 5] == '/')
		return (1);
	if (path[len - 4] != '.' || path[len - 3] != 'c'
		|| path[len - 2] != 'u' || path[len - 1] != 'b')
		return (1);
	return (0);
}

static int	is_xpm_file(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (len < 5)
		return (1);
	if (path[len - 5] == '/')
		return (1);
	if (path[len - 4] != '.' || path[len - 3] != 'x'
		|| path[len - 2] != 'p' || path[len - 1] != 'm')
		return (1);
	return (0);
}

int	is_file_ok(char *path, int is_cub)
{
	int	fd;

	if (is_cub == 0 && is_cub_file(path) != 0)
		return (error_msg("File does not end with '.cub'."));
	if (is_cub == 1 && is_xpm_file(path) != 0)
		return (error_msg("File does not end with '.xpm'."));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (error_msg("Could not open file."));
	close(fd);
	return (0);
}
