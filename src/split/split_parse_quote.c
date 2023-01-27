/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_parse_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:21:03 by mich              #+#    #+#             */
/*   Updated: 2023/01/27 16:04:44 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split.h"

int	count_str(char *str, int i)
{
	int	j;

	i = 0;
	j = 0;
	while (is_separator(str[i]) <= 0)
	{
		while (is_separator(str[i]) == 0)
		{
			j++;
			i++;
		}
		if (is_separator(str[i]) == -1)
		{
			i++;
			j++;
			while (is_separator(str[i]) != -1)
			{
				j++;
				i++;
			}
			j++;
			i++;
		}
	}
	return (j);
}

int	count_quote(char *str, int c)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	printf("EHIIIIII SONO QUI\n");
	while (c > 0)
	{
		printf("%d\n", c);
		if (is_separator(str[i]) != -1)
			j++;
		else
		{
			j++;
			c--;
		}
		i++;
	}
	return (j);
}
