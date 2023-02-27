/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:32:54 by mich              #+#    #+#             */
/*   Updated: 2023/02/27 15:31:46 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

void	red_out(char *redirection)
{
	int	i;

	i = open(redirection, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	dup2(i, STDOUT_FILENO);
}

void	red_inp(char	*redirection)
{
	int	i;

	i = open(redirection, O_RDONLY);
	dup2(i, STDIN_FILENO);
}

void	append(char *redirection)
{
	int	i;

	i = open(redirection, O_WRONLY | O_CREAT | O_APPEND,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	dup2(i, STDOUT_FILENO);
}

void	here_doc(char *redirection, t_shell *shell)
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
	free(shell->lst.doc);
	shell->lst.doc = NULL;
}

void	here_doc_cat(char *redirection, t_shell *shell)
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
	j = -1;
	while (shell->lst.cat_array[++j])
		printf("%s\n", shell->lst.cat_array[j]);
	free(shell->lst.doc);
	shell->lst.doc = NULL;
}
