/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_parse_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:16:48 by mvolpi            #+#    #+#             */
/*   Updated: 2023/01/30 11:01:10 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split.h"

/**
 * @brief saves the pipe or double pipe in the string array cell
 * 
 * @param dest cell of the string array
 * @param src the pipe or double pipe to save
 */
int	write_pipe(char *dest, char *src)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	j = i + 1;
	p = 0;
	if (is_separator(src[i]) == 2 && is_separator(src[j]) == 2)
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
	return (p);
}

/**
 * @brief saves the redirection or double redirection going right
 * in the string array cell
 * 
 * @param dest cell of the string array
 * @param src the redirection or double redirection to save
 */
int	write_red_r(char *dest, char *src)
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
	return (p);
}

/**
 * @brief saves the redirection or double redirection going left 
 * in the string array cell
 * 
 * @param dest cell of the string array
 * @param src the redirection or double redirection to save
 */
int	write_red_l(char *dest, char *src)
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
	return (p);
}

/**
 * @brief counts until is_separator equals zero, then if it finds a
 * quote it counts all the quote and everything inside until it finds
 * an operator outside the quotes or until it reaches the end of the
 * sent string
 * 
 * @param str string that needs to be save
 * @param i the position to check
 * @return int returns the lenght of the string to save
 */
int	control_quote(char *str, int i)
{
	int	j;
	int	c;

	i = -1;
	j = 0;
	c = 0;
	while (str[++i])
	{
		if (is_separator(str[i]) == -1)
			c++;
	}
	j = c % 2;
	if (j != 0)
		j = count_quote(str, c);
	else if (c == 0)
		j = count_all(str);
	else
		j = count_str(str, i);
	return (j);
}

/**
 * @brief Check which operator it is and use the different functions
 * builts to save that operator, then check that the following character
 * is not another operator that has already been saved in case and in
 * case there is it skips it more skips every space it finds
 * 
 * @param str string that needs to be save
 * @param split the cell of the string array
 * @param i the position to check
 * @return int returns saved operators plus skipped spaces
 */
int	control_sep(char *str, char *split, int i)
{
	int	p;

	p = 0;
	if (is_separator(str[i]) == 2)
		p = write_pipe(split, str + i);
	if (is_separator(str[i]) == 3)
		p = write_red_r(split, str + i);
	if (is_separator(str[i]) == 4)
		p = write_red_l(split, str + i);
	i++;
	if (p == 2)
		i++;
	while (str[i] == ' ')
		i++;
	return (i);
}
