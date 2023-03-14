/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:44:24 by mich              #+#    #+#             */
/*   Updated: 2023/03/14 14:44:59 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	control(char *string)
{
	int	i;

	i = ft_strlen(string);
	if (i == 2)
	{
		if ((string[0] == 34 && string[1] == 34)
			|| (string[0] == 39 && string[1] == 39))
		{
			printf("Command %s not found\n", string);
			g_exit = 127;
		}
	}
	return (g_exit);
}
