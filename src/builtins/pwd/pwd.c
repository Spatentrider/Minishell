/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:24:24 by mich              #+#    #+#             */
/*   Updated: 2023/02/08 11:47:38 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pwd.h"

char	*ft_pwd(void)
{
	char	*s;

	s = (char *)malloc(100 * sizeof(char));
	getcwd(s, 100);
	return (s);
}

void	pwd(void)
{
	char	*s;

	s = (char *)malloc(100 * sizeof(char));
	printf("%s\n", getcwd(s, 100));
	free(s);
	s = NULL;
}
