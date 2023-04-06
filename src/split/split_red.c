/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_red.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:35:15 by mich              #+#    #+#             */
/*   Updated: 2023/04/06 16:58:13 by kzak             ###   ########.fr       */
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
int	is_red(char c)
{
	if (c == '<' || c == '>')
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
int	how_words(char *str)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (str[i] != '\0')
	{
		if (is_red(str[i]) == 0
			&& is_red(str[i + 1]) == 1)
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
void	stamp_word(char *dest, char *src)
{
	int	i;

	i = 0;
	while (is_red(src[i]) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

/**
 * @brief Takes the string array and the string that needs to be split
 * with a loop it scroll through the whole string and checks letter by
 * letter, with the is_red function it checks if str[i] is a
 * pipe, if it skip the pipe. If instead it is a pipe with a loop it
 * counts how long the string is and mallocates the cell of the array 
 * for that lenght and then with stamp_word saves the whole string up 
 * to the next separator or ends at the end
 * 
 * @param split the string array where we saves the splitted string
 * @param str the string that needs to be split
 * @return int return 1
 */
int	stamp_split(char **split, char *str)
{
	int	i;
	int	j;
	int	w;

	i = 0;
	w = 0;
	while (str[i] != '\0')
	{
		if (is_red(str[i]) == 1 || str[i] == ' ')
			i++;
		else
		{
			j = 0;
			while (is_red(str[i + j]) == 0)
				j++;
			split[w] = (char *)malloc(sizeof(char) * (j + 1));
			if (!(split[w]))
				return (0);
			stamp_word(split[w], str + i);
			i += j;
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
char	**split_redirection(char const *s)
{
	int		w;
	char	**rtn;

	if (!s)
		return (NULL);
	w = how_words((char *)s);
	rtn = (char **)malloc(sizeof(char *) * (w + 1));
	if (!rtn)
		return (NULL);
	if (!(stamp_split(rtn, (char *) s)))
	{
		w = -1;
		while (rtn[w])
			free(rtn[w]);
		free(rtn);
	}
	rtn[w] = 0;
	return (rtn);
}
