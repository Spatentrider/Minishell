/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:12:50 by mich              #+#    #+#             */
/*   Updated: 2023/04/15 16:53:42 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int	control_cmd(t_shell *shell)
{
	if (ft_strncmp("./minishell", shell->lst.executor[0], 12) == 0)
	{
		minishell_case(shell);
		return (1);
	}
	return (0);
}

int	control_path(t_shell *shell)
{
	shell->exp.i = -1;
	shell->exp.j = -1;
	while (shell->env.current[++shell->exp.i])
	{
		if (ft_strncmp(shell->env.current[shell->exp.i], "PATH=", 5) == 0)
		{
			shell->path = ft_split(shell->env.current[shell->exp.i] + 5, ':');
			while (shell->path[++shell->exp.j])
			{
				shell->str = ft_strjoin(shell->path[shell->exp.j], "/");
				shell->str = ft_strjoinfree(shell->str, \
					ft_strdup(shell->lst.executor[0]));
				if (!access(shell->str, F_OK))
				{
					ft_fork(shell, shell->str);
					ft_sarfree(shell->path, ft_sarsize(shell->path));
					return (1);
				}
				free(shell->str);
			}
			ft_sarfree(shell->path, ft_sarsize(shell->path));
		}
	}
	return (0);
}

int	fork_process(int pid, char *str)
{
	waitpid(pid, &g_exit, 0);
	if (WIFEXITED(g_exit))
	{
		free(str);
		return (g_exit = WEXITSTATUS(g_exit));
	}
	free(str);
	return (0);
}
