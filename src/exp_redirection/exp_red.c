/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_red.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:39:47 by mich              #+#    #+#             */
/*   Updated: 2023/04/17 14:39:51 by mich             ###   ########.fr       */
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

void	change_curr(t_shell *shell)
{
	while (shell->env.current[++shell->expn.c])
	{
		shell->expn.pos = -1;
		while (shell->lst.expansion[shell->expn.j][++shell->expn.pos])
			;
		control_a(shell);
		shell->expn.pos = ft_strchrp(shell->env.current[shell->expn.c], '=');
		if (shell->expn.pos > 0)
			shell->expn.curr = strdup_exp(shell->env.current[shell->expn.c], \
				shell->expn.pos);
		else
			shell->expn.curr = ft_strdup(shell->env.current[shell->expn.c]);
		if (ft_strncmp(shell->lst.expansion[shell->expn.j], shell->expn.curr, \
			ft_strlen(shell->lst.expansion[shell->expn.j])) == 0)
		{
			change_exp_red(shell, shell->expn.j, shell->expn.curr, \
				shell->expn.c);
			if (shell->expn.curr)
				free(shell->expn.curr);
			break ;
		}
		if (shell->expn.curr)
			free(shell->expn.curr);
	}
}

void	list_exp_red(t_shell *shell, int i)
{
	init_var(shell, i);
	while (shell->lst.expansion[++shell->expn.j])
	{
		shell->expn.c = -1;
		if ((shell->expn.flag == 0) && (shell->flag == 0))
			change_curr(shell);
		else
		{
			shell->flag = 0;
			shell->expn.flag = 0;
			if (shell->lst.expansion[shell->expn.j][0] == '\a')
				shell->expn.flag = 1;
			shell->str = ft_strdup(shell->lst.expansion[shell->expn.j]);
			free(shell->lst.expansion[shell->expn.j]);
			shell->lst.expansion[shell->expn.j] = ft_strjoin("$", shell->str);
		}
		if (shell->env.current[shell->expn.c] == NULL)
		{
			free(shell->lst.expansion[shell->expn.j]);
			shell->lst.expansion[shell->expn.j] = ft_strdup("\a");
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
