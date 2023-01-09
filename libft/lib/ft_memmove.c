/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:16:21 by mvolpi            #+#    #+#             */
/*   Updated: 2022/09/19 10:53:34 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*new_dest;
	unsigned char		*new_src;

	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
	{
		new_dest = (unsigned char *)dest;
		new_src = (unsigned char *)src;
		while (n--)
			*new_dest++ = *new_src++;
	}
	else
	{
		new_dest = (unsigned char *)dest + (n - 1);
		new_src = (unsigned char *)src + (n - 1);
		while (n--)
			*new_dest-- = *new_src--;
	}
	return (dest);
}
