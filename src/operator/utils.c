/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:35:40 by mich              #+#    #+#             */
/*   Updated: 2023/03/01 14:46:09 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

int	double_count(char *string, int i, int count_quote)
{
	while (string[i])
	{
		if (string[i] == 34)
			count_quote++;
		i++;
	}
	return (count_quote);
}

int	single_count(char *string, int i, int count_single)
{
	while (string[i])
	{
		if (string[i] == 39)
			count_single++;
		i++;
	}
	return (count_single);
}

void	change_word(t_shell *shell, int i, int pos)
{
	int	j;

	j = -1;
	while (shell->lst.input[++j] != '$')
		;
	while (shell->env.current[i][++pos])
	{
		shell->lst.input[j] = shell->env.current[i][pos];
		j++;
	}
	shell->lst.input[j] = ' ';
}
