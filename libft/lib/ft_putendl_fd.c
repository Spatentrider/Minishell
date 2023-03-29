/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:28:57 by mvolpi            #+#    #+#             */
/*   Updated: 2023/03/29 17:02:34 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!(s) || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

int	ft_sarprint(char **sar)
{
	int	i;
	int	ret;

	i = -1;
	ret = 0;
	if (!sar || !sar[0])
		return (0);
	ft_printf("---SPLITTED ARGS---\n");
	while (sar[++i] && sar[i] != 0)
	{
		ret += ft_printf("\"%s\"\n", sar[i]);
	}
	ft_printf("-----########-----\n");
	return (ret);
}
