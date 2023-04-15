/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:27:19 by mich              #+#    #+#             */
/*   Updated: 2023/04/15 12:20:53 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unset.h"

void	unset_loop(t_shell *shell, char **current)
{
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
}

int	cont_unset(t_shell *shell, char *curr, char *str, char **current)
{
	if (shell->unset.position > 0)
		str = strdup_exp(shell->lst.executor[shell->unset.k], \
		shell->unset.position);
	else
		str = ft_strdup(shell->lst.executor[shell->unset.k]);
	if (ft_strncmp(curr, str, ft_strlen(str)) == 0)
	{
		shell->unset.j = shell->unset.i - 1;
		unset_loop(shell, current);
		return (1);
	}
	return (0);
}

void	ft_unset(t_shell *shell, char **current)
{
	char	*curr;
	char	*str;

	shell->unset.k = 0;
	shell->unset.j = 0;
	while (shell->lst.executor[++shell->unset.k])
	{
		shell->unset.i = -1;
		while (current[++shell->unset.i])
		{
			shell->unset.position = ft_strchrp(current[shell->unset.i], '=');
			if (shell->unset.position > 0)
				curr = strdup_exp(current[shell->unset.i], \
					shell->unset.position);
			else
				curr = ft_strdup(current[shell->unset.i]);
			shell->unset.position = \
				ft_strchrp(shell->lst.executor[shell->unset.k], '=');
			if (cont_unset(shell, curr, str, current))
				break ;
			(void)str;
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
