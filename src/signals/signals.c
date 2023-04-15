/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:08:47 by mich              #+#    #+#             */
/*   Updated: 2023/04/15 13:24:37 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

void	signal_handler(int sig)
{
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_exit = 1;
	(void)sig;
}

void	signal_handler2(int sig)
{
	g_exit = 130;
	printf("\n");
	rl_replace_line("", 0);
	rl_redisplay();
	(void)sig;
}

void	signal_handler3(int sig)
{
	g_exit = 131;
	printf("Quit: 3");
	printf("\n");
	rl_replace_line("", 0);
	rl_redisplay();
	(void)sig;
}

void	ctrl_d(t_shell *shell)
{
	if (!shell->lst.input)
	{
		shell->lst.input = NULL;
		free_struct(shell);
		printf("Exiting...\n");
		exit(0);
	}
	if (!shell->lst.doc)
		shell->check_signal_d = 1;
}
