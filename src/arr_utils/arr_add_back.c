/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:26:35 by mvolpi            #+#    #+#             */
/*   Updated: 2023/04/04 11:16:09 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr_utils.h"

void	arr_add_back(t_shell *env_list, char *copy)
{
	int	i;
	int	l;

	i = -1;
	while (env_list->env.current[++i])
		;
	l = ft_sarsize(env_list->env.current) + 1;
	env_list->env.current = (char **)realloc(env_list->env.current, l);
	env_list->env.current[l - 1] = ft_strdup(copy);
	env_list->env.current[l] = NULL;
}
