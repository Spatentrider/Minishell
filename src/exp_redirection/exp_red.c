/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_red.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 11:24:08 by mich              #+#    #+#             */
/*   Updated: 2023/04/15 11:34:14 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp_red.h"

void	join_redirection(t_shell *shell, int i)
{
	int	j;

	free(shell->lst.redirection[i]);
	if (shell->lst.expansion[1])
	{
		shell->lst.redirection[i] = ft_strjoin(shell->lst.expansion[0], \
			shell->lst.expansion[1]);
		j = 1;
		while (shell->lst.expansion[++j])
			shell->lst.redirection[i] = ft_strjoin(shell->lst.redirection[i], \
			shell->lst.expansion[j]);
	}
	else
		shell->lst.redirection[i] = ft_strdup(shell->lst.expansion[0]);
}

void	change_exp_red(t_shell *shell, int i, char *curr, int c)
{
	char	*str;

	str = ft_strdup(shell->env.current[c] + ft_strlen(curr) + 1);
	free(shell->lst.expansion[i]);
	shell->lst.expansion[i] = ft_strdup(str);
	free(str);
}

void	list_exp_red(t_shell *shell, int i)
{
	char	*curr;
	int		pos;
	int		j;
	int		c;
	int		flag;

	if (shell->lst.redirection[i][0] == '$')
		shell->dollar = 1;
	if (shell->lst.redirection[i][0] == '\a')
		shell->flag = 1;
	j = -1;
	pos = 0;
	flag = 0;
	shell->lst.expansion = ft_split(shell->lst.redirection[i], '$');
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
					change_exp_red(shell, j, curr, c);
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
			shell->lst.expansion[j][0] = '$';
		}
		if (shell->env.current[c] == NULL)
		{
			free(shell->lst.expansion[j]);
			shell->lst.expansion[j] = ft_strdup("\a");
		}
	}
	join_redirection(shell, i);
	ft_sarfree(shell->lst.expansion, ft_sarsize(shell->lst.expansion));
}

void	exp_red(t_shell *shell)
{
	int		j;

	shell->exp.i = -1;
	while (shell->lst.redirection[++shell->exp.i])
	{
		j = -1;
		while (shell->lst.redirection[shell->exp.i][++j])
		{
			if (shell->lst.redirection[shell->exp.i][j] == '$')
				list_exp_red(shell, shell->exp.i);
		}
	}
}
