/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:17:48 by mich              #+#    #+#             */
/*   Updated: 2023/02/14 16:51:01 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

void	redirection(char **redirection, int c, t_shell *shell)
{
	shell->lst.file = ft_split(redirection[1], ' ');
	if (c == 1)
		red_out(shell->lst.file[0]);
	else if (c == 2)
		red_inp(shell->lst.file[0]);
	else if (c == 3)
		append(shell->lst.file[0]);
	else if (c == 4)
		here_doc(shell->lst.file[0], shell);
}

int	check_red(char *input)
{
	int	i;
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
	return (c);
}

void	expansion(t_shell *shell, int p)
{
	int		i;
	int		j;
	int		pos;
	char	*str;

	i = -1;
	j = 0;
	str = (char *)malloc(sizeof(char) * 100);
	while (shell->lst.expansion[p][++j])
		str[++i] = shell->lst.expansion[p][j];
	str[++i] = '\0';
	i = -1;
	while (shell->env.current[++i])
	{
		pos = ft_strchrp(shell->env.current[i], '=');
		if (ft_strncmp(shell->env.current[i], str, pos) == 0)
			change_word(shell, i, pos);
	}
}

void	control_exp(t_shell *shell)
{
	int	i;

	i = -1;
	shell->lst.expansion = split_executor(shell->lst.split[0]);
	while (shell->lst.expansion[++i])
	{
		if (ft_strncmp(shell->lst.expansion[i], "$", 1) == 0)
			expansion(shell, i);
	}
}

int	check_operator(t_shell *shell)
{
	int	i;
	int	q;
	int	c;

	i = -1;
	q = -1;
	control_exp(shell);
	q = clean_quote(shell, i);
	if (q == 0 || q == 3)
		executor(shell);
	else if (q == 1 || q == 4)
	{
		c = check_red(shell->lst.input);
		if (c > 0)
		{
			shell->lst.redirection = split_redirection(shell->lst.input);
			redirection(shell->lst.redirection, c, shell);
		}
		delete_op(shell);
		executor(shell);
	}
	return (0);
}

// shell->lst.pipe = split_pipe(shell->lst.input);
// if (shell->lst.pipe[1] != NULL)
// 	ft_pipe();
