/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:54 by mich              #+#    #+#             */
/*   Updated: 2023/04/15 12:51:22 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_H
# define EXPORT_H

# include "../builtins.h"

/*export_urils.c*/
int		ft_strchrp(const char *s, int c);
void	free_str(char *str, char *curr);
int		change_a(int i, int c, int pos, t_shell *shell);
int		save_str(t_shell *shell, int pos, int i, int c);
/*export.c*/
char	**sort(char **sorting);
void	ft_export(t_shell *shell);

#endif
