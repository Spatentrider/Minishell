/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:31:00 by mich              #+#    #+#             */
/*   Updated: 2023/03/22 16:14:14 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	delete_file(t_shell *shell, int i, int j)
{
	while (shell->lst.executor[++i])
	{
		while (shell->lst.executor[i][++j])
			;
		if (ft_strncmp(shell->lst.executor[i], shell->lst.file[0], j) == 0)
		{
			i -= 1;
			while (shell->lst.executor[++i])
			{
				if (shell->lst.executor[i + 1] != NULL)
				{
					free(shell->lst.executor[i]);
					shell->lst.executor[i] = ft_strdup \
						(shell->lst.executor[i + 1]);
				}
				else
				{
					free(shell->lst.executor[i]);
					shell->lst.executor[i] = NULL;
				}
			}
			break ;
		}
	}
}

int	check_file(t_shell *shell)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (shell->lst.redirection == NULL)
		return (1);
	else
	{
		delete_file(shell, i, j);
		return (0);
	}
}

int	executor(t_shell *shell)
{
	shell->lst.executor = ft_split(shell->lst.input, ' ');
	check_file(shell);
	expansion(shell);
	if (ft_strncmp(shell->lst.input, "$?", 3) == 0)
	{
		printf("%d: command not found\n", shell->old_g_exit);
		if (shell->lst.executor)
			ft_sarfree(shell->lst.executor, ft_sarsize(shell->lst.executor));
		shell->old_g_exit = 127;
		return (g_exit);
	}
	if (strncmp(shell->lst.executor[0], "pwd", 4) == 0)
		pwd();
	else if (strncmp(shell->lst.executor[0], "echo", 5) == 0)
		ft_echo(shell);
	else if (strncmp(shell->lst.executor[0], "cd", 3) == 0)
		ft_cd(shell);
	else if (strncmp(shell->lst.executor[0], "env", 4) == 0)
		ft_env(shell, shell->env.current);
	else if (strncmp(shell->lst.executor[0], "exit", 5) == 0)
		ft_exit(shell);
	else if (strncmp(shell->lst.executor[0], "export", 7) == 0)
		ft_export(shell);
	else if (strncmp(shell->lst.executor[0], "unset", 6) == 0)
		ft_unset (shell, shell->env.current);
	else
		commands(shell);
	if(shell->lst.executor)
		ft_sarfree(shell->lst.executor, ft_sarsize(shell->lst.executor));
	return (0);
}
