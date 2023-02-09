/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:18:24 by mich              #+#    #+#             */
/*   Updated: 2023/02/09 15:13:30 by mvolpi           ###   ########.fr       */
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
void	delete_op(t_shell *shell);
/*redirection.c*/
void	red_out(char *redirection);
void	red_inp(char	*redirection);
void	append(char *redirection);
// void	here_doc(char *redirection, t_shell *shell);

#endif
