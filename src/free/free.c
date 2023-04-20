/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:12:05 by mich              #+#    #+#             */
/*   Updated: 2023/04/20 16:01:03 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src.h"

void	ft_sarfree(char **sar, int y)
{
	int	x;

	x = -1;
	if (!sar)
		return ;
	while (sar[++x])
	{
		if (sar[x])
		{
			free(sar[x]);
			sar[x] = NULL;
		}
	}
	if (sar)
	{
		free(sar);
		sar = NULL;
	}
	(void)y;
}

int	ft_sarsize(char **tocount)
{
	int	j;

	j = -1;
	if (!tocount)
		return (0);
	while (tocount[++j])
		;
	return (j);
}

/**
 * @brief function that takes the structure of structures to be freed,
 * iterates cell by cell to be free and then does a general free of the
 * array
 * 
 * @param shell the structure of structures
 */

void	free_struct(t_shell *shell)
{
	ft_sarfree(shell->env.current, ft_sarsize(shell->env.current));
	if (shell->lst.input)
		free(shell->lst.input);
}
