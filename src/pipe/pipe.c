/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:06:58 by mich              #+#    #+#             */
/*   Updated: 2023/03/01 15:36:10 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

void	change_in(t_shell *shell, int c)
{
	int	i;
	int	j;

	i = 0;
	while (shell->lst.input[++i])
		shell->lst.input[i] = ' ';
	i = 0;
	j = -1;
	while (shell->lst.pipe[c][++j])
	{
		shell->lst.input[i] = shell->lst.pipe[c][j];
		i++;
	}
	shell->lst.input[i] = '\0';
}

int	last_process(t_shell *shell, int c, int i)
{
	int	d;
	int	fd[2];

	d = 0;
	pipe(fd);
	dup2(fd[0], STDIN_FILENO);
	c++;
	change_in(shell, c);
	d = check_red(shell->lst.input, shell, i);
	if (d == 0)
		executor(shell);
	close(fd[0]);
	close(fd[1]);
	return (1);
}

int	process_pipe(t_shell *shell, int *pid, int c, int j)
{
	int	fd[2];
	int	i;

	i = -1;
	pipe(fd);
	if (j == 1)
	{
		last_process(shell, c, i);
		return (1);
	}
	pid[c] = fork();
	if (!pid[c])
	{
		process_child(fd, c, shell, i);
		free(pid);
		exit(0);
	}
	if (j != 1)
		process_father(fd, shell, c, i);
	return (0);
}

int	control_pipe(t_shell *shell)
{
	int	i;
	int	j;
	int	pipe_counter;
	int	*pid;
	int	c;

	i = -1;
	c = 0;
	j = 0;
	pipe_counter = count_pipe(shell, i);
	i = dup(STDOUT_FILENO);
	if (pipe_counter > 0)
	{
		shell->lst.pipe = split_pipe(shell->lst.input);
		pid = (int *) malloc(sizeof(int) * pipe_counter);
		while (c < pipe_counter || j == 0)
		{
			if (c == pipe_counter - 1)
				j = 1;
			process_pipe(shell, pid, c, j);
				c++;
			dup2(i, STDOUT_FILENO);
		}
	}
	return (0);
}
