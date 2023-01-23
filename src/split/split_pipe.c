/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:01:25 by mvolpi            #+#    #+#             */
/*   Updated: 2023/01/23 11:16:57 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split.h"

int	is_pipe(char c)
{
	if (c == '|')
		return (1);
	if (c == '\0')
		return (1);
	return (0);
}

int	count_words(char *str)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (str[i] != '\0')
	{
		if (is_pipe(str[i]) == 0
			&& is_pipe(str[i + 1]) == 1)
			w++;
		i++;
	}
	return (w);
}

void	save_word(char *dest, char *src)
{
	int	i;

	i = 0;
	while (is_pipe(src[i]) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	save_split(char **split, char *str)
{
	int	i;
	int	j;
	int	w;

	i = 0;
	w = 0;
	while (str[i] != '\0')
	{
		if (is_pipe(str[i]) == 1 || str[i] == ' ')
			i++;
		else
		{
			j = 0;
			while (is_pipe(str[i + j]) == 0)
				j++;
			split[w] = (char *)malloc(sizeof(char) * (j + 1));
			if (!(split + w))
				return (0);
			save_word(split[w], str + i);
			i += j;
			w++;
		}
	}
	return (1);
}

char	**split_pipe(char const *s)
{
	int		w;
	char	**rtn;

	if (!s)
		return (NULL);
	w = count_words((char *)s);
	rtn = (char **)malloc(sizeof(char *) * (w + 1));
	if (!rtn)
		return (NULL);
	if (!(save_split(rtn, (char *) s)))
	{
		w = -1;
		while (rtn + ++w)
			free(rtn + w);
		free(rtn);
	}
	rtn[w] = 0;
	return (rtn);
}
