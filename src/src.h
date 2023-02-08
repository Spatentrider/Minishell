/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:35:47 by mvolpi            #+#    #+#             */
/*   Updated: 2023/02/08 11:34:00 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
# define SRC_H

# include "../h_file/minishell.h"
# include "split/split.h"
# include "get_env/get_env.h"
# include "arr_utils/arr_utils.h"
# include "builtins/builtins.h"
# include "parse/parse.h"
# include "operator/operator.h"

void	free_struct(t_shell *shell);

#endif
