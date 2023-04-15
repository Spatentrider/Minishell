/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:16:52 by mich              #+#    #+#             */
/*   Updated: 2023/04/15 12:45:29 by mich             ###   ########.fr       */
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

void	free_str(char *str, char *curr)
{
	free(curr);
	free(str);
}

int	change_a(int i, int j, int pos, t_shell *shell)
{
	if (pos > 0)
	{
		free(shell->env.current[i]);
		shell->env.current[i] = ft_strdup(shell->lst.executor[c]);
		j = -1;
		while (shell->env.current[i][++j])
		{
			if (shell->env.current[i][j] == '\a')
				shell->env.current[i][j] = ' ';
		}
		return (1);
	}
	return (0);
}

int	save_str(t_shell *shell, int pos, int i, int c)
{
	pos = ft_strchrp(shell->env.current[i], '=');
	if (pos > 0)
		shell->curr = strdup_exp(shell->env.current[i], pos);
	else
		shell->curr = ft_strdup(shell->env.current[i]);
	pos = ft_strchrp(shell->lst.executor[c], '=');
	if (pos > 0)
		shell->str = strdup_exp(shell->lst.executor[c], pos);
	else
		shell->str = ft_strdup(shell->lst.executor[c]);
	return (pos);
}
