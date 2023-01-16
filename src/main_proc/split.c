/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:02:27 by mvolpi            #+#    #+#             */
/*   Updated: 2023/01/16 18:25:33 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_proc.h"

/**
 * @brief Takes a single character and checks if it is the one of the
 * separators, it returns a diffirent number depending on which operator
 * it is
 * 
 * @param c the character to be checked
 * @return int it returns a diffirent number depending on which operator
 * it is
 */
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


/**
 * @brief Scrolls the entire string and count into how many strings
 * the sent string needs to be divided into
 * 
 * @param str the string that is to be divided
 * @return int how many strings the sent string needs to be divided into
 */
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

/**
 * @brief takes the string that needs to be save and the array where
 * we save the string and the lenght of the string to save, save
 * character by charater until j reaches 0
 * 
 * @param dest cell of the string array
 * @param src string that needs to be save
 * @param j lenght of the string
 */
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

/**
 * @brief Takes the string array and the string that needs to be split
 * with a loop it scroll through the whole string and checks letter by
 * letter, with the is_separator function it checks if str[i] is a
 * separator, if it mallocates the cell of the array by 3, checks with
 * function which of the operators it is on and if more of one saves two
 * in the same cell otherwise only one. If instead it is not one of the
 * separators with control_quote it counts how long the string is and
 * mallocates the cell of the array for that lenght and then with
 * write_word saves the whole string up to the next separator or ends at
 * the end
 * 
 * @param split the string array where we saves the splitted string
 * @param str the string that needs to be split
 * @return int return 1
 */
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

/**
 * @brief Takes the string to be split and counts the cells of the array
 * to be prepared where to insert the single strings to be created, once
 * the count is finished it mallocates the necessary cells and checks
 * that if the mallocation or copying fails it frees everything
 * 
 * @param s the string that needs to be split
 * @return char** the string array with split string
 */
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
