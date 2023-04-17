/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:53:12 by mich              #+#    #+#             */
/*   Updated: 2023/04/17 15:21:12 by mich             ###   ########.fr       */
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
		ft_sarfree(shell->lst.executor, ft_sarsize(shell->lst.executor));
		free(shell->lst.input);
		shell->lst.input = NULL;
		if (loop(shell) == -1)
		{
			perror("execve failed");
			exit(EXIT_FAILURE);
		}
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (0);
	return (1);
}

int	ft_fork(t_shell *shell, char *str)
{
	int	pid;

	pid = fork();
	signal(SIGINT, signal_handler2);
	signal(SIGQUIT, signal_handler3);
	if (pid == 0)
	{
		if (execve(str, shell->lst.executor, NULL) == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		if (g_exit == 130 || g_exit == 131)
		{
			free(str);
			exit(0);
		}
	}
	return (fork_process(pid, str));
}

int	ab_path(t_shell	*shell)
{
	int	pid;

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
		waitpid(pid, &g_exit, 0);
		if (WIFEXITED(g_exit))
			g_exit = WEXITSTATUS(g_exit);
		return (1);
	}
	return (0);
}

void	change_shlvl(t_shell *shell)
{
	char	*save;

	shell->exp.i = -1;
	shell->exp.j = -1;
	shell->exp.pos = 5;
	save = (char *)malloc(sizeof(char) * 10);
	while (shell->env.current[++shell->exp.i])
	{
		if (ft_strncmp("SHLVL=", shell->env.current[shell->exp.i], 6) == 0)
		{
			while (shell->env.current[shell->exp.i][++shell->exp.pos])
				save[++shell->exp.j] = \
					shell->env.current[shell->exp.i][shell->exp.pos];
			save[++shell->exp.j] = '\0';
			break ;
		}
	}
	if (save[1] == '\0')
		save[0]++;
	free(shell->env.current[shell->exp.i]);
	shell->env.current[shell->exp.i] = ft_strjoin("SHLVL=", save);
	free(save);
	save = NULL;
}

int	commands(t_shell *shell)
{
	char	*str;

	if (shell->lst.executor[1] == NULL)
	{
		str = ft_strdup(shell->lst.executor[0]);
		ft_sarfree(shell->lst.executor, ft_sarsize(shell->lst.executor));
		shell->lst.executor = ft_split(str, ' ');
		free(str);
	}
	if (control_cmd(shell))
		return (1);
	else if (control_path(shell))
		return (1);
	else if (ab_path(shell))
		return (1);
	g_exit = 127;
	dup2(shell->stdout, STDOUT_FILENO);
	printf("%s: command not found\n", shell->lst.executor[0]);
	return (1);
}
