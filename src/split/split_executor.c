/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_executor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:20:12 by mvolpi            #+#    #+#             */
/*   Updated: 2023/01/23 11:24:47 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split.h"

int	separator(char c)
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
	else if (c == ' ')
		return (5);
	return (0);
}

int	how_much_words(char *str)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (str[i] != '\0')
	{
		if (separator(str[i]) == 0
			&& separator(str[i + 1]) > 0)
			w++;
		i++;
	}
	return (w);
}

void	word(char *dest, char *src)
{
	int	i;

	i = 0;
	while (separator(src[i]) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	split(char **split, char *str)
{
	int	i;
	int	j;
	int	w;

	i = 0;
	w = 0;
	while (str[i] != '\0')
	{
		if (separator(str[i]) > 0)
			i++;
		else
		{
			j = 0;
			while (separator(str[i + j]) == 0)
				j++;
			split[w] = (char *)malloc(sizeof(char) * (j + 1));
			if (!(split + w))
				return (0);
			word(split[w], str + i);
			i += j;
			w++;
		}
	}
	return (1);
}

char	**split_executor(char const *s)
{
	int		w;
	char	**rtn;

	if (!s)
		return (NULL);
	w = how_much_words((char *)s);
	rtn = (char **)malloc(sizeof(char *) * (w + 1));
	if (!rtn)
		return (NULL);
	if (!(split(rtn, (char *) s)))
	{
		w = -1;
		while (rtn + ++w)
			free(rtn + w);
		free(rtn);
	}
	rtn[w] = 0;
	return (rtn);
}
