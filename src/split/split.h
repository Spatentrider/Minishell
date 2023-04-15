/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:33:59 by mvolpi            #+#    #+#             */
/*   Updated: 2023/04/15 16:25:08 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_H
# define SPLIT_H

# include "../src.h"

/*split_executor.c*/
int		separator(char c);
int		how_much_words(char *str);
void	word(char *dest, char *src);
int		split(char **split, char *str);
/*split_parse_quote.c*/
int		count_str(char *str, int i);
int		count_quote(char *str, int c);
int		count_all(char *str);
int		num_of_quote(char *str);
int		count_sep(char *str, int i);
/*split_parse_utils.c*/
int		write_pipe(char *dest, char *src);
int		write_red_r(char *dest, char *src);
int		write_red_l(char *dest, char *src);
int		control_quote(char *str, int i);
int		control_sep(char *str, char *split, int i);
/*split_parse.c*/
int		is_separator(char c);
int		words(char *str);
void	write_word(char *dest, char *src, int j);
int		write_split(char **split, char *str);
char	**split_cmd(char const *s);
/*split_pipe.c*/
int		is_pipe(char c);
int		count_words(char *str);
void	save_word(char *dest, char *src);
int		save_split(char **split, char *str);
char	**split_pipe(char const *s);
/*split_red.c*/
int		is_red(char c);
char	**split_redirection(char const *s);
/*spòit_urils.c*/
int		control_check(int n);
int		check_str(char *str, int check_pipe, int i);
int		check_string(char *str, int check_red, int i);

#endif
