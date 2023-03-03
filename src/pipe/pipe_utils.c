/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:55:58 by mich              #+#    #+#             */
/*   Updated: 2023/03/03 15:44:00 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"
	// write(2, shell->lst.input, ft_strlen(shell->lst.input));

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
	if (i)
		dup2(shell->stdout, STDOUT_FILENO);
	else
		dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	d = check_red(shell->lst.input, shell, i);
	if (d == 0)
		executor(shell);
	return (1);
}
