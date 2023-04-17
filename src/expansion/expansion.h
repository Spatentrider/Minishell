/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbellucc <vbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:11:32 by mich              #+#    #+#             */
/*   Updated: 2023/04/17 12:20:16 by vbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# include "../src.h"

/*expansion_urils.c*/
void	init_variable(t_shell *shell, int i);
void	control_string_a(t_shell *shell);
/*expansion.c*/
void	expansion(t_shell *shell);

#endif
