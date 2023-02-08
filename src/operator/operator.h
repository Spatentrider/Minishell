/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:18:24 by mich              #+#    #+#             */
/*   Updated: 2023/02/08 15:33:51 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATOR_H
# define OPERATOR_H

# include "../src.h"

/*check_op*/
int		check_operator(t_shell *shell);
void	red_out(char **redirection);
void	red_inp(char	**redirection);
void	append(char **redirection);
void	here_doc(char **redirection, t_shell *shell);

#endif
