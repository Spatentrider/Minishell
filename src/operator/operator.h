/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:18:24 by mich              #+#    #+#             */
/*   Updated: 2023/02/15 10:21:29 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATOR_H
# define OPERATOR_H

# include "../src.h"

/*check_op.c*/
void	redirection(int c, t_shell *shell);
int		check_red(char *input, t_shell *shell, int i);
void	expansion(t_shell *shell, int p);
void	control_exp(t_shell *shell);
int		check_operator(t_shell *shell);
/*clean_quote.c*/
void	delete_qt(t_shell *shell);
int		clean_q(t_shell *shell, int q, int i);
void	delete_dq(t_shell *shell, int q);
void	delete_sq(t_shell *shell, int q);
void	delete_sdq(t_shell *shell, int q);
/*delete.c*/
int		is_sep(char c);
int		control_q(int q, int d, t_shell *shell);
int		control_qt(int q, int d, int s, t_shell *shell);
int		clean_quote(t_shell *shell, int i);
void	delete_op(t_shell *shell);
/*redirection.c*/
void	red_out(char *redirection);
void	red_inp(char	*redirection);
void	append(char *redirection);
void	here_doc(char *redirection, t_shell *shell);
/*utils.c*/
void	change_word(t_shell *shell, int i, int pos);

#endif
