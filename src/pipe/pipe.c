/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:06:58 by mich              #+#    #+#             */
/*   Updated: 2023/04/13 10:32:40 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

void	change_in(t_shell *shell, int c)
{
	free(shell->lst.input);
	shell->lst.input = NULL;
	shell->lst.input = ft_strdup(shell->lst.pipe[c]);
}

int	last_process(t_shell *shell, int c, int *pid, int j)
{
	int	d;

	d = 0;
	while (d < c)
	{
		if (j)
		{
			waitpid(pid[d], &g_exit, 0);
			if (WIFEXITED(g_exit))
				g_exit = WEXITSTATUS(g_exit);
		}
		d++;
	}
	free(pid);
	pid = NULL;
	(void)shell;
	return (0);
}

int	process_pipe(t_shell *shell, int *pid, int c, int j)
{
	int	fd[2];

	pipe(fd);
	pid[c] = fork();
	if (!pid[c])
	{
		process_child(fd, c, shell, j);
		exit(0);
	}
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	(void)j;
	return (0);
}

int	control_pipe(t_shell *shell)
{
	int	j;
	int	pipe_counter;
	int	*pid;
	int	c;

	c = 0;
	j = 0;
	shell->lst.pipe = split_pipe(shell->lst.input);
	pipe_counter = ft_sarsize(shell->lst.pipe);
	if (pipe_counter > 1)
	{
		pid = (int *) malloc(sizeof(int) * pipe_counter);
		while (c < pipe_counter)
		{
			if (c == pipe_counter - 1)
				j = 1;
			process_pipe(shell, pid, c, j);
			c++;
		}
		last_process(shell, c, pid, j);
		ft_sarfree(shell->lst.pipe, ft_sarsize(shell->lst.pipe));
		return (1);
	}
	if (shell->lst.pipe)
		ft_sarfree(shell->lst.pipe, ft_sarsize(shell->lst.pipe));
	return (0);
}
