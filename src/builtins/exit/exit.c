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

void inside_exit(t_shell *shell)
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
				printf("exit\n");
				exit(printf("minishell: exit: %s: numeric argument required\n", \
					shell->lst.executor[1]));
			}
		}
	}
}

void	nor_exit(t_shell *shell)
{
	int	k;

	k = -1;
	if (shell->lst.executor[1] != NULL)
	{
		while (shell->lst.executor[1][++k])
		{
			if (isdigit(shell->lst.executor[1][k]) == 0)
			{
				printf("exit\nminishell: exit: %s: numeric argument required\n", \
					shell->lst.executor[1]);
				exit(2);
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

void	ft_exit(char **current, t_shell *shell)
{
	int		i;

	i = -1;
	while (current[++i])
	{
		//if (strncmp(current[i], "SHLVL=3", 7) == 0)
			nor_exit(shell);
		//else if (strncmp(current[i], "SHLVL=", 6) == 0)
		//	reduce_shlvl(shell);
	}
}
