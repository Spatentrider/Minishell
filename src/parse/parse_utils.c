/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:44:24 by mich              #+#    #+#             */
/*   Updated: 2023/04/15 13:09:47 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	control(char *string)
{
	int	i;

	i = ft_strlen(string);
	if (i == 2)
	{
		if ((string[0] == 34 && string[1] == 34)
			|| (string[0] == 39 && string[1] == 39))
		{
			printf("Command %s not found\n", string);
			g_exit = 127;
		}
	}
	return (g_exit);
}

int	check_pipe(char *string)
{
	size_t	i;

	i = ft_strlen(string);
	if (i > 1)
	{
		printf("minishell: double pipe is not allowed\n");
		g_exit = 2;
	}
	return (g_exit);
}

void	check_2_red(t_shell *shell, char *string)
{
	if (shell->check_redirection == 0)
	{
		shell->check_redirection = 1;
		if (is_red(string[1]) == 0 || is_red(string[2]) == 0)
			shell->check_redirection = 0;
	}
	else
	{
		printf("minishell: syntax error near unexpected token redirection\n");
		return (g_exit = 2);
	}
}
