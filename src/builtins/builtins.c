/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzodimascia <lorenzodimascia@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:31:00 by mich              #+#    #+#             */
/*   Updated: 2023/03/29 17:00:26 by lorenzodima      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	delete_file(t_shell *shell)
{
	int i;
	int k;
	int j;
	
	k = -1;
	printf("entro?");
	while(shell->lst.delete_str[++k])
	{
		i = -1;
		while(shell->lst.executor[++i])
		{
			if(ft_strncmp(shell->lst.executor[i], shell->lst.delete_str[k], ft_strlen(shell->lst.executor[i])) == 0)
			{
				j = i ;
				while(shell->lst.executor[j])
				{
					free(shell->lst.executor[j]);
					if(shell->lst.executor[j + 1] != NULL)
					{
						shell->lst.executor[j] = ft_strdup(shell->lst.executor[j + 1]);
						j++;
					}
					else
					{
						shell->lst.executor[j] = NULL;
					}
				}
			}
		}
	}
}

int	check_file(t_shell *shell)
{
	if (shell->lst.redirection == NULL || shell->redirection_id != 1 || shell->redirection_id != 3)
		return (1);
	else
	{
		delete_file(shell);
		return (0);
	}
}

int	executor(t_shell *shell)
{
	if (ft_strncmp(shell->lst.input, "$?", 3) == 0)
	{
		printf("%d: command not found\n", shell->old_g_exit);
		shell->old_g_exit = 127;
		return (g_exit);
	}
	shell->lst.executor = ft_split(shell->lst.input, ' ');
	check_file(shell);
	expansion(shell);
	if (strncmp(shell->lst.executor[0], "pwd", 4) == 0)
		pwd();
	else if (strncmp(shell->lst.executor[0], "echo", 5) == 0)
		ft_echo(shell);
	else if (strncmp(shell->lst.executor[0], "cd", 3) == 0)
		ft_cd(shell);
	else if (strncmp(shell->lst.executor[0], "env", 4) == 0)
		ft_env(shell, shell->env.current);
	else if (strncmp(shell->lst.executor[0], "exit", 5) == 0)
		ft_exit(shell);
	else if (strncmp(shell->lst.executor[0], "export", 7) == 0)
		ft_export(shell);
	else if (strncmp(shell->lst.executor[0], "unset", 6) == 0)
		ft_unset (shell, shell->env.current);
	else
		commands(shell);
	ft_sarfree(shell->lst.executor, ft_sarsize(shell->lst.executor));
	return (0);
}
