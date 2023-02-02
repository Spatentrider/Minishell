/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:31:00 by mich              #+#    #+#             */
/*   Updated: 2023/02/02 17:10:53 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	executor(t_shell *shell)
{
	int			i;

	i = -1;
	shell->lst.executor = split_executor(shell->lst.input);
	while (shell->lst.executor[++i])
	{
		if (strncmp(shell->lst.executor[i], "pwd", 4) == 0)
			ft_pwd();
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
	}
	return (0);
}
