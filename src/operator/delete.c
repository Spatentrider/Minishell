/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:28:13 by mvolpi            #+#    #+#             */
/*   Updated: 2023/02/09 15:43:39 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

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
