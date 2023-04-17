/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_red.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbellucc <vbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 11:22:55 by mich              #+#    #+#             */
/*   Updated: 2023/04/17 12:17:40 by vbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXP_RED_H
# define EXP_RED_H

# include "../src.h"

/*exp_red_util.c*/
void	init_var(t_shell *shell, int i);
void	control_a(t_shell *shell);
/*exp_red.c*/
void	exp_red(t_shell *shell);

#endif
