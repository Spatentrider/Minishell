/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:35:47 by mvolpi            #+#    #+#             */
/*   Updated: 2023/03/16 15:16:47 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C2B7F3BC_6568_4979_B36F_6D18B29323DE
#define C2B7F3BC_6568_4979_B36F_6D18B29323DE

#ifndef SRC_H
# define SRC_H

# include "../h_file/minishell.h"
# include "split/split.h"
# include "get_env/get_env.h"
# include "arr_utils/arr_utils.h"
# include "builtins/builtins.h"
# include "parse/parse.h"
# include "operator/operator.h"
# include "signals/signals.h"
# include "pipe/pipe.h"
# include "commands/commands.h"
# include "expansion/expansion.h"
# include "free/free.h"

int		loop(t_shell *shell, int i, int j);
void	reset_var(t_shell *shell);
void	init_all(t_shell *shell);
#endif


#endif /* C2B7F3BC_6568_4979_B36F_6D18B29323DE */
