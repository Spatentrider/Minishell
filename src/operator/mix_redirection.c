/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:26:49 by mich              #+#    #+#             */
/*   Updated: 2023/04/17 10:26:49 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "operator.h"

int	ft_strtok_loop(char *next_token, const char *delim, t_shell *shell)
{
	int	match,

	match = 1;
	while (++shell->strtok.i < shell->strtok.delim_len)
	{
		if (*next_token == delim[shell->strtok.i])
		{
			match = 0;
			break ;
		}
	}
	return (match);
}

void	*ft_strtok(char *str, const char *delim, t_shell *shell)
{
	static char	*next_token;

	next_token = NULL;
	if (str != NULL)
		next_token = str;
	else if (next_token == NULL)
		return (NULL);
	shell->strtok.result = next_token;
	shell->strtok.delim_len = ft_strlen(delim);
	while (*next_token != '\0')
	{
		shell->strtok.i = 1;
		shell->strtok.match = ft_strtok_loop(next_token, delim, shell);
		if (shell->strtok.match)
			next_token++;
		else
		{
			*next_token = '\0';
			next_token++;
			return (shell->strtok.result);
		}
	}
	next_token = NULL;
	return (shell->strtok.result);
}

void	control_redirection(t_shell *shell)
{
	if (strcmp(shell->redirection.token, "<") == 0)
	{
		shell->redirection.token = ft_strtok(NULL, " ", shell);
		shell->lst.delete_str[shell->redirection.i] = \
			ft_strdup(shell->redirection.token);
		shell->redirection.fd = open(shell->redirection.token, O_RDONLY);
		if (shell->redirection.fd < 0)
			printf("Error during open file\n");
		dup2(shell->redirection.fd, STDIN_FILENO);
		close(shell->redirection.fd);
		shell->redirection.i++;
	}
}

void	mix_redirection(t_shell *shell)
{
	shell->redirection.input = ft_strdup(shell->lst.input);
	shell->redirection.flag = 0;
	shell->redirection.token = ft_strtok(shell->redirection.input, " ", shell);
	if (ft_strncmp(shell->redirection.token, "cat", 4) == 0)
		shell->redirection.flag = 1;
	shell->lst.delete_str = (char **)malloc(sizeof(char *) * 4000);
	shell->redirection.i = 0;
	while (shell->redirection.token != NULL)
	{
		control_redirection(shell);
		shell->redirection.token = ft_strtok(NULL, " ", shell);
		if (shell->redirection.token != NULL)
		{
			if (ft_strncmp(shell->redirection.token, ">", 1) != 0 && \
				ft_strncmp(shell->redirection.token, "<", 1) != 0 && \
				ft_strncmp(shell->redirection.token, ">>", 2) != 0 && \
				ft_strncmp(shell->redirection.token, "<<", 2) != 0)
				shell->redirection.flag = 2;
		}
	}
	shell->lst.delete_str[shell->redirection.i] = NULL;
	free(shell->redirection.input);
	delete_op(shell);
	if (shell->redirection.flag!= 3)
		executor(shell);
}
