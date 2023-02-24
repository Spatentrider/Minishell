/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:17:02 by mich              #+#    #+#             */
/*   Updated: 2023/02/21 15:50:29 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

int inside_exit(t_shell *shell)
{
	int	k;

	k = -1;
	if (shell->lst.executor[1] != NULL)
	{
		while (shell->lst.executor[1][++k])
		{
			if (isdigit(shell->lst.executor[1][k]) == 0)
			{
				g_exit = (int)shell->lst.executor[1][k];
				if (shell->lst.executor[2] == NULL)
				{
					printf("exit\n");
					printf("minishell: exit: %s: numeric argument required\n", \
					shell->lst.executor[1]);
					return(0);
				}
			}
		}
	}
	return(0);
}

int	nor_exit(t_shell *shell)
{
	int	k;

	k = -1;
	if (shell->lst.executor[1] != NULL)
	{
		while (shell->lst.executor[1][++k])
		{
			if (isdigit(shell->lst.executor[1][k]) == 0)
			{
				if (shell->lst.executor[2] == NULL)
				{
					printf("exit\n");
					printf("minishell: exit: %s: numeric argument required\n", \
					shell->lst.executor[1]);
					return(0);
				}
			}
		}
	}
	printf("exit\n");
	exit(ft_atoi(shell->lst.executor[1]));
}


void	reduce_shlvl(t_shell *shell)
{
	int		i;
	int		j;
	int		k;
	char	*save;

	i = -1;
	j = 0;
	k = 5;
	save = (char *)malloc(sizeof(char) * 10);
	while (shell->env.current[++i])
	{
		if (ft_strncmp("SHLVL=", shell->env.current[i], 6) == 0)
		{
			while (shell->env.current[i][++k])
			{
				save[j] = shell->env.current[i][k];
				j++;
			}
			save[j] = '\0';
			break ;
		}
	}
	save[0]--;
	shell->env.current[i] = ft_strjoin("SHLVL=", save);
	inside_exit(shell);
}

void	ft_exit(t_shell *shell)
{
	int	k;

	k = -1;
	if (shell->lst.executor[1] != NULL)
	{
		while (shell->lst.executor[1][++k])
		{
			if (isdigit(shell->lst.executor[1][k]) == 0)
			{
				if (shell->lst.executor[2] == NULL)
				{
					printf("exit\n");
					printf("minishell: exit: %s: numeric argument required\n", \
					shell->lst.executor[1]);
					return ;
				}
			}
		}
	}
	printf("exit\n");
	exit(1);
}
