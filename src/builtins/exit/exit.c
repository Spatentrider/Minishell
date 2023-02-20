/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:17:02 by mich              #+#    #+#             */
/*   Updated: 2023/02/20 17:54:40 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

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
				printf("exit\n");
				exit(printf("minishell: exit: %s: numeric argument required\n", \
					shell->lst.executor[1]));
			}
		}
	}
	exit(printf("exit\n"));
}

void	ft_exit(char **current, t_shell *shell)
{
	int		i;

	i = -1;
	while (current[++i])
	{
		if (strncmp(current[i], "SHLVL=3", 7) == 0)
			nor_exit(shell);
	}
}

// int		j;
// j = -1;
// j = current[i][6] - '0';
// j--;
// j += '0';
// current[i][6] = j;
