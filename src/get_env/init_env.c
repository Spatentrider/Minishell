/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:20:28 by mvolpi            #+#    #+#             */
/*   Updated: 2023/01/20 10:32:44 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_env.h"

/**
 * @brief Takes the working enviroment and save it in a list
 * 
 * @param envp array of the enviroment that already exists in
 * the computer as argv that we copy to our list with ft_strdup
 * @param env_list created list that we use to save the enviroment
 */
void	get_env(char **envp, t_shell *env_list)
{
	int	c;
	int	i;

	c = -1;
	i = -1;
	while (envp[++i])
		;
	env_list->env.current = (char **)malloc(sizeof(char *) * (i + 1));
	while (envp[++c])
	{
		env_list->env.current[c] = ft_strdup(envp[c]);
	}
}
