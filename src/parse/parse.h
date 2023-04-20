/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzak <kzak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:35:28 by mich              #+#    #+#             */
/*   Updated: 2023/04/20 15:36:57 by kzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../src.h"

/*parse_utils.c*/
size_t	ft_strlenr(const char *s);
int		control(char *string);
int		check_pipe(char *string, t_shell *shell);
int		check_2_red(t_shell *shell, char *string);
int		control_string(char *string);
/*parse.c*/
int		check_redirection(char *string, t_shell *shell);
int		check_quote(char *string);
int		check_parameter(char *string, char c, t_shell *shell);
int		parse(char **string, t_shell *shell, int i);

#endif
