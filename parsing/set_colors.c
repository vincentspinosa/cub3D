/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:13:44 by vispinos          #+#    #+#             */
/*   Updated: 2024/12/11 12:11:48 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int	at_least_one_digit(char *rgb_str)
{
	int		i;

	i = 0;
	while (rgb_str[i])
	{
		if (ft_isdigit(rgb_str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	*copy_into_rgb_array(char **rgb_to_convert, int *rgb_array)
{
	int		i;

	i = 0;
	while (rgb_to_convert[i])
	{
		rgb_array[i] = ft_atoi(rgb_to_convert[i]);
		if (at_least_one_digit(rgb_to_convert[i]) != 0)
		{
			error_msg("An RGB value has to contain a digit.");
			return (NULL);
		}
		i++;
	}
	return (rgb_array);
}

static int	*set_rgb_colors(char *line)
{
	char	**rgb_to_convert;
	int		*rgb_array;
	int		count;

	if (!line)
	{
		error_msg("Missing RGB code.");
		return (NULL);
	}
	rgb_to_convert = ft_split(line, ',');
	count = 0;
	while (rgb_to_convert && rgb_to_convert[count])
		count++;
	if (count != 3)
	{
		error_msg("An RGB code has to contain three values.");
		return (NULL);
	}
	rgb_array = g_malloc(sizeof(int) * 3);
	if (!rgb_array)
	{
		error_msg("Malloc error.");
		return (NULL);
	}
	return (copy_into_rgb_array(rgb_to_convert, rgb_array));
}

int	set_colors(t_txt_state *textures, char *line, int c)
{
	if (line[c + 1] && ft_isprint_nospace(line[c + 1]))
		return (error_msg("Error in color syntax"));
	if (line[c] == 'F' && !textures->floor)
	{
		textures->floor = set_rgb_colors(&(line[c + 1]));
		if (!(textures->floor))
			return (1);
	}
	else if (line[c] == 'C' && !textures->ceiling)
	{
		textures->ceiling = set_rgb_colors(&(line[c + 1]));
		if (!(textures->ceiling))
			return (1);
	}
	else
		return (error_msg("Error in color syntax"));
	return (0);
}
