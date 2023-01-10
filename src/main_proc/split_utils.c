/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:16:48 by mvolpi            #+#    #+#             */
/*   Updated: 2023/01/10 14:27:46 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_proc.h"

void	write_pipe(char *dest, char *src)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	if (is_separator(src[i]) == 2 && is_separator(src[i + 1] == 2))
	{
		while (p < 2)
		{	
			dest[i] = src[i];
			i++;
			p++;
		}
	}
	else
	{
		dest[i] = src[i];
		i++;
	}
}

void	write_red_r(char *dest, char *src)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	if (is_separator(src[i]) == 3 && is_separator(src[i + 1] == 3))
	{
		while (p < 2)
		{	
			dest[i] = src[i];
			i++;
			p++;
		}
	}
	else
	{
		dest[i] = src[i];
		i++;
	}
}

void	write_red_l(char *dest, char *src)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	if (is_separator(src[i]) == 4 && is_separator(src[i + 1] == 4))
	{
		while (p < 2)
		{	
			dest[i] = src[i];
			i++;
			p++;
		}
	}
	else
	{
		dest[i] = src[i];
		i++;
	}
}

int	control_sep(char *str, char *split, int i)
{
	if (is_separator(str[i]) == 2)
		write_pipe(split, str + i);
	if (is_separator(str[i]) == 3)
		write_red_r(split, str + i);
	if (is_separator(str[i]) == 4)
		write_red_l(split, str + i);
	i++;
	if (is_separator(str[i]) == 2)
		i++;
	else if (is_separator(str[i]) == 3)
		i++;
	else if (is_separator(str[i]) == 4)
		i++;
	while (str[i] == ' ')
		i++;
	return (i);
}
