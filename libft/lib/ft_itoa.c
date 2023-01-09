/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:55:01 by mvolpi            #+#    #+#             */
/*   Updated: 2022/09/19 10:52:32 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/libft.h"

static long	ft_digitnb(int n)
{
	long		size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size++);
}

static int	ft_sign(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	long		n_long;
	long		length;
	char		*fresh;

	n_long = n;
	length = ft_digitnb(n_long);
	fresh = (char *)malloc((length + 1) * sizeof(char));
	if (!fresh)
		return (NULL);
	fresh[length] = '\0';
	length--;
	if (n_long < 0)
		n_long = -n_long;
	while (length >= 0)
	{
		fresh[length] = (n_long % 10) + '0';
		length--;
		n_long /= 10;
	}
	if (ft_sign(n))
		fresh[0] = '-';
	return (fresh);
}
