/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:25:43 by mich              #+#    #+#             */
/*   Updated: 2023/04/13 12:18:16 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	init_strings(t_shell *shell)
{
	shell->env.save = NULL;
	shell->env.current = NULL;
	shell->lst.input = NULL;
	shell->lst.doc = NULL;
	shell->lst.split = NULL;
	shell->lst.error = NULL;
	shell->lst.executor = NULL;
	shell->lst.pipe = NULL;
	shell->lst.redirection = NULL;
	shell->lst.file = NULL;
	shell->lst.expansion = NULL;
	shell->lst.here_doc = NULL;
	shell->lst.cat_array = NULL;
	shell->cd.oldpwd = NULL;
	shell->cd.pwd = NULL;
	shell->cd.pwd2 = NULL;
	shell->exp.sort_env = NULL;
	shell->lst.input = NULL;
}

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
	shell->check_mix_red = 0;
	shell->dollar = 0;
	shell->flag = 0;
	shell->check_signal_d = 0;
	shell->here_cat = 0;
	shell->check_redirection = 0;
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
	shell->check_mix_red = 0;
	shell->dollar = 0;
	shell->flag = 0;
	shell->check_signal_d = 0;
	shell->here_cat = 0;
	shell->check_redirection = 0;
}
