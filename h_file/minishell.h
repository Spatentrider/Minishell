/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:55:02 by mvolpi            #+#    #+#             */
/*   Updated: 2023/02/09 15:09:40 by mvolpi           ###   ########.fr       */
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
# include "../src/src.h"

int	g_exit;

typedef struct s_unset
{
	int	i;
	int	j;
	int	position;
}					t_unset;

typedef struct s_env
{
	char			**current;
}					t_env;

typedef struct s_lst
{
	char	*input;
	char	*doc;
	char	**split;
	char	**error;
	char	**executor;
	char	**pipe;
	char	**redirection;
	char	**file;
	char	**expansion;
}					t_lst;

typedef struct s_cd
{
	int		bash_level;
	int		i;
	int		s;
	char	*oldpwd;
	char	*pwd;
	char	*pwd2;
}			t_cd;

typedef struct s_echo
{
	int	i;
	int	j;
}	t_echo;

typedef struct s_exp
{
	int		i;
	int		j;
	char	**sort_env;
	int		pos;
}	t_exp;

typedef struct s_shell
{
	t_cd	cd;
	t_lst	lst;
	t_env	env;
	t_echo	echo;
	t_exp	exp;
	t_unset	unset;
}				t_shell;

#endif
