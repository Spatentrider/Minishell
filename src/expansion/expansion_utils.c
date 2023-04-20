/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:18:36 by vbellucc          #+#    #+#             */
/*   Updated: 2023/04/20 10:13:08 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

void	init_variable(t_shell *shell, int i)
{
	if (shell->lst.executor[i][0] == '$')
		shell->dollar = 1;
	if (shell->lst.executor[i][0] == '\a')
		shell->flag = 1;
	shell->expn.j = -1;
	shell->expn.pos = 0;
	shell->expn.flag = 0;
	shell->lst.expansion = ft_split(shell->lst.executor[i], '$');
	shell->expn.j = ft_strlen(shell->lst.expansion[0]);
	if (shell->lst.expansion[0][shell->expn.j - 1] == '\a')
		shell->expn.flag = 1;
	if (shell->dollar == 1)
		shell->expn.j = -1;
	else
		shell->expn.j = 0;
}

void	control_string_a(t_shell *shell)
{
	if (shell->lst.expansion[shell->expn.j][shell->expn.pos - 1] == '\a')
	{
		shell->lst.expansion[shell->expn.j][shell->expn.pos - 1] = '\0';
		shell->expn.flag = 1;
	}
}
