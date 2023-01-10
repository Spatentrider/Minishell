/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:16:48 by mvolpi            #+#    #+#             */
/*   Updated: 2023/01/10 10:32:17 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_proc.h"

int	is_separator(char c)
{
	if (c == '|'
		|| c == '>'
		|| c == '<')
		return (2);
	else if (c == '\0')
		return (1);
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
		if (is_separator(str[i] == 2))
			w++;
		if (is_separator(str[i]) == 0
			&& is_separator(str[i + 1]) == 2)
			w++;
		i++;
	}
	return (w);
}

void	write_word(char *dest, char *src)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	if (is_separator(src[i]) == 2)
	{
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
	else
	{
		while (is_separator(src[i]) == 0)
		{
			dest[i] = src[i];
			i++;
		}
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
		if (is_separator(str[i]) == 2 && is_separator(str[i + 1] == 2))
		{
			split[w] = (char *)malloc(sizeof(char) * (3));
			write_word(split[w], str + i);
			w++;
			i += 2;
			while (str[i] == ' ')
				i++;
		}
		else if (is_separator(str[i]) == 2)
		{
			split[w] = (char *)malloc(sizeof(char) * (2));
			write_word(split[w], str + i);
			w++;
			i++;
			while (str[i] == ' ')
				i++;
		}
		else
		{
			j = 0;
			while (is_separator(str[i + j]) == 0)
				j++;
			split[w] = (char *)malloc(sizeof(char) * (j + 1));
			if (!(split + w))
				return (0);
			write_word(split[w], str + i);
			i += j;
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
