/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:16:48 by mvolpi            #+#    #+#             */
/*   Updated: 2023/01/05 15:48:40 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_proc.h"

int	is_separator(char c, char cr)
{
	if (c == cr)
		return (2);
	if (c == '\0')
		return (1);
	return (0);
}

int	words(char *str, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (str[i] != '\0')
	{
		if (is_separator(str[i], c) == 0
			&& is_separator(str[i + 1], c) == 2)
			w++;
		else if (is_separator(str[i], c) == 2
			&& is_separator(str[i + 1], c) == 0)
			w++;
		else if (is_separator(str[i], c) == 0
			&& is_separator(str[i + 1], c) == 1)
			w++;
		else if (is_separator(str[i], c) == 2
			&& is_separator(str[i + 1], c) == 1)
			w++;
		else if (is_separator(str[i], c) == 2
			&& is_separator(str[i + 1], c) == 2)
			w++;
		i++;
	}
	return (w);
}

void	write_word(char *dest, char *src, char c, int n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		while (is_separator(src[i], c) == 0)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else if (n == 2)
	{
		if (is_separator(src[i], c) == 2)
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
}

int	write_split(char **split, char *str, char c)
{
	int	i;
	int	j;
	int	co;
	int	w;

	i = 0;
	w = 0;
	co = 0;
	while (str[i] != '\0')
	{
		if (is_separator(str[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (is_separator(str[i + co], c) == 0
				|| is_separator(str[i + co], c) == 2)
				co++;
			while (is_separator(str[i + j], c) == 0)
				j++;
			split[w] = (char *)malloc(sizeof(char) * (co + 1));
			if (!(split + w))
				return (0);
			while (str[i] == ' ')
				i++;
			if (is_separator(str[i], c) == 0)
			{
				write_word(split[w], str + i, c, 0);
				i += j;
			}
			while (str[i] == ' ')
				i++;
			if (is_separator(str[i], c) == 2)
			{
				w++;
				split[w] = (char *)malloc(sizeof(char) * (1));
				write_word(split[w], str + i, c, 2);
				i++;
			}
			w++;
		}
	}
	return (1);
}

char	**split_cmd(char const *s, char c)
{
	int		w;
	char	**rtn;

	if (!s)
		return (NULL);
	w = words((char *)s, c);
	rtn = (char **)malloc(sizeof(char *) * (w + 1));
	if (!rtn)
		return (NULL);
	if (!(write_split(rtn, (char *) s, c)))
	{
		w = -1;
		while (rtn + ++w)
			free(rtn + w);
		free(rtn);
	}
	rtn[w] = 0;
	return (rtn);
}
