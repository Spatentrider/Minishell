/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzodimascia <lorenzodimascia@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:27:19 by mich              #+#    #+#             */
/*   Updated: 2023/03/09 15:31:24 by lorenzodima      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unset.h"

void	ft_unset(t_shell *shell, char **current)
{
	shell->unset.k = 0;
	while(shell->lst.executor[++shell->unset.k])
	{
		shell->unset.i = -1;
		while (current[++shell->unset.i])
		{
			shell->unset.position = ft_strchrp(current[shell->unset.i], '=');
			if (ft_strncmp(current[shell->unset.i], \
				shell->lst.executor[shell->unset.k], shell->unset.position) == 0)
			{
				shell->unset.j = shell->unset.i - 1;
				while (current[++shell->unset.j])
				{
					if (current[shell->unset.j + 1] != NULL)
					{
						free(current[shell->unset.j]);
						current[shell->unset.j] = ft_strdup \
							(current[shell->unset.j + 1]);
					}
					else
					{
						free(current[shell->unset.j]);
						current[shell->unset.j] = NULL;
					}
				}
				break ;
			}
		}
	}
}

void	ft_unset2(t_shell *shell, char **current)
{
	shell->unset.i = -1;
	while (current[++shell->unset.i])
	{
		if (ft_strncmp(current[shell->unset.i], \
			shell->lst.executor[1], shell->unset.position) == 0)
		{
			shell->unset.j = shell->unset.i - 1;
			while (current[++shell->unset.j])
			{
				if (current[shell->unset.j + 1] != NULL)
				{
					free(current[shell->unset.j]);
					current[shell->unset.j] = ft_strdup \
						(current[shell->unset.j + 1]);
				}
				else
				{
					free(current[shell->unset.j]);
					current[shell->unset.j] = NULL;
				}
			}
			break ;
		}
	}
}
