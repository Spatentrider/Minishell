/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:31:00 by mich              #+#    #+#             */
/*   Updated: 2023/02/08 15:12:37 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	executor(t_shell *shell, char *str)
{
	int		i;
	// int		pid;
	// int		status;

	i = -1;
	shell->lst.executor = split_executor(str);
	while (shell->lst.executor[++i])
	{
		if (strncmp(shell->lst.executor[i], "pwd", 4) == 0)
			pwd();
		else if (strncmp(shell->lst.executor[i], "echo", 5) == 0)
			ft_echo(shell);
		else if (strncmp(shell->lst.executor[i], "cd", 3) == 0)
			ft_cd(shell);
		else if (strncmp(shell->lst.executor[i], "env", 4) == 0)
			ft_env(shell->env.current);
		else if (strncmp(shell->lst.executor[i], "exit", 5) == 0)
			ft_exit(shell->env.current);
		else if (strncmp(shell->lst.executor[i], "export", 7) == 0)
			ft_export(shell);
		else if (strncmp(shell->lst.executor[i], "unset", 6) == 0)
			ft_unset (shell, shell->env.current);
		// else
		// {
		// 	pid = fork();
		// 	if (pid == 0)
		// 	{
		// 		char *args[] = {shell->lst.executor[i], shell->lst.executor[i + 1], NULL};
		// 		execve("/bin/ls", args, NULL);
		// 	}
		// 	else
		// 	{
		// 		waitpid(pid, &status, 0);
		// 		if (WIFEXITED(status))
		// 		{
		// 			printf("Il processo figlio ha terminato con codice %d\n", WEXITSTATUS(status));
		// 			break ;
		// 		}
		// 	}
	}
	return (0);
}
