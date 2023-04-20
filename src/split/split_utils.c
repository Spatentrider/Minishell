/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:03:21 by mich              #+#    #+#             */
/*   Updated: 2023/04/20 11:59:43 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split.h"

int	control_check(int n)
{
	if (n == 0)
		n = 1;
	else
		n = 0;
	return (n);
}

int	check_str(char *str, int check_pipe, int i)
{
	int	j;

	j = 0;
	while (is_pipe(str[i + j]) == 0 || check_pipe == 1)
	{
		if (str[i + j] == 34)
			check_pipe = control_check(check_pipe);
		j++;
	}
	return (j);
}

int	check_string(char *str, int check_red, int i)
{
	int	j;

	j = 0;
	while (is_red(str[i + j]) == 0 || check_red == 1)
	{
		if (str[i + j] == 34 || str[i + j] == 39)
			check_red = control_check(check_red);
		j++;
	}
	return (j);
}
