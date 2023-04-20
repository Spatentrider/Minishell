/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:18:24 by mich              #+#    #+#             */
/*   Updated: 2023/04/20 12:10:27 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATOR_H
# define OPERATOR_H

# include "../src.h"

/*check_op_utils.c*/
int		check_double_red(t_shell *shell, char *input, int i);
void	check_single_red(t_shell *shell, char *input, int i);
/*check_op.c*/
void	redirection(t_shell *shell);
int		check_red(char *input, t_shell *shell, int i);
void	control_exp(t_shell *shell);
int		check_operator(t_shell *shell);
/*clean_quote.c*/
void	clean_parse(t_shell *shell);
void	clean_all_quote(t_shell *shell);
void	clean_single(t_shell *shell);
void	clean_double(t_shell *shell);
/*cln_quote_utils.c*/
int		loop_quote(t_shell *shell, int i);
void	change_input(t_shell *shell, char *str, int j);
/*delete.c*/
int		is_sep(char c);
int		control_q(int q, int d);
int		control_qt(int q, int d, int s);
int		cont_quote(t_shell *shell, int i);
void	delete_op(t_shell *shell);
/*mix_redirection_urils.c*/
void	print_cat_array(t_shell *shell);
int		ft_strcmp(const char *str1, const char *str2);
/*mix_redirection.c*/
void	mix_redirection(t_shell *shell);
/*redirection.c*/
void	red_out(int count_redirection, t_shell *shell, \
	int count_delete_str, int j);
void	red_inp(char	*redirection, t_shell *shell);
void	append(t_shell *shell, int j, int count_redirection, \
	int count_delete_str);
void	here_doc(char *redirection, t_shell *shell);
void	here_doc_cat(char *redirection, t_shell *shell);
/*utils.c*/
int		double_count(char *string, int i, int count_quote);
int		single_count(char *string, int i, int count_single);
void	change_word(t_shell *shell, int i, int pos);
void	here_doc(char *redirection, t_shell *shell);
int		print_here_doc(t_shell *shell, char *redirection);
int		print_heredoc_cat(t_shell *shell);
/*execute_redirection.c*/
void	go_here_doc(t_shell *shell);
void	go_here_doc_cat(t_shell *shell);
void	go_output(t_shell *shell);
void	go_input(t_shell *shell);
void	go_append(t_shell *shell);
#endif
