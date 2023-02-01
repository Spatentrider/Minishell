/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:55:02 by mvolpi            #+#    #+#             */
/*   Updated: 2023/02/01 15:06:03 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <signal.h>
# include <sys/wait.h>
# include <dirent.h>
# include "../readline/readline.h"
# include "../readline/history.h"
# include "../libft/h_file/libft.h"
# include "../parse/parse.h"

int	g_exit;

typedef struct s_env
{
	char			**current;
}					t_env;

typedef struct s_lst
{
	char			*input;
	char			**split;
	char			**error;
}					t_lst;

typedef struct s_cd
{
	int	bash_level;
}			t_cd;

typedef struct s_shell
{
	t_cd	cd;
	t_lst	lst;
	t_env	env;
}				t_shell;

#endif
