/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:17:48 by mich              #+#    #+#             */
/*   Updated: 2023/02/06 16:54:20 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

void	expansion(char **expansion, char **current)
{
	int		i;
	int		j;
	int		pos;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * 100);
	while (expansion[0][++j])
	{
		str[i] = expansion[0][j];
		i++;
	}
	printf("ciao = %s\n", str);
	i = -1;
	while (current[++i])
	{
		pos = ft_strchrp(current[i], '=');
		if (ft_strncmp(current[i], str, pos) == 0)
		{
			expansion [0] = current[pos];
		}
		printf("pipooooooooooooooo = %s\n", expansion[0]);
	}
}

int	check_operator(t_shell *shell)
{
	int		i;

	i = -1;
	// shell->lst.pipe = split_pipe(shell->lst.input);
	// if (shell->lst.pipe[1] != NULL)
	// 	ft_pipe();
	// shell->lst.redirection = split_redirection(shell->lst.input);
	// if (shell->lst.redirection[1] != NULL)
	// 	redirection();
	shell->lst.expansion = split_executor(shell->lst.split[0]);
	while (shell->lst.expansion[++i])
	{
		if (ft_strncmp(shell->lst.expansion[i], "$", 1) == 0)
			expansion(shell->lst.expansion, shell->env.current);
	}
	printf("pippo ora");
	return (0);
}
