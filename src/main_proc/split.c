/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:02:27 by mvolpi            #+#    #+#             */
/*   Updated: 2023/01/16 11:43:29 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_proc.h"

int	is_separator(char c)
{
	if (c == '\0')
		return (1);
	else if (c == '|')
		return (2);
	else if (c == '>')
		return (3);
	else if (c == '<')
		return (4);
	else if (c == '\0')
		return (1);
	else if (c == 34 || c == 39)
		return (-1);
	return (0);
}

int	words(char *str)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (str[i] != '\0')
	{
		if (is_separator(str[i] == -1))
			w++;
		if (is_separator(str[i] == 2))
			w++;
		if (is_separator(str[i] == 3))
			w++;
		if (is_separator(str[i] == 4))
			w++;
		if (is_separator(str[i]) == 0
			&& is_separator(str[i + 1]) == 2)
			w++;
		i++;
	}
	return (w);
}

void	write_word(char *dest, char *src, int j)
{
	int	i;

	i = 0;
	while (j > 0)
	{
		dest[i] = src[i];
			i++;
			j--;
	}
	dest[i] = '\0';
}

int	write_split(char **split, char *str)
{
	int	i;
	int	j;
	int	w;

	i = 0;
	w = 0;
	while (str[i] != '\0')
	{
		if (is_separator(str[i]) > 0)
		{
			split[w] = (char *)malloc(sizeof(char) * (3));
			i = control_sep(str, split[w], i);
			w++;
		}
		else
		{
			j = control_quote(str + i, i);
			split[w] = (char *)malloc(sizeof(char) * (j));
			write_word(split[w], str + i, j);
			i = i + j;
			w++;
		}
	}
	return (1);
}

char	**split_cmd(char const *s)
{
	int		w;
	char	**rtn;

	if (!s)
		return (NULL);
	w = words((char *)s);
	rtn = (char **)malloc(sizeof(char *) * (w + 1));
	if (!rtn)
		return (NULL);
	if (!(write_split(rtn, (char *) s)))
	{
		w = -1;
		while (rtn + ++w)
			free(rtn + w);
		free(rtn);
	}
	rtn[w] = 0;
	return (rtn);
}
