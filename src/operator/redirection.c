/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbellucc <vbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:32:54 by mich              #+#    #+#             */
/*   Updated: 2023/04/17 11:34:32 by vbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

void	red_out(int count_redirection, t_shell *shell, \
	int count_delete_str, int j)
{
	int	i;
	int	k;

	if (j != count_redirection)
	{
		k = open(shell->lst.file[0], O_CREAT | \
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		shell->lst.delete_str[count_delete_str] = ft_strdup(shell->lst.file[0]);
		return ;
	}
	else
	{
		i = open(shell->lst.file[0], O_WRONLY | O_CREAT | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		shell->lst.delete_str[count_delete_str] = ft_strdup(shell->lst.file[0]);
		dup2(i, STDOUT_FILENO);
		(void)k;
		return ;
	}
}

void	red_inp(char	*redirection, t_shell *shell)
{
	int	i;

	i = open(redirection, O_RDONLY);
	dup2(i, STDIN_FILENO);
	shell->lst.delete_str[0] = ft_strdup(redirection);
}

void	append(t_shell *shell, int j, \
	int count_redirection, int count_delete_str)
{
	int	i;
	int	k;

	if (j != count_redirection)
	{
		k = open(shell->lst.file[0], O_CREAT | \
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		shell->lst.delete_str[count_delete_str] = ft_strdup(shell->lst.file[0]);
		return ;
	}
	else
	{
		i = open(shell->lst.file[0], O_WRONLY | O_CREAT | O_APPEND,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		shell->lst.delete_str[0] = ft_strdup(shell->lst.file[0]);
		dup2(i, STDOUT_FILENO);
		(void)k;
		return ;
	}
}

void	here_doc(char *redirection, t_shell *shell)
{
	int		i;

	if (shell->here_pipe == 1 || shell->check_mix_red == 1)
		dup2(shell->stdout, STDOUT_FILENO);
	while (1)
	{
		shell->lst.doc = readline("> ");
		i = -1;
		while (redirection[++i])
			;
		ctrl_d(shell);
		if (shell->check_signal_d == 1)
			break ;
		if (ft_strncmp(redirection, shell->lst.doc, i + 1) == 0)
			break ;
		free(shell->lst.doc);
		shell->lst.doc = NULL;
	}
	free(shell->lst.doc);
	shell->lst.doc = NULL;
	if (shell->here_pipe == 1)
		dup2(shell->out_pipe, STDOUT_FILENO);
	if (shell->check_mix_red == 1)
	{
		dup2(shell->redirection_out, STDOUT_FILENO);
		return ;
	}
	shell->lst.delete_str[0] = ft_strdup(redirection);
	if (shell->check_signal_d == 1)
	{
		free(shell->lst.doc);
		shell->lst.doc = NULL;
		printf("warning: here-document delimited by end-of-file\n");
		return ;
	}
}

void	here_doc_cat(char *redirection, t_shell *shell)
{
	int	i;
	int	j;

	shell->lst.cat_array = (char **)malloc(sizeof(char *) * 40000);
	shell->here_cat = 1;
	j = 0;
	if (shell->here_pipe == 1)
		dup2(shell->stdout, STDOUT_FILENO);
	while (1)
	{
		shell->lst.doc = readline("> ");
		i = -1;
		while (redirection[++i])
			;
		ctrl_d(shell);
		if (shell->check_signal_d == 1)
			break ;
		if (ft_strncmp(redirection, shell->lst.doc, i + 1) == 0)
			break ;
		shell->lst.cat_array[j] = ft_strdup(shell->lst.doc);
		j++;
		free(shell->lst.doc);
		shell->lst.doc = NULL;
	}
	shell->lst.cat_array[j] = NULL;
	j = -1;
	if (shell->here_pipe == 1)
		dup2(shell->out_pipe, STDOUT_FILENO);
	if (shell->check_mix_red == 1)
	{
		free(shell->lst.doc);
		shell->lst.doc = NULL;
		return ;
	}
	while (shell->lst.cat_array[++j])
		printf("%s\n", shell->lst.cat_array[j]);
	if (shell->check_signal_d == 1)
	{
		ft_sarfree(shell->lst.cat_array, ft_sarsize(shell->lst.cat_array));
		free(shell->lst.doc);
		shell->lst.doc = NULL;
		shell->here_cat = 1;
		printf("warning: here-document delimited by end-of-file\n");
		return ;
	}
	free(shell->lst.doc);
	shell->lst.doc = NULL;
	ft_sarfree(shell->lst.cat_array, ft_sarsize(shell->lst.cat_array));
	shell->check_signal_d = 0;
}
