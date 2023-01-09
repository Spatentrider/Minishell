/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:20:28 by mvolpi            #+#    #+#             */
/*   Updated: 2023/01/09 14:29:35 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_proc.h"

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

	c = -1;
	env_list->env.current = (char **)malloc(sizeof(char *) * 40000000);
	while (envp[++c])
	{
		env_list->env.current[c] = ft_strdup(envp[c]);
	}
}
