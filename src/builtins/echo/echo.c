/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:10:40 by mich              #+#    #+#             */
/*   Updated: 2023/02/01 15:11:34 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "echo.h"

void	short_echo(char **argv, t_shell shell)
{
	while (argv[shell.echo.i])
	{
		printf("%s\n", argv[shell.echo.i]);
		shell.echo.i++;
	}
}

void	ft_echo(int argc, char **argv, t_shell shell)
{
	shell.echo.i = 2;
	shell.echo.j = 0;
	while (shell.echo.j < 1)
	{
		if (argc == 2)
			printf("\n");
		else if (strncmp(argv[shell.echo.i], "-n", 3) == 0)
		{
			shell.echo.i++;
			while ((strncmp(argv[shell.echo.i], "-n", 3) == 0))
					shell.echo.i++;
			while (argv[shell.echo.i])
			{
				printf("%s", argv[shell.echo.i]);
				shell.echo.i++;
			}
		}
		else
		{
			short_echo(argv, shell);
		}
		shell.echo.j++;
	}
}
