/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:03:18 by vispinos          #+#    #+#             */
/*   Updated: 2024/12/01 15:48:33 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_state	s;

	if (ac < 2)
		return (error_msg("Not enough arguments."));
	init_state(&s);
	parsing(&s, av);
	exec(&s);
	return (0);
}
