/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:26:49 by mich              #+#    #+#             */
/*   Updated: 2023/04/17 15:28:56 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

int ft_strtok_loop(char *next_token,const char *delim, t_shell *shell)
{
	int match;

	match = 1;
	while(++shell->strtok.i < shell->strtok.delim_len) 
		{
			if (*next_token == delim[shell->strtok.i]) 
			{
				match = 0;
				break;
			}
		}
	return(match);
}

char *ft_strtok(char *str, const char *delim, t_shell *shell) 
{
	static char *next_token;

	next_token = NULL;
	if (str != NULL) 
		next_token = str;
	else if (next_token == NULL) 
		return NULL;
	shell->strtok.result = next_token; 
	shell->strtok.delim_len = strlen(delim);
	while (*next_token != '\0') 
	{
		shell->strtok.i = -1;
		shell->strtok.match = ft_strtok_loop(next_token, delim, shell);
		if (shell->strtok.match) 
			next_token++;
		else 
		{
			*next_token = '\0';
			next_token++;
			return shell->strtok.result;
		}
	}
	next_token = NULL;
	return shell->strtok.result;
}

void	control_double_redirection(t_shell *shell)
{
	if (ft_strncmp(shell->redirection.token, ">>", 2) == 0)
	{
		printf("quo\n");
		shell->redirection.token = ft_strtok(NULL, " ", shell);
		shell->lst.delete_str[shell->redirection.i] = \
			ft_strdup(shell->redirection.token);
		shell->redirection.fd = open(shell->redirection.token, \
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (shell->redirection.fd < 0)
			printf("Error opening file\n");
		dup2(shell->redirection.fd, STDOUT_FILENO);
		shell->redirection_out = dup(STDOUT_FILENO);
		close(shell->redirection.fd);
		shell->redirection.i++;
	}
	else if (ft_strncmp(shell->redirection.token, "<<", 2) == 0)
	{
		shell->redirection.token = ft_strtok(NULL, " ", shell);
		shell->lst.delete_str[shell->redirection.i] = \
			ft_strdup(shell->redirection.token);
		if (shell->redirection.flag == 2)
			here_doc(shell->redirection.token, shell);
		else
			here_doc_cat(shell->redirection.token, shell);
		shell->redirection.i++;
	}
}

void	control_redirection(t_shell *shell)
{
	if (ft_strncmp(shell->redirection.token, "<", 1) == 0)
	{
		printf("qui\n");
		shell->redirection.token = ft_strtok(NULL, " ", shell);
		shell->lst.delete_str[shell->redirection.i] = \
			ft_strdup(shell->redirection.token);
		shell->redirection.fd = open(shell->redirection.token, O_RDONLY);
		if (shell->redirection.fd < 0)
			printf("Error opening file\n");
		dup2(shell->redirection.fd, STDIN_FILENO);
		close(shell->redirection.fd);
		shell->redirection.i++;
	}
	else if (ft_strncmp(shell->redirection.token, ">", 1) == 0)
	{
		shell->redirection.token = ft_strtok(NULL, " ", shell);
		shell->lst.delete_str[shell->redirection.i] = \
			ft_strdup(shell->redirection.token);
		shell->redirection.fd = open(shell->redirection.token, \
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (shell->redirection.fd < 0)
			printf("Error opening file\n");
		dup2(shell->redirection.fd, STDOUT_FILENO);
		print_cat_array(shell);
	}
	control_double_redirection(shell);
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
		// printf("%s\n", shell->redirection.token);
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
	if (shell->redirection.flag != 3)
		executor(shell);
}
