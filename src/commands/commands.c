/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:53:12 by mich              #+#    #+#             */
/*   Updated: 2023/03/16 14:59:18 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int	minishell_case(t_shell *shell)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == 0)
	{
		change_shlvl(shell);
		if (loop(shell, shell->stdout, shell->stdin) == -1)
		{
			perror("execve failed");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{	
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			return (0);
	}
	else
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	return (1);
}

int	ft_fork(t_shell *shell, char *str)
{
	int	pid;
	int	status;

	pid = fork();
	signal(SIGINT, signal_handler2);
	signal(SIGQUIT, signal_handler3);
	if (pid == 0)
	{
		if (execve(str, shell->lst.executor, NULL) == -1)
			exit(EXIT_FAILURE);
		if (g_exit == 130 || g_exit == 131)
			exit(0);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			return (0);
	}
	else
		exit(EXIT_FAILURE);
	return (0);
}

int	ab_path(t_shell	*shell)
{
	int	pid;
	int	status;

	if (!access(shell->lst.executor[0], F_OK))
	{
		signal(SIGINT, signal_handler2);
		pid = fork();
		if (pid == 0)
		{
			if (execve(shell->lst.executor[0], shell->lst.executor, NULL) == -1)
				exit(EXIT_FAILURE);
			if (g_exit == 130)
				exit(0);
		}
		else if (pid > 0)
		{
			waitpid(pid, &status, 0);
			if (WIFEXITED(status))
				return (0);
		}
		else
			exit(EXIT_FAILURE);
	}
	return (0);
}

void	change_shlvl(t_shell *shell)
{
	int		i;
	int		j;
	int		k;
	char	*save;

	i = -1;
	j = 0;
	k = 5;
	save = (char *)malloc(sizeof(char) * 10);
	while (shell->env.current[++i])
	{
		if (ft_strncmp("SHLVL=", shell->env.current[i], 6) == 0)
		{
			while (shell->env.current[i][++k])
			{
				save[j] = shell->env.current[i][k];
				j++;
			}
			save[j] = '\0';
			break ;
		}
	}
	if (save[1] == '\0')
		save[0]++;
	free(shell->env.current[i]);
	shell->env.current[i] = ft_strjoin("SHLVL=", save);
	free(save);
	save = NULL;
}

int	commands(t_shell *shell)
{
	char	**path;
	char	*str;

	path = (char **)malloc(sizeof(char *) * 200);
	str = NULL;
	if (control_cmd(shell))
		return (1);
	else if (control_path(shell, path, str))
		return (1);
	g_exit = 127;
	printf("%s: command not found\n", shell->lst.executor[0]);
	return (1);
}
