/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:10:40 by mich              #+#    #+#             */
/*   Updated: 2023/02/09 17:01:41 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "echo.h"

void	short_echo(t_shell *shell)
{
	while (shell->lst.executor[shell->echo.i])
	{
		printf("%s", shell->lst.executor[shell->echo.i]);
		if (shell->lst.executor[shell->echo.i + 1] != NULL)
			printf(" ");
		shell->echo.i++;
	}
	printf("\n");
}

void	ft_echo(t_shell *shell)
{
	shell->echo.i = 1;
	shell->echo.j = 0;
	while (shell->echo.j < 1)
	{
		if (strncmp(shell->lst.executor[shell->echo.i], "-n", 3) == 0)
		{
			shell->echo.i++;
			while ((strncmp(shell->lst.executor[shell->echo.i], "-n", 3) == 0))
					shell->echo.i++;
			while (shell->lst.executor[shell->echo.i])
			{
				printf("%s ", shell->lst.executor[shell->echo.i]);
				shell->echo.i++;
			}
		}
		else
			short_echo(shell);
		shell->echo.j++;
	}
}
