/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzodimascia <lorenzodimascia@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:08:47 by mich              #+#    #+#             */
/*   Updated: 2023/03/15 16:17:25 by lorenzodima      ###   ########.fr       */
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
	g_exit = 130;
	printf("\n");
	rl_replace_line("", 0);
	rl_redisplay();
	(void)sig;
}

void	signal_handler3(int sig)
{
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	(void)sig;
}
