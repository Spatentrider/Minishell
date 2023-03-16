/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:43:40 by mich              #+#    #+#             */
/*   Updated: 2023/03/16 15:44:45 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

void	list_expansion(char *current, int pos, t_shell *shell)
{
	int		i;
	char	*str;

	i = -1;
	str = ft_strdup(current + pos);
	while (shell->lst.executor[++i])
	{
		if (ft_strncmp(shell->lst.executor[i], "$", 1) == 0)
			break ;
	}
	free(shell->lst.executor[i]);
	shell->lst.executor[i] = ft_strdup(str + 1);
	free(str);
	str = NULL;
}

void	expansion(t_shell *shell)
{
	int		j;
	int		pos;
	char	*str;
	char	*curr;

	shell->exp.i = -1;
	while (shell->lst.executor[++shell->exp.i])
	{
		if (ft_strncmp(shell->lst.executor[shell->exp.i], "$?", 2) == 0)
			shell->lst.executor[shell->exp.i] = ft_itoa(shell->old_g_exit);
		else if (ft_strncmp(shell->lst.executor[shell->exp.i], "$", 1) == 0)
		{
			str = ft_strdup(shell->lst.executor[shell->exp.i] + 1);
			j = -1;
			while (shell->env.current[++j])
			{		
				pos = ft_strchrp(shell->env.current[j], '=');
				curr = strdup_curr(shell->env.current[j]);
				if (ft_strncmp(curr, str, pos) == 0)
					list_expansion(shell->env.current[j], pos, shell);
			}
			free(str);
			str = NULL;
		}
	}
}
