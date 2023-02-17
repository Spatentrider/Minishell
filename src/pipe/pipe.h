/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:05:58 by mich              #+#    #+#             */
/*   Updated: 2023/02/15 15:02:00 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include "../src.h"

int	control_pipe(t_shell *shell);
int process_pipe(t_shell *shell, int *pid, int c, int j);

#endif
