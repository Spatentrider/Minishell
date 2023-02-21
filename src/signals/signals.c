/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:08:47 by mich              #+#    #+#             */
/*   Updated: 2023/02/14 16:10:20 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

void	signal_handler(int sig)
{
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	(void)sig;
}

void	signal_handler2(int sig)
{
	g_exit = 500;
	printf("\n");
	signal(SIGQUIT, SIG_IGN);
	//rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	(void)sig;
}
