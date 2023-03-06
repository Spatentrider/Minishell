/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:17:02 by mich              #+#    #+#             */
/*   Updated: 2023/03/06 15:57:11 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

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
		printf("exit\n");
		exit(ft_atoi(shell->lst.executor[1]));
	}
	printf("exit\n");
	exit(shell->old_g_exit);
}
