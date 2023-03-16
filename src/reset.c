/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:25:43 by mich              #+#    #+#             */
/*   Updated: 2023/03/16 11:39:40 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	init_all(t_shell *shell)
{
	shell->old_g_exit = 0;
	shell->unset.i = 0;
	shell->unset.j = 0;
	shell->unset.position = 0;
	shell->unset.k = 0;
	shell->single_quote = 0;
	shell->exp.i = 0;
	shell->exp.j = 0;
	shell->exp.pos = 0;
	shell->env.i = 0;
	shell->echo.i = 0;
	shell->echo.j = 0;
	shell->cd.bash_level = 0;
	shell->cd.i = 0;
	shell->cd.s = 0;
	shell->here_pipe = 0;
}

void	reset_var(t_shell *shell)
{
	g_exit = 0;
	shell->unset.i = 0;
	shell->unset.j = 0;
	shell->unset.position = 0;
	shell->unset.k = 0;
	shell->single_quote = 0;
	shell->exp.i = 0;
	shell->exp.j = 0;
	shell->exp.pos = 0;
	shell->env.i = 0;
	shell->echo.i = 0;
	shell->echo.j = 0;
	shell->cd.bash_level = 0;
	shell->cd.i = 0;
	shell->cd.s = 0;
	shell->here_pipe = 0;
}
