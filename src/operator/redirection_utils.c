/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbellucc <vbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:26:34 by vbellucc          #+#    #+#             */
/*   Updated: 2023/04/17 12:46:40 by vbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

int	print_here_doc(t_shell *shell, char *redirection)
{
	free(shell->lst.doc);
	shell->lst.doc = NULL;
	if (shell->here_pipe == 1)
		dup2(shell->out_pipe, STDOUT_FILENO);
	if (shell->check_mix_red == 1)
	{
		dup2(shell->redirection_out, STDOUT_FILENO);
		return (1);
	}
	shell->lst.delete_str[0] = ft_strdup(redirection);
	if (shell->check_signal_d == 1)
	{
		free(shell->lst.doc);
		shell->lst.doc = NULL;
		printf("warning: here-document delimited by end-of-file\n");
		return (1);
	}
	return (0);
}

int	print_heredoc_cat(t_shell *shell, int j)
{
	shell->lst.cat_array[j] = NULL;
	j = -1;
	if (shell->here_pipe == 1)
		dup2(shell->out_pipe, STDOUT_FILENO);
	if (shell->check_mix_red == 1)
	{
		free(shell->lst.doc);
		shell->lst.doc = NULL;
		return (1);
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
		return (1);
	}
	free(shell->lst.doc);
	shell->lst.doc = NULL;
	shell->check_signal_d = 0;
	return (0);
}
