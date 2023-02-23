/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:02:46 by mich              #+#    #+#             */
/*   Updated: 2023/02/14 16:03:08 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

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

int	clean_q(t_shell *shell, int q, int i)
{
	while (q >= 1)
	{
		if (is_separator(shell->lst.input[++i]) == -1)
		{
			shell->lst.input[i] = ' ';
			q--;
		}
	}
	return (i);
}

void	delete_dq(t_shell *shell, int q)
{
	int	i;
	int	j;

	i = -1;
	j = q;
	i = clean_q(shell, q, i);
	shell->lst.input[i] = 39;
	i++;
	while (shell->lst.input[++i])
	{
		if (is_separator(shell->lst.input[i]) == -1)
		{
			shell->lst.input[i] = 39;
			i++;
			while (j > 1)
			{
				shell->lst.input[i] = ' ';
				j--;
				i++;
			}
			break ;
		}
	}
}

void	delete_sq(t_shell *shell, int q)
{
	int	i;
	int	j;

	i = -1;
	j = q;
	i = clean_q(shell, q, i);
	shell->lst.input[i] = 34;
	i++;
	while (shell->lst.input[++i])
	{
		if (is_separator(shell->lst.input[i]) == -1)
		{
			shell->lst.input[i] = 34;
			i++;
			while (j > 1)
			{
				shell->lst.input[i] = ' ';
				j--;
				i++;
			}
			break ;
		}
	}
}

void	delete_sdq(t_shell *shell, int q)
{
	int	i;
	int	j;

	i = -1;
	j = q;
	i = clean_q(shell, q, i);
	i++;
	while (shell->lst.input[++i])
	{
		if (is_separator(shell->lst.input[i]) == -1)
		{
			i++;
			while (j > 1)
			{
				shell->lst.input[i] = ' ';
				j--;
				i++;
			}
			break ;
		}
	}
}
