/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:28:13 by mvolpi            #+#    #+#             */
/*   Updated: 2023/04/13 10:24:03 by mvolpi           ###   ########.fr       */
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
	else if (c == ' ')
		return (4);
	return (0);
}

int	control_q(int q, int d)
{
	if ((q % 2) == 0)
	{
		return (3);
	}
	else
	{
		if ((d % 2) == 0)
		{
			return (4);
		}
		else
		{
			return (4);
		}
	}
}

int	control_qt(int q, int d, int s)
{
	if (d > 0)
	{
		if (s == 0)
		{
			if ((d % 2) == 0)
				return (1);
			else
				return (0);
		}
	}
	if (s > 0)
	{
		if (d == 0)
		{
			if ((s % 2) == 0)
				return (1);
			else
				return (0);
		}
	}
	q = d + s;
	q = control_q(q, d);
	return (q);
}

int	cont_quote(t_shell *shell, int i)
{
	int	q;
	int	d;
	int	s;

	q = -1;
	d = 0;
	s = 0;
	while (shell->lst.input[++i])
	{
		if (is_sep(shell->lst.input[i]) > 1)
		{
			while (is_sep(shell->lst.input[i]) > 1)
			{
				if (is_sep(shell->lst.input[i]) == 2)
					d++;
				if (is_sep(shell->lst.input[i]) == 3)
					s++;
				i++;
			}
			break ;
		}
	}
	if (q > 0 || d > 0 || s > 0)
		q = control_qt(q, d, s);
	return (q);
}

void	delete_op(t_shell *shell)
{
	int	i;
	int	check_quote;

	i = -1;
	check_quote = 0;
	while (shell->lst.input[++i])
	{
		if (is_separator(shell->lst.input[i]) == -1)
		{
			if (check_quote == 0)
				check_quote = 1;
			else
				check_quote = 0;
		}
		if (is_separator(shell->lst.input[i]) > 1 && check_quote == 0)
			shell->lst.input[i] = ' ';
	}
}
