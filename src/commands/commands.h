/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:24:29 by mich              #+#    #+#             */
/*   Updated: 2023/03/01 15:38:45 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "../src.h"

/*cmd_utils.c*/
int		control_cmd(t_shell *shell);
int		control_path(t_shell *shell, char **path, char *str);
/*command.c*/
int		minishell_case(t_shell *shell);
int		ft_fork(t_shell *shell);
int		ab_path(t_shell	*shell);
void	change_shlvl(t_shell *shell);
int		commands(t_shell *shell);

#endif
