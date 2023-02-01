/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:09:25 by mich              #+#    #+#             */
/*   Updated: 2023/02/01 15:12:49 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ECHO_H
# define ECHO_H

# include "../builtins.h"

/*echo.c*/
void	short_echo(char **argv, t_shell shell);
void	ft_echo(int argc, char **argv, t_shell shell);

#endif
