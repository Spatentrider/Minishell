/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:18:24 by mich              #+#    #+#             */
/*   Updated: 2023/02/13 11:44:18 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATOR_H
# define OPERATOR_H

# include "../src.h"

/*check_op*/
void	redirection(char **redirection, int c, t_shell *shell);
int		check_red(char *input);
void	expansion(char *expansion, char **current);
int		check_operator(t_shell *shell);
/*delete.c*/
int		clean_quote(t_shell *shell);
void	delete_op(t_shell *shell);
/*redirection.c*/
void	red_out(char *redirection);
void	red_inp(char	*redirection);
void	append(char *redirection);
void	here_doc(char *redirection, t_shell *shell);

#endif
