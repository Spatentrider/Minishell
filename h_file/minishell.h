/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:55:02 by mvolpi            #+#    #+#             */
/*   Updated: 2023/04/15 16:52:58 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <signal.h>
# include <sys/wait.h>
# include <dirent.h>
# include <termios.h>
# include "../readline/readline.h"
# include "../readline/history.h"
# include "../libft/h_file/libft.h"
# include "../src/src.h"

# define BUFSIZE 100

int	g_exit;

typedef struct s_unset
{
	int	i;
	int	j;
	int	position;
	int	k;
}					t_unset;

typedef struct s_env
{
	char	**current;
	char	**save;
	int		i;
}			t_env;

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
	char	**here_doc;
	char	**cat_array;
	char	**delete_str;
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

typedef struct s_strtok
{
	size_t	delim_len;
	char	*result;
	int		match;
	size_t	i;
}	t_strtok;

typedef struct s_shell
{
	t_cd		cd;
	t_lst		lst;
	t_env		env;
	t_echo		echo;
	t_exp		exp;
	t_unset		unset;
	t_strtok	strtok;
	char		*save_redirection;
	char		**path;
	char		*str;
	char		*curr;
	int			old_g_exit;
	int			stdin;
	int			stdout;
	int			out_pipe;
	int			single_quote;
	int			here_pipe;
	int			redirection_id;
	int			check_mix_red;
	int			redirection_out;
	int			here_cat;
	int			flag;
	int			dollar;
	int			check_signal_d;
	int			check_redirection;
	int			do_redirection;
	int			pipe_counter;
}				t_shell;

#endif
