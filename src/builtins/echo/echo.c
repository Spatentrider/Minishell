/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:10:40 by mich              #+#    #+#             */
/*   Updated: 2023/04/20 11:24:51 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "echo.h"

void	short_echo(t_shell *shell)
{
	while (shell->lst.executor[shell->echo.i])
	{
		shell->exp.i = -1;
		while (shell->lst.executor[shell->echo.i][++shell->exp.i])
		{
			if (shell->lst.executor[shell->echo.i][shell->exp.i] == '~')
					shell->lst.executor[shell->echo.i][shell->exp.i] = ' ';
			if (shell->lst.executor[shell->echo.i][shell->exp.i] == '\a')
					shell->lst.executor[shell->echo.i][shell->exp.i] = ' ';
		}
		printf("%s", shell->lst.executor[shell->echo.i]);
		if (shell->lst.executor[shell->echo.i + 1] != NULL)
			printf(" ");
		shell->echo.i++;
	}
	printf("\n");
}

void	print(t_shell *shell)
{
	while (shell->lst.executor[shell->echo.i])
	{
		shell->exp.i = -1;
		while (shell->lst.executor[shell->echo.i][++shell->exp.i])
		{
			if (shell->lst.executor[shell->echo.i][shell->exp.i] == '~')
					shell->lst.executor[shell->echo.i][shell->exp.i] = ' ';
			if (shell->lst.executor[shell->echo.i][shell->exp.i] == '\a')
					shell->lst.executor[shell->echo.i][shell->exp.i] = ' ';
		}
		printf("%s", shell->lst.executor[shell->echo.i]);
		if (shell->lst.executor[shell->echo.i + 1] == NULL)
			break ;
		if (shell->lst.executor[shell->echo.i + 1] != NULL)
			printf(" ");
		shell->echo.i++;
	}
}

int	ft_echo(t_shell *shell)
{
	shell->echo.i = 1;
	shell->echo.j = 0;
	if (shell->lst.executor[1] == NULL)
		printf("\n");
	else if (strncmp(shell->lst.executor[shell->echo.i], "-n", 3) == 0)
	{
		shell->echo.i++;
		if (shell->lst.executor[shell->echo.i] == NULL)
			return (0);
		while ((strncmp(shell->lst.executor[shell->echo.i], "-n", 3) == 0))
		{
			if (shell->lst.executor[shell->echo.i + 1] == NULL)
				break ;
			shell->echo.i++;
		}
		print(shell);
	}
	else
		short_echo(shell);
	return (0);
}
