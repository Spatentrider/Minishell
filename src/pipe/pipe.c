/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:06:58 by mich              #+#    #+#             */
/*   Updated: 2023/02/17 11:33:46 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

void	change_in(t_shell *shell, int c)
{
	int	i;
	int	j;

	i = 0;
	printf("%d", c);
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

int	process_pipe(t_shell *shell, int *pid, int c, int j)
{
	int	fd[2];
	int d;
	int i;

	d = 0;
	i = -1;
	pipe(fd);
	pid[c] = fork();
	if(!pid[c])
	{
		change_in(shell, c);
		dup2(fd[1], STDOUT_FILENO);
		d = check_red(shell->lst.input, shell, i);
		if(d == 0)
			executor(shell);
		free(pid);
		exit(0);
	}
	if(j != 1)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		++c;
		change_in(shell, c);
		d = check_red(shell->lst.input, shell, i);
		if(d == 0)
			executor(shell);
		return(1);
	}	
	return(0);
}

int	last_process(t_shell *shell, int c, int i)
{
	int d;
	int fd[2];
	d = 0;
	pipe(fd);
	printf("%d", c);
	sleep(5);
	dup2(fd[0], STDIN_FILENO);
	++c;
	change_in(shell, c);
	d = check_red(shell->lst.input, shell, i);
	if(d == 0)
		executor(shell);
	close(fd[0]);
	close(fd[1]);
	return (1);
}

int	control_pipe(t_shell *shell)
{
	int	i;
	int j;
	int	pipe_counter;
	int	*pid;
	int	c;
	int	status;
	int copy;

	i = -1;
	c = 0;
	j = 0;
	status = 0;
	pipe_counter = 0;
	while (shell->lst.input[++i])
	{
		if (is_pipe(shell->lst.input[i]) == 1)
			pipe_counter++;
	}
	copy = dup(STDOUT_FILENO);
	if (pipe_counter > 0)
	{
		shell->lst.pipe = split_pipe(shell->lst.input);
		pid = (int *) malloc(sizeof(int) * pipe_counter);
		while (c < pipe_counter)
		{
			if(c == pipe_counter - 1)
				j = 1;
			status = process_pipe(shell, pid, c, j);
			if(j == 0)
				c++;
			printf("%d", c);
		}
		dup2(copy, STDOUT_FILENO);
		printf("%d", c);
		last_process(shell, c, i);
		//dup2(i, STDOUT_FILENO);
		//status = ft_pipe(shell, pid, c);
		// if (c == 1)
		// 	ft_pipe(shell->lst.pipe, shell);
		// else
		// 	cazzi_e_mazzi(shell->lst.pipe, shell);
	}
	(void)status;
	return (0);
}
