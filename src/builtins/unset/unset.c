/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:27:19 by mich              #+#    #+#             */
/*   Updated: 2023/02/01 15:27:48 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unset.h"

void	ft_unset(int argc, char **argv, char **current)
{
	int			i;
	int			position;

	i = -1;
	ft_env(current);
	while (current[++i])
	{
		position = ft_strchrp(current[i], '=');
		if (ft_strncmp(current[i], argv[2], position) == 0)
		{
			free(current[i]);
			current[i] = (current[i + 1]);
			i++;
		}
	}
	ft_env(current);
}
