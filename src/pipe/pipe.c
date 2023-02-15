/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:06:58 by mich              #+#    #+#             */
/*   Updated: 2023/02/15 16:21:41 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

void	change_in(t_shell *shell)
{
	int	i;
	int	j;

	i = 0;
	while (shell->lst.input[++i])
		shell->lst.input[i] = ' ';
	i = 0;
	j = -1;
	while (shell->lst.pipe[1][++j])
	{
		shell->lst.input[i] = shell->lst.pipe[1][j];
		i++;
	}
	shell->lst.input[i] = '\0';
	executor(shell);
}

int	ft_pipe(char **pip, t_shell *shell)
{
	int	fd[2];
	int	status;
	int	pid;
	int	pid1;
	int	i;

	(void)pip;
	i = dup(STDOUT_FILENO);
	// j = dup(STDIN_FILENO);
	if (pipe(fd) == -1)
		exit(printf("Failure\n"));
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		// change_in(shell);
		printf("bho\n");
	}
	else
	{
		dup2(i, STDOUT_FILENO);
		pid1 = fork();
		if (pid1 == 0)
		{
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
			change_in(shell);
		}
		else
		{
			close(fd[0]);
			close(fd[1]);
			waitpid(pid, &status, 0);
			if (WIFEXITED(status))
				printf("fiuto\n");
			waitpid(pid1, &status, 0);
			if (WIFEXITED(status))
				printf("pippo\n");
		}
	}
	return (0);
}

int	control_pipe(t_shell *shell)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (shell->lst.input[++i])
	{
		if (is_pipe(shell->lst.input[i]) == 1)
		{
			j = 1;
			break ;
		}
	}
	if (j == 1)
	{
		shell->lst.pipe = split_pipe(shell->lst.input);
		ft_pipe(shell->lst.pipe, shell);
	}
	return (0);
}
