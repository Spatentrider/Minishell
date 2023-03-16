/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:08:47 by mich              #+#    #+#             */
/*   Updated: 2023/03/16 11:20:59 by mich             ###   ########.fr       */
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
