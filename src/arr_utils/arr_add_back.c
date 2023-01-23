/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:26:35 by mvolpi            #+#    #+#             */
/*   Updated: 2023/01/23 10:43:39 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr_utils.h"

void	arr_add_back(t_shell *env_list, char *copy, int n)
{
	int	i;
	int	l;

	i = -1;
	while (env_list->env.current[++i])
		;
	l = n + 1;
	env_list->env.current = (char **)realloc(env_list->env.current, l);
	env_list->env.current[n] = ft_strdup(copy);
	n++;
	env_list->env.current[n] = NULL;
}
