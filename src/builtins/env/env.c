/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:15:42 by mich              #+#    #+#             */
/*   Updated: 2023/03/06 15:33:29 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	ft_env(t_shell *shell, char **current)
{
	int	i;

	i = -1;
	if (shell->lst.executor[1] == NULL)
	{
		while (current[++i])
		{
			if (strchr(current[i], '=') != NULL)
				printf("%s\n", current[i]);
		}
	}
	else
	{
		g_exit = 127;
		printf("env: %c%s%c: No such file or directory\n", \
			39, shell->lst.executor[1], 39);
	}
}
