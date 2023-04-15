/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:01:25 by mvolpi            #+#    #+#             */
/*   Updated: 2023/04/15 13:05:13 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split.h"

/**
 * @brief Takes a single character and checks if it is a pipe, if not
 * it return 0, instead if it ia a pipe or the end of the string it
 * returns 1
 * 
 * @param c the character to be checked
 * @return int returns 0 if it is not a pipe, if it is, returns 1
 */
int	is_pipe(char c)
{
	if (c == '|')
		return (1);
	if (c == '\0')
		return (1);
	return (0);
}

/**
 * @brief Scrolls the entire string and count into how many strings
 * the sent string needs to be divided into
 * 
 * @param str the string that is to be divided
 * @return int how many strings the sent string needs to be divided into
 */
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

/**
 * @brief takes the string that needs to be save and the array where
 * we save the string, save character by charater
 * 
 * @param dest cell of the string array
 * @param src string that needs to be save
 */
void	save_word(char *dest, char *src)
{
	int	i;
	int	check_pipe;

	i = 0;
	while ((is_pipe(src[i]) == 0 || check_pipe == 1) && src[i] != '\0')
	{
		if (src[i] == 34)
		{
			dest[i] = src[i];
			if (check_pipe == 0)
				check_pipe = 1;
			else
				check_pipe = 0;
			i++;
		}
		else
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
}

/**
 * @brief Takes the string array and the string that needs to be split
 * with a loop it scroll through the whole string and checks letter by
 * letter, with the is_pipe function it checks if str[i] is a
 * pipe, if it skip the pipe. If instead it is a pipe with a loop it
 * counts how long the string is and mallocates the cell of the array 
 * for that lenght and then with save_word saves the whole string up 
 * to the next separator or ends at the end
 * 
 * @param split the string array where we saves the splitted string
 * @param str the string that needs to be split
 * @return int return 1
 */
int	save_split(char **split, char *str)
{
	int	i;
	int	j;
	int	w;
	int	check_pipe;

	i = 0;
	w = 0;
	check_pipe = 0;
	while (str[i] != '\0')
	{
		if (is_pipe(str[i]) == 1 || str[i] == ' ')
			i++;
		else
		{
			j = 0;
			while (is_pipe(str[i + j]) == 0 || check_pipe == 1)
			{
				if (str[i + j] == 34)
				{
					if (check_pipe == 1)
						check_pipe = 0;
					else
						check_pipe = 1;
				}
				j++;
			}
			split[w] = (char *)malloc(sizeof(char) * (j + 10));
			if (!(split[w]))
				return (0);
			save_word(split[w], str + i);
			i += j;
			w++;
		}
	}
	split[w] = NULL;
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
		while (rtn[w])
			free(rtn[w]);
		free(rtn);
	}
	rtn[w] = 0;
	return (rtn);
}
