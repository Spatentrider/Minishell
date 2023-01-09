/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:20:28 by mvolpi            #+#    #+#             */
/*   Updated: 2023/01/04 14:09:01 by mvolpi           ###   ########.fr       */
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
void	get_env(char **envp, t_env *env_list)
{
	int	c;

	c = 0;
	lstnew(envp[0]);
	env_list->current = ft_strdup(envp[c]);
	while (envp[++c])
	{
		lstadd_back(&env_list, lstnew(envp[c]));
		env_list->current = ft_strdup(envp[c]);
	}
}
