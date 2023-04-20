/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:44:24 by mich              #+#    #+#             */
/*   Updated: 2023/04/20 16:05:38 by mvolpi           ###   ########.fr       */
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

int	check_pipe(char *string, t_shell *shell)
{
	int		k;

	k = 0;
	shell->pipe = 1;
	g_exit = check_2_red(shell, string);
	if (string[k] == string[k +1])
	{
		printf("minishell: double pipe is not allowed\n");
		g_exit = 2;
	}	
	return (g_exit);
}

int	not_red(char c)
{
	if (c >= 65 && c <= 90)
		return (1);
	if (c >= 97 && c <= 122)
		return (1);
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	check_2_red(t_shell *shell, char *string)
{
	int	i;

	if (shell->check_redirection == 0)
	{
		shell->check_redirection = 1;
		i = ft_strlen(string);
		if (i > 1)
		{
			if (not_red(string[1]) == 1 || not_red(string[2]) == 1)
				shell->check_redirection = 0;
		}
	}
	else
	{
		if (shell->pipe == 1)
			printf("minishell: syntax error near unexpected token pipe\n");
		else
			printf("minishell: syntax error near \
				unexpected token redirection\n");
		return (g_exit = 2);
	}
	return (0);
}

int	control_string(char *string)
{
	if (string[0] == '|')
	{
		printf("minishell: syntax error near unexpected token `|'\n");
		return (g_exit = 258);
	}
	else if (string[0] == '<')
	{
		printf("minishell: syntax error near unexpected token `<'\n");
		return (g_exit = 2);
	}
	else if (string[0] == '>')
	{
		printf("minishell: syntax error near unexpected token `>'\n");
		return (g_exit = 2);
	}
	return (g_exit);
}
