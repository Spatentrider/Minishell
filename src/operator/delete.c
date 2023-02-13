/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:28:13 by mvolpi            #+#    #+#             */
/*   Updated: 2023/02/13 12:20:50 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

int	is_sep(char c)
{
	if (c == '\0')
		return (1);
	else if (c == 34)
		return (2);
	else if (c == 39)
		return (3);
	return (0);
}

void	delete_qt(t_shell *shell)
{
	int	i;

	i = -1;
	while (shell->lst.input[++i])
	{
		if (is_separator(shell->lst.input[i]) == -1)
			shell->lst.input[i] = ' ';
	}
}

int	clean_quote(t_shell *shell)
{
	int	i;
	int	q;
	int	d;
	int	s;

	i = -1;
	q = 0;
	d = 0;
	s = 0;
	while (shell->lst.input[++i])
	{
		if (is_sep(shell->lst.input[i]) > 1)
		{
			while (is_sep(shell->lst.input[i]) > 1)
			{
				while (is_sep(shell->lst.input[i]) == 2)
				{
					d++;
					i++;
				}
				while (is_sep(shell->lst.input[i]) == 3)
				{
					s++;
					i++;
				}
				i++;
			}
			break ;
		}
	}
	if (d > 0)
	{
		if (s == 0)
			delete_qt(shell);
		return (0);
	}
	if (s > 0)
	{
		if (d == 0)
			delete_qt(shell);
		return (0);
	}
	q = d + s;
	
	return (q);
}

void	delete_op(t_shell *shell)
{
	int	i;

	i = -1;
	while (shell->lst.input[++i])
	{
		if (is_separator(shell->lst.input[i]) > 1)
			shell->lst.input[i] = ' ';
		while (is_separator(shell->lst.input[i]) == -1)
			shell->lst.input[i] = ' ';
	}
}
