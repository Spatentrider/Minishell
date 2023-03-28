/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:17:48 by mich              #+#    #+#             */
/*   Updated: 2023/03/16 15:46:13 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

void	redirection(int c, t_shell *shell)
{
	int count_redirection;
	int count_delete_str;

	count_delete_str = 0;
	shell->lst.redirection = split_redirection(shell->lst.input);
	count_redirection = ft_sarsize(shell->lst.redirection) - 1;
	shell->lst.here_doc = ft_split(shell->lst.redirection[0], ' ');
	if (c == 1)
	{
		shell->lst.delete_str = (char **)malloc(sizeof(char *) * (count_redirection + 1));
		while (count_redirection > 0)
		{
			shell->lst.file = ft_split(shell->lst.redirection[count_redirection], ' ');
			red_out(shell->lst.file[0], count_redirection, shell, count_delete_str);
			count_redirection--;
			count_delete_str++;
			ft_sarfree(shell->lst.file, ft_sarsize(shell->lst.file));
		}
		shell->lst.delete_str[count_delete_str] = NULL;
		ft_sarprint(shell->lst.delete_str);
	}
	else if (c == 2)
		red_inp(shell->lst.file[0]);
	else if (c == 3)
		append(shell->lst.file[0]);
	else if (shell->lst.here_doc[1] == NULL)
	{
		here_doc_cat(shell->lst.file[0], shell);
		ft_sarfree(shell->lst.redirection, ft_sarsize(shell->lst.redirection));
		ft_sarfree(shell->lst.here_doc, ft_sarsize(shell->lst.here_doc));
		return ;
	}
	else if (c == 4)
		here_doc(shell->lst.file[0], shell);
	delete_op(shell);
	executor(shell);
	ft_sarfree(shell->lst.here_doc, ft_sarsize(shell->lst.here_doc));
	ft_sarfree(shell->lst.redirection, ft_sarsize(shell->lst.redirection));
}

int	check_red(char *input, t_shell *shell, int i)
{
	int	c;

	i = -1;
	c = 0;
	while (input[++i])
	{
		if (input[i] == '<' && input[i + 1] == '<')
		{
			c = 4;
			break ;
		}
		else if (input[i] == '>' && input[i + 1] == '>')
		{
			c = 3;
			break ;
		}
		else if (input[i] == '<')
			c = 2;
		else if (input[i] == '>')
			c = 1;
	}
	if (c > 0)
		redirection(c, shell);
	return (c);
}

int	check_operator(t_shell *shell)
{
	int	q;
	int	i;
	int	c;

	i = -1;
	q = clean_quote(shell, i);
	c = -1;
	if (q == 0 || q == 3)
	{
		clean_parse(shell);
		executor(shell);
	}
	else if (q == 1 || q == 4 || q == -1)
	{
		if (!control_pipe(shell))
			c = check_red(shell->lst.input, shell, i);
		if (c == 0)
		{
			clean_parse(shell);
			executor(shell);
		}
	}
	return (0);
}
