/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:56:37 by mvolpi            #+#    #+#             */
/*   Updated: 2022/09/19 10:54:40 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*c;
	int		i;

	if (!s || !f)
		return (0);
	c = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!c)
		return (0);
	i = 0;
	while (s[i])
	{
		c[i] = f(i, s[i]);
		++i;
	}
	c[i] = '\0';
	return (c);
}
