/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:35:40 by mich              #+#    #+#             */
/*   Updated: 2023/02/14 17:23:15 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

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
