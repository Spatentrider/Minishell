/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbellucc <vbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:15:50 by vbellucc          #+#    #+#             */
/*   Updated: 2023/04/20 10:29:41 by vbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

void	go_here_doc_cat(t_shell *shell)
{
	shell->lst.file = \
		ft_split(shell->lst.redirection[shell->red.count_redirection], ' ');
	here_doc_cat(shell->lst.file[0], shell);
	ft_sarfree(shell->lst.redirection, \
		ft_sarsize(shell->lst.redirection));
	ft_sarfree(shell->lst.here_doc, ft_sarsize(shell->lst.here_doc));
	ft_sarfree(shell->lst.file, ft_sarsize(shell->lst.file));
}

void	go_here_doc(t_shell *shell)
{
	shell->lst.delete_str = (char **)malloc(sizeof(char *) \
		* (shell->red.count_redirection + 1));
	shell->lst.file = \
		ft_split(shell->lst.redirection[shell->red.count_redirection], ' ');
	here_doc(shell->lst.file[0], shell);
	ft_sarfree(shell->lst.file, ft_sarsize(shell->lst.file));
	shell->lst.delete_str[1] = NULL;
}

void	go_append(t_shell *shell)
{
	shell->lst.delete_str = (char **)malloc(sizeof(char *) \
		* (shell->red.count_redirection + 1));
	while (shell->red.count_redirection > 0)
	{
		shell->lst.file = \
			ft_split(shell->lst.redirection[shell->red.count_redirection], ' ');
		append(shell, shell->red.j, shell->red.count_redirection, \
			shell->red.count_delete_str);
		shell->red.count_redirection--;
		shell->red.count_delete_str++;
		ft_sarfree(shell->lst.file, ft_sarsize(shell->lst.file));
	}
	shell->lst.delete_str[shell->red.count_delete_str] = NULL;
}

void	go_output(t_shell *shell)
{
	shell->lst.delete_str = (char **)malloc(sizeof(char *) \
		* (shell->red.count_redirection + 1));
	shell->lst.file = \
		ft_split(shell->lst.redirection[shell->red.count_redirection], ' ');
	red_inp(shell->lst.file[0], shell);
	ft_sarfree(shell->lst.file, ft_sarsize(shell->lst.file));
	shell->lst.delete_str[1] = NULL;
}

void	go_input(t_shell *shell)
{
	shell->lst.delete_str = (char **)malloc(sizeof(char *) \
		* (shell->red.count_redirection + 1));
	while (shell->red.count_redirection > 0)
	{
		shell->lst.file = \
			ft_split(shell->lst.redirection[shell->red.count_redirection], ' ');
		red_out(shell->red.count_redirection, shell, \
			shell->red.count_delete_str, shell->red.j);
		shell->red.count_redirection--;
		shell->red.count_delete_str++;
		ft_sarfree(shell->lst.file, ft_sarsize(shell->lst.file));
	}
	shell->lst.delete_str[shell->red.count_delete_str] = NULL;
}
