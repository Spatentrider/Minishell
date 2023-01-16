/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:16:48 by mvolpi            #+#    #+#             */
/*   Updated: 2023/01/16 11:20:50 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_proc.h"

void	write_pipe(char *dest, char *src)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	j = i + 1;
	p = 0;
	if (is_separator(src[i]) == 2 && is_separator(src[j]) != 0)
	{
		while (p < 2)
		{	
			dest[i] = src[i];
			i++;
			j++;
			p++;
		}
	}
	else
	{
		if (is_separator(src[i]) != 0)
			dest[i] = src[i];
		i++;
		j++;
	}
	dest[i] = '\0';
}

void	write_red_r(char *dest, char *src)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	j = i + 1;
	p = 0;
	if (is_separator(src[i]) == 3 && is_separator(src[j]) != 0)
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
		if (is_separator(src[i]) != 0)
			dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	write_red_l(char *dest, char *src)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	j = i + 1;
	p = 0;
	if (is_separator(src[i]) == 4 && is_separator(src[j]) != 0)
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
		if (is_separator(src[i]) == 4)
			dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	control_quote(char *str, int i)
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
