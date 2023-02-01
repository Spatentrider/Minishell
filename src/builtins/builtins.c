/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:31:00 by mich              #+#    #+#             */
/*   Updated: 2023/02/01 15:31:34 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	main(int argc, char **argv, char **envp)
{
	int			i;
	t_shell		shell;

	get_env(envp, &shell);
	i = -1;
	while (argv[++i])
	{
		if (strncmp(argv[i], "pwd", 4) == 0)
			ft_pwd();
		else if (strncmp(argv[i], "echo", 5) == 0)
			ft_echo(argc, argv, shell);
		else if (strncmp(argv[i], "cd", 3) == 0)
			ft_cd(argc, argv, shell);
		else if (strncmp(argv[i], "env", 4) == 0)
			ft_env(shell.env.current);
		else if (strncmp(argv[i], "exit", 5) == 0)
			ft_exit(argc, argv, shell.env.current);
		else if (strncmp(argv[i], "export", 7) == 0)
			ft_export(argc, argv, shell);
		else if (strncmp(argv[i], "unset", 6) == 0)
			ft_unset (argc, argv, shell.env.current);
	}
	return (0);
}
