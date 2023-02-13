/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:17:48 by mich              #+#    #+#             */
/*   Updated: 2023/02/13 16:11:16 by mich             ###   ########.fr       */
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

void	expansion(char *expansion, char **current)
{
	int		i;
	int		j;
	int		pos;
	char	*str;

	i = -1;
	j = 0;
	str = (char *)malloc(sizeof(char) * 100);
	while (expansion[++j])
		str[++i] = expansion[j];
	str[++i] = '\0';
	i = -1;
	while (current[++i])
	{
		pos = ft_strchrp(current[i], '=');
		if (ft_strncmp(current[i], str, pos) == 0)
		{
			j = -1;
			while (current[i][++pos])
				expansion[++j] = current[i][pos];
			expansion[++j] = '\0';
		}
	}
}

int	check_operator(t_shell *shell)
{
	int	i;
	int	q;
	int	c;

	i = -1;
	q = -1;
	q = clean_quote(shell);
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
		shell->lst.expansion = split_executor(shell->lst.split[0]);
		while (shell->lst.expansion[++i])
		{
			if (ft_strncmp(shell->lst.expansion[i], "$", 1) == 0)
				expansion(shell->lst.expansion[i], shell->env.current);
		}
		delete_op(shell);
		executor(shell);
	}
	return (0);
}

// shell->lst.pipe = split_pipe(shell->lst.input);
// if (shell->lst.pipe[1] != NULL)
// 	ft_pipe();
