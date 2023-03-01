/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:05:58 by mich              #+#    #+#             */
/*   Updated: 2023/03/01 15:41:21 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include "../src.h"

/*pipe_utils.c*/
int		count_pipe(t_shell *shell, int i);
int		process_child(int *fd, int c, t_shell *shell, int i);
int		process_father(int *fd, t_shell *shell, int c, int i);
/*pipe.c*/
void	change_in(t_shell *shell, int c);
int		control_pipe(t_shell *shell);
int		process_pipe(t_shell *shell, int *pid, int c, int j);

#endif
