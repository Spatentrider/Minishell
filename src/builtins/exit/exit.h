/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:17:13 by mich              #+#    #+#             */
/*   Updated: 2023/03/14 14:48:52 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include "../builtins.h"

/*exit.c*/
void	ft_exit(t_shell *shell);
int		inside_exit(t_shell *shell);
#endif
