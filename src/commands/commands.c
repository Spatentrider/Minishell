/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:53:12 by mich              #+#    #+#             */
/*   Updated: 2023/02/20 15:47:35 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int	ft_fork(t_shell *shell)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, signal_handler2);
		if (execve(ft_strjoin("/bin/", shell->lst.executor[0]), \
			shell->lst.executor, NULL) == -1)
		{
			perror("execve failed");
			exit(EXIT_FAILURE);
		}
		exit(0);
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
	return (0);
}

int	ab_path(t_shell	*shell)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(shell->lst.executor[0], shell->lst.executor, NULL) == -1)
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
	return (0);
}

int	commands(t_shell *shell)
{
	int		c;

	c = -1;
	if (ft_strncmp("/bin/", shell->lst.executor[0], 5) == 0)
	{
		ab_path(shell);
		return (1);
	}
	while (shell->env.current[++c])
	{
		if (ft_strncmp(shell->env.save, shell->env.current[c], \
			shell->env.i) == 0)
			ft_fork(shell);
	}
	return (1);
}
