/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:00:36 by mich              #+#    #+#             */
/*   Updated: 2023/02/08 10:11:47 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../src.h"
# include "cd/cd.h"
# include "echo/echo.h"
# include "env/env.h"
# include "exit/exit.h"
# include "export/export.h"
# include "pwd/pwd.h"
# include "unset/unset.h"

int	executor(t_shell *shell, char *str);

#endif
