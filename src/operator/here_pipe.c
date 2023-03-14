/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:02:05 by mich              #+#    #+#             */
/*   Updated: 2023/03/14 16:23:49 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

void	heredoc(char *redirection, t_shell *shell)
{
	int		i;

	while (1)
	{
		shell->lst.doc = readline("> ");
		i = -1;
		while (redirection[++i])
			;
		if (ft_strncmp(redirection, shell->lst.doc, i + 1) == 0)
			break ;
		free(shell->lst.doc);
		shell->lst.doc = NULL;
	}
	dup2(shell->out_pipe, STDOUT_FILENO);
	free(shell->lst.doc);
	shell->lst.doc = NULL;
}

void	heredoc_cat(char *redirection, t_shell *shell)
{
	int	i;
	int	j;

	shell->lst.cat_array = (char **)malloc(sizeof(char *) * 40000);
	j = 0;
	while (1)
	{
		shell->lst.doc = readline("> ");
		i = -1;
		while (redirection[++i])
			;
		if (ft_strncmp(redirection, shell->lst.doc, i + 1) == 0)
			break ;
		shell->lst.cat_array[j] = ft_strdup(shell->lst.doc);
		j++;
		free(shell->lst.doc);
		shell->lst.doc = NULL;
	}
	shell->lst.cat_array[j] = NULL;
	dup2(shell->out_pipe, STDOUT_FILENO);
	j = -1;
	while (shell->lst.cat_array[++j])
		printf("%s\n", shell->lst.cat_array[j]);
	free(shell->lst.doc);
	shell->lst.doc = NULL;
}

int	spec_here_doc(t_shell *shell, int c)
{
	dup2(shell->stdout, STDOUT_FILENO);
	if (shell->lst.here_doc[1] == NULL)
	{
		heredoc_cat(shell->lst.file[0], shell);
		return (1);
	}
	else if (c == 4)
	{
		heredoc(shell->lst.file[0], shell);
		return (1);
	}
	return (0);
}
