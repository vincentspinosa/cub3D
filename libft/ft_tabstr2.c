/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:01:22 by vispinos          #+#    #+#             */
/*   Updated: 2024/12/17 17:02:02 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabstr_addback(char *str, char **tab_str)
{
	size_t	tabstr_len;
	char	**temp_tab;
	char	*str_dup;

	str_dup = ft_strdup(str);
	temp_tab = tab_str;
	if (!str_dup)
		return (ft_free_all(temp_tab), NULL);
	tabstr_len = ft_tabstr_len(tab_str);
	tab_str = (char **)g_malloc((tabstr_len + 2) * sizeof(char *));
	if (!tab_str)
		return (g_free(str_dup), ft_free_all(temp_tab), NULL);
	ft_temptab_totab(tab_str, temp_tab);
	tab_str[tabstr_len] = &(*(str_dup));
	tab_str[tabstr_len + 1] = NULL;
	g_free(temp_tab);
	return (tab_str);
}
