/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:17:48 by mich              #+#    #+#             */
/*   Updated: 2023/02/20 11:54:53 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

void	redirection(int c, t_shell *shell)
{
	shell->lst.redirection = split_redirection(shell->lst.input);
	shell->lst.file = ft_split(shell->lst.redirection[1], ' ');
	if (c == 1)
		red_out(shell->lst.file[0]);
	else if (c == 2)
		red_inp(shell->lst.file[0]);
	else if (c == 3)
		append(shell->lst.file[0]);
	else if (c == 4)
		here_doc(shell->lst.file[0], shell);
	delete_op(shell);
	executor(shell);
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
	return(c);
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
	if (ft_strncmp(shell->lst.input, "$?", 2))
	{
		
	}
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

	i = -1;
	q = -1;
	q = clean_quote(shell, i);
	if (q == 0 || q == 3)
		executor(shell);
	else if (q == 1 || q == 4 || q == -1)
	{
		if (!control_pipe(shell))
			check_red(shell->lst.input, shell, i);
		executor(shell);
	}
	return (0);
}
