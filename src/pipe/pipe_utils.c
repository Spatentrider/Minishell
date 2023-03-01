/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:55:58 by mich              #+#    #+#             */
/*   Updated: 2023/03/01 15:42:07 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

int	count_pipe(t_shell *shell, int i)
{
	int	pipe_counter;

	pipe_counter = 0;
	while (shell->lst.input[++i])
	{
		if (is_pipe(shell->lst.input[i]) == 1)
			pipe_counter++;
	}
	return (pipe_counter);
}

int	process_child(int *fd, int c, t_shell *shell, int i)
{
	int	d;

	d = 0;
	change_in(shell, c);
	dup2(fd[1], STDOUT_FILENO);
	d = check_red(shell->lst.input, shell, i);
	if (d == 0)
		executor(shell);
	return (1);
}

int	process_father(int *fd, t_shell *shell, int c, int i)
{
	int	d;

	d = 0;
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	++c;
	change_in(shell, c);
	d = check_red(shell->lst.input, shell, i);
	if (d == 0)
		executor(shell);
	return (1);
}
