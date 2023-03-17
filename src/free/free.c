/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:12:05 by mich              #+#    #+#             */
/*   Updated: 2023/02/14 18:12:06 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src.h"

void	free_struct2(t_shell *shell, int i)
{
	if(shell->exp.sort_env)
	{
		i = -1;
		while (shell->exp.sort_env[++i])
		{
			free(shell->exp.sort_env[i]);
			shell->exp.sort_env[i] = NULL;
		}
		free(shell->exp.sort_env);
		shell->exp.sort_env = NULL;
	}
	if(shell->lst.executor)
	{
		i = -1;
		while (shell->lst.executor[++i])
		{
			free(shell->lst.executor[i]);
			shell->lst.executor[i] = NULL;
		}
		free(shell->lst.executor[i]);
		shell->lst.executor = NULL;
	}
	if(shell->lst.expansion)
	{
		i = -1;
		while (shell->lst.expansion[++i])
		{
			free(shell->lst.expansion[i]);
			shell->lst.expansion[i] = NULL;
		}
		free(shell->lst.expansion);
		shell->lst.expansion[i] = NULL;
	}
}

/**
 * @brief function that takes the structure of structures to be freed,
 * iterates cell by cell to be free and then does a general free of the
 * array
 * 
 * @param shell the structure of structures
 */

void	free_struct(t_shell *shell)
{
	int	i;

	if(shell->env.current)
	{
		i = -1;
		while (shell->env.current[++i])
		{
			free(shell->env.current[i]);
			shell->env.current[i] = NULL;
		}
		free(shell->env.current);
	}
	free(shell->lst.input);
	if(shell->lst.split)
	{
		i = -1;
		while (shell->lst.split[++i])
		{
			free(shell->lst.split[i]);
			shell->lst.split[i] = NULL;
		}
		free(shell->lst.split);
	}
	free_struct2(shell, i);
}
