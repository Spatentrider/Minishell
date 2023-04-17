/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_redirection_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbellucc <vbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:45:20 by mich              #+#    #+#             */
/*   Updated: 2023/04/17 11:05:51 by vbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

void	print_cat_array(t_shell *shell)
{
	if (shell->here_cat == 1)
	{
		shell->echo.i = -1;
		while (shell->lst.cat_array[++shell->echo.i])
			printf("%s\n", shell->lst.cat_array[shell->echo.i]);
		ft_sarfree(shell->lst.cat_array, ft_sarsize(shell->lst.cat_array));
	}
	shell->redirection_out = dup(STDOUT_FILENO);
	close(shell->redirection.fd);
	shell->redirection.i++;
}

int	ft_strcmp(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i])
	{
		if (str1[i] == '\0')
			return (0);
		i++;
	}
	return (i);
}
