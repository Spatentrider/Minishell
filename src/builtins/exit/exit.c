/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:17:02 by mich              #+#    #+#             */
/*   Updated: 2023/04/15 15:02:43 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

void	printf_error(t_shell *shell)
{
	if (isdigit(shell->lst.executor[1][k]) == 0)
	{
		if (shell->lst.executor[2] == NULL)
		{
			printf("exit\n");
			printf("minishell: exit: %s: numeric argument required\n", \
			shell->lst.executor[1]);
			free_struct(shell);
			exit(1);
		}
	}
}

void	ft_exit(t_shell *shell)
{
	int	k;

	k = -1;
	if (shell->lst.executor[1] != NULL && shell->lst.executor[2] != NULL)
	{
		printf("exit\nminishell: exit: too many arguments\n");
		return ;
	}
	if (shell->lst.executor[1] != NULL)
	{
		while (shell->lst.executor[1][++k])
			printf_error(shell);
		printf("exit\n");
		k = ft_atoi(shell->lst.executor[1]);
		free_struct(shell);
		exit(k);
	}
	printf("exit\n");
	free_struct(shell);
	exit(shell->old_g_exit);
}
