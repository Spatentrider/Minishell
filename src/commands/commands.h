/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:24:29 by mich              #+#    #+#             */
/*   Updated: 2023/03/01 14:24:30 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "../src.h"

int		commands(t_shell *shell);
void	change_shlvl(t_shell *shell);
int		loop(t_shell *shell, int i, int j);

#endif
