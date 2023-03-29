/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:09:29 by mich              #+#    #+#             */
/*   Updated: 2023/03/29 17:01:04 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "../src.h"

void	signal_handler(int sig);
void	signal_handler2(int sig);
void	signal_handler3(int sig);
void	ctrl_d(t_shell *shell);
#endif
