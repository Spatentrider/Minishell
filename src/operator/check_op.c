/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzodimascia <lorenzodimascia@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:17:48 by mich              #+#    #+#             */
/*   Updated: 2023/03/30 16:18:30 by lorenzodima      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

void	redirection(t_shell *shell)
{
	int count_redirection;
	int count_delete_str;
	int j;

	count_delete_str = 0;
	shell->red_pos = -1;
	shell->lst.redirection = split_redirection(shell->lst.input);
	count_redirection = ft_sarsize(shell->lst.redirection) - 1;
	j = count_redirection;
	shell->lst.here_doc = ft_split(shell->lst.redirection[0], ' ');
	while(shell->redirection_id[++shell->red_pos])
	{
		count_redirection = ft_sarsize(shell->lst.redirection) - 1;
		j = count_redirection;
		if (shell->redirection_id[shell->red_pos] == 1)
		{
			shell->lst.delete_str = (char **)malloc(sizeof(char *) * (count_redirection + 1));
			while (count_redirection > 0)
			{
				shell->lst.file = ft_split(shell->lst.redirection[count_redirection], ' ');
				red_out(shell->lst.file[0], count_redirection, shell, count_delete_str, j);
				count_redirection--;
				count_delete_str++;
				ft_sarfree(shell->lst.file, ft_sarsize(shell->lst.file));
			}
			shell->lst.delete_str[count_delete_str] = NULL;
		}
		else if (shell->redirection_id[shell->red_pos] == 2)
		{
			shell->lst.delete_str = (char **)malloc(sizeof(char *) * (count_redirection + 1));
			shell->lst.file = ft_split(shell->lst.redirection[count_redirection], ' ');
			red_inp(shell->lst.file[0], shell);
			ft_sarfree(shell->lst.file, ft_sarsize(shell->lst.file));	
			shell->lst.delete_str[1] = NULL;
		}
		else if (shell->redirection_id[shell->red_pos] == 3)
		{
			shell->lst.delete_str = (char **)malloc(sizeof(char *) * (count_redirection + 1));
			shell->lst.file = ft_split(shell->lst.redirection[count_redirection], ' ');
			append(shell->lst.file[0], shell);
			ft_sarfree(shell->lst.file, ft_sarsize(shell->lst.file));
			shell->lst.delete_str[1] = NULL;
		}
		else if (shell->lst.here_doc[1] == NULL)
		{
			shell->lst.delete_str = (char **)malloc(sizeof(char *) * (count_redirection + 1));
			shell->lst.file = ft_split(shell->lst.redirection[count_redirection], ' ');
			here_doc_cat(shell->lst.file[0], shell);
			ft_sarfree(shell->lst.redirection, ft_sarsize(shell->lst.redirection));
			ft_sarfree(shell->lst.here_doc, ft_sarsize(shell->lst.here_doc));
			ft_sarfree(shell->lst.file, ft_sarsize(shell->lst.file));
			shell->lst.delete_str[1] = NULL;
			return ;
		}
		else if (shell->redirection_id[shell->red_pos] == 4)
		{
			shell->lst.delete_str = (char **)malloc(sizeof(char *) * (count_redirection + 1));
			shell->lst.file = ft_split(shell->lst.redirection[count_redirection], ' ');	
			here_doc(shell->lst.file[0], shell);
			ft_sarfree(shell->lst.file, ft_sarsize(shell->lst.file));
			shell->lst.delete_str[1] = NULL;
		}
	}
	delete_op(shell);
	executor(shell);
	ft_sarfree(shell->lst.here_doc, ft_sarsize(shell->lst.here_doc));
	ft_sarfree(shell->lst.redirection, ft_sarsize(shell->lst.redirection));
}

int	check_red(char *input, t_shell *shell, int i)
{
	i = -1;
	int k;

	k = 0;
	shell->redirection_id = malloc(sizeof(int) * 40);
	shell->redirection_id[0] = 0;
	while (input[++i])
	{
		if (input[i] == '<' && input[i + 1] == '<')
		{
			shell->redirection_id[k] = 4;
			i++;
		}
		else if (input[i] == '>' && input[i + 1] == '>')
		{
			shell->redirection_id[k] = 4;
			i++;
		}
		else if (input[i] == '<' && input[i + 1] != '<')
			shell->redirection_id[k] = 2;
		else if (input[i] == '>' && input[i + 1] != '>')
			shell->redirection_id[k] = 1;
		k++;
	}
	if (shell->redirection_id[0] > 0)
		redirection(shell);
	free(shell->redirection_id);
	return (shell->redirection_id[0]);
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
