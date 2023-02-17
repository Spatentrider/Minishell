/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:06:58 by mich              #+#    #+#             */
/*   Updated: 2023/02/16 11:50:15 by mich             ###   ########.fr       */
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

int process_pipe(t_shell *shell, int *pid, int c)
{
	int fd[2];

	pipe(fd);
	pid[c] = fork();
	dup2(fd[0], STDIN_FILENO);
	executor(shell);
	close(fd[1]);
	close(fd[0]);
	return (1);
}

int	control_pipe(t_shell *shell)
{
	int	i;
	int	pipe_counter;
	int *pid;
	int c;
	int status;

	i = -1;
	c = 0;
	status = 0;
	pipe_counter = 0;
	while (shell->lst.input[++i])
	{
		if (is_pipe(shell->lst.input[i]) == 1)
			pipe_counter++;
	}
	if (pipe_counter > 0)
	{
		shell->lst.pipe = split_pipe(shell->lst.input);
		pid = (int *) malloc(sizeof(int) * pipe_counter);
		while (c < pipe_counter)
		{
			status = process_pipe(shell,pid,c);
			c++;
		}
		// if (c == 1)
		// 	ft_pipe(shell->lst.pipe, shell);
		// else
		// 	cazzi_e_mazzi(shell->lst.pipe, shell);
	}
	(void)status;
	return (0);
}
