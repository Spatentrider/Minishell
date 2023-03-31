/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:16:52 by mich              #+#    #+#             */
/*   Updated: 2023/03/31 11:17:16 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

int	ft_strchrp(const char *s, int c)
{
	char	find;
	int		i;

	find = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == find)
			return (i);
		i++;
	}
	if (s[i] == find)
		return (i);
	return (0);
}
