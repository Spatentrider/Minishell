/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:17:02 by mich              #+#    #+#             */
/*   Updated: 2023/02/02 14:43:51 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

void	ft_exit(char **current)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	ft_env(current);
	while (current[++i])
	{
		if (strncmp(current[i], "SHLVL=", 6) == 0)
		{
			j = current[i][6] - '0';
			j--;
			j += '0';
			current[i][6] = j;
			exit(0);
		}
	}
}
