/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:33:59 by mvolpi            #+#    #+#             */
/*   Updated: 2023/01/20 10:34:38 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_H
# define SPLIT_H

# include "../../h_file/minishell.h"

/*split_utils.c*/
void	write_pipe(char *dest, char *src);
void	write_red_r(char *dest, char *src);
void	write_red_l(char *dest, char *src);
int		control_quote(char *str, int i);
int		control_sep(char *str, char *split, int i);
/*split.c*/
int		is_separator(char c);
int		words(char *str);
void	write_word(char *dest, char *src, int j);
int		write_split(char **split, char *str);
char	**split_cmd(char const *s);

#endif
