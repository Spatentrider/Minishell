/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:43:40 by mich              #+#    #+#             */
/*   Updated: 2023/04/12 15:11:55 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

void	join_executor(t_shell *shell, int i)
{
	int	j;

	free(shell->lst.executor[i]);
	if (shell->lst.expansion[1])
	{
		shell->lst.executor[i] = ft_strjoin(shell->lst.expansion[0], \
			shell->lst.expansion[1]);
		j = 1;
		while (shell->lst.expansion[++j])
			shell->lst.executor[i] = ft_strjoin(shell->lst.executor[i], \
			shell->lst.expansion[j]);
	}
	else
		shell->lst.executor[i] = ft_strdup(shell->lst.expansion[0]);
}

void	change_expansion(t_shell *shell, int i, char *curr, int c)
{
	char	*str;

	str = ft_strdup(shell->env.current[c] + ft_strlen(curr) + 1);
	free(shell->lst.expansion[i]);
	shell->lst.expansion[i] = ft_strdup(str);
	free(str);
}

void	list_expansion(t_shell *shell, int i)
{
	char	*curr;
	int		pos;
	int		j;
	int		c;
	int		flag;

	if (shell->lst.executor[i][0] == '$')
		shell->dollar = 1;
	if (shell->lst.executor[i][0] == '\a')
		shell->flag = 1;
	j = -1;
	pos = 0;
	flag = 0;
	shell->lst.expansion = ft_split(shell->lst.executor[i], '$');
	if (shell->dollar == 1)
		j = -1;
	else
		j = 0;
	while (shell->lst.expansion[++j])
	{
		c = -1;
		if ((flag == 0) && (shell->flag == 0))
		{
			while (shell->env.current[++c])
			{
				pos = -1;
				while (shell->lst.expansion[j][++pos])
					;
				if (shell->lst.expansion[j][pos - 1] == '\a')
				{
					shell->lst.expansion[j][pos - 1] = '\0';
					flag = 1;
				}
				pos = ft_strchrp(shell->env.current[c], '=');
				if (pos > 0)
					curr = strdup_exp(shell->env.current[c], pos);
				else
					curr = ft_strdup(shell->env.current[c]);
				if (ft_strncmp(shell->lst.expansion[j], curr, \
					ft_strlen(shell->lst.expansion[j])) == 0)
				{
					change_expansion(shell, j, curr, c);
					if (curr)
						free(curr);
					break ;
				}
				if (curr)
					free(curr);
			}
		}
		else
		{
			shell->flag = 0;
			flag = 0;
			if (shell->lst.expansion[j][0] == '\a')
				flag = 1;
		}
		if (shell->env.current[c] == NULL)
		{
			free(shell->lst.expansion[j]);
			shell->lst.expansion[j] = ft_strdup("\a");
		}
	}
	join_executor(shell, i);
	ft_sarfree(shell->lst.expansion, ft_sarsize(shell->lst.expansion));
}

void	expansion(t_shell *shell)
{
	int		j;

	shell->exp.i = -1;
	while (shell->lst.executor[++shell->exp.i])
	{
		if (ft_strncmp(shell->lst.executor[shell->exp.i], "$?", 2) == 0)
		{
			free(shell->lst.executor[shell->exp.i]);
			shell->lst.executor[shell->exp.i] = ft_itoa(shell->old_g_exit);
		}
		else
		{
			j = -1;
			while (shell->lst.executor[shell->exp.i][++j])
			{
				if (shell->lst.executor[shell->exp.i][j] == '$')
					list_expansion(shell, shell->exp.i);
			}
		}
	}
}
