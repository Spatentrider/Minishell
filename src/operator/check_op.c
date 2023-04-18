/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:17:48 by mich              #+#    #+#             */
/*   Updated: 2023/04/17 15:22:53 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

void	go_input(t_shell *shell)
{
	if (shell->redirection_id == 1)
	{
		shell->lst.delete_str = (char **)malloc(sizeof(char *) \
			* (shell->red.count_redirection + 1));
		while (shell->red.count_redirection > 0)
		{
			shell->lst.file = \
				ft_split(shell->lst.redirection[shell->red.count_redirection], ' ');
			red_out(shell->red.count_redirection, shell, shell->red.count_delete_str, shell->red.j);
			shell->red.count_redirection--;
			shell->red.count_delete_str++;
			ft_sarfree(shell->lst.file, ft_sarsize(shell->lst.file));
		}
		shell->lst.delete_str[shell->red.count_delete_str] = NULL;
	}
}

void	redirection(t_shell *shell)
{
	shell->lst.redirection = split_redirection(shell->lst.input);
	shell->red.count_redirection = ft_sarsize(shell->lst.redirection) - 1;
	printf("id red e %d\n", shell->redirection_id);
	if (shell->red.count_redirection >= 1)
	{
		shell->red.count_delete_str = 0;
		shell->red.j = shell->red.count_redirection;
		shell->lst.here_doc = ft_split(shell->lst.redirection[0], ' ');
		shell->do_redirection = 1;
		clean_parse(shell);
		exp_red(shell);
		if (shell->redirection_id == 1)
		{
			shell->lst.delete_str = (char **)malloc(sizeof(char *) \
				* (shell->red.count_redirection + 1));
			while (shell->red.count_redirection > 0)
			{
				shell->lst.file = \
					ft_split(shell->lst.redirection[shell->red.count_redirection], ' ');
				red_out(shell->red.count_redirection, shell, shell->red.count_delete_str, shell->red.j);
				shell->red.count_redirection--;
				shell->red.count_delete_str++;
				ft_sarfree(shell->lst.file, ft_sarsize(shell->lst.file));
			}
			shell->lst.delete_str[shell->red.count_delete_str] = NULL;
		}
		else if (shell->redirection_id == 2)
		{
			shell->lst.delete_str = (char **)malloc(sizeof(char *) \
				* (shell->red.count_redirection + 1));
			shell->lst.file = \
				ft_split(shell->lst.redirection[shell->red.count_redirection], ' ');
			red_inp(shell->lst.file[0], shell);
			ft_sarfree(shell->lst.file, ft_sarsize(shell->lst.file));
			shell->lst.delete_str[1] = NULL;
		}
		else if (shell->redirection_id == 3)
		{
			printf("ci sei?\n");
			shell->lst.delete_str = (char **)malloc(sizeof(char *) \
				* (shell->red.count_redirection + 1));
			while (shell->red.count_redirection > 0)
			{
				shell->lst.file = \
					ft_split(shell->lst.redirection[shell->red.count_redirection], ' ');
				append(shell, shell->red.j, shell->red.count_redirection, shell->red.count_delete_str);
				shell->red.count_redirection--;
				shell->red.count_delete_str++;
				ft_sarfree(shell->lst.file, ft_sarsize(shell->lst.file));
			}
			shell->lst.delete_str[shell->red.count_delete_str] = NULL;
		}
		shell->lst.file = \
			ft_split(shell->lst.redirection[shell->red.count_redirection], ' ');
		if ((ft_strncmp(shell->lst.here_doc[1], "<<", 2) == 0 \
			|| ft_strncmp(shell->lst.here_doc[1], shell->lst.file[0], \
			ft_strlen(shell->lst.file[0])) == 0) && \
			ft_strncmp(shell->lst.here_doc[0], "cat", 3) == 0)
		{
			shell->lst.file = \
				ft_split(shell->lst.redirection[shell->red.count_redirection], ' ');
			here_doc_cat(shell->lst.file[0], shell);
			ft_sarfree(shell->lst.redirection, \
				ft_sarsize(shell->lst.redirection));
			ft_sarfree(shell->lst.here_doc, ft_sarsize(shell->lst.here_doc));
			ft_sarfree(shell->lst.file, ft_sarsize(shell->lst.file));
			return ;
		}
		ft_sarfree(shell->lst.file, ft_sarsize(shell->lst.file));
		if (shell->redirection_id == 4)
		{
			shell->lst.delete_str = (char **)malloc(sizeof(char *) \
				* (shell->red.count_redirection + 1));
			shell->lst.file = \
				ft_split(shell->lst.redirection[shell->red.count_redirection], ' ');
			here_doc(shell->lst.file[0], shell);
			ft_sarfree(shell->lst.file, ft_sarsize(shell->lst.file));
			shell->lst.delete_str[1] = NULL;
		}
	}
	if (shell->here_cat == 0 && shell->check_flag == 0)
	{
		delete_op(shell);
		executor(shell);
	}
	ft_sarfree(shell->lst.here_doc, ft_sarsize(shell->lst.here_doc));
	ft_sarfree(shell->lst.redirection, ft_sarsize(shell->lst.redirection));
}

int	check_red(char *input, t_shell *shell, int i)
{
	i = -1;
	shell->redirection_id = 0;
	shell->check_mix_red = 0;
	while (input[++i])
	{
		i = check_double_red(shell, input, i);
		check_single_red(shell, input, i);
	}
	if (shell->redirection_id > 0 && shell->check_mix_red != 1)
		redirection(shell);
	if (shell->check_mix_red == 1)
		mix_redirection(shell);
	return (shell->redirection_id);
}

int	check_operator(t_shell *shell)
{
	int	i;
	int	c;

	i = -1;
	c = -1;
	if (!control_pipe(shell))
		c = check_red(shell->lst.input, shell, i);
	if (c == 0)
	{
		clean_parse(shell);
		executor(shell);
	}
	return (0);
}
