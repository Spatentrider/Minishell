/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:35:28 by mich              #+#    #+#             */
/*   Updated: 2023/04/15 15:18:55 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../src.h"

/*parse_utils.c*/
int		control(char *string);
int		check_pipe(char *string);
int		check_2_red(t_shell *shell, char *string);
/*parse.c*/
int		check_pipe(char *string);
int		check_redirection(char *string, t_shell *shell);
int		check_quote(char *string);
int		check_parameter(char *string, char c, t_shell *shell);
int		parse(char **string, t_shell *shell);

#endif
