/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:54 by mich              #+#    #+#             */
/*   Updated: 2023/03/31 11:17:46 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_H
# define EXPORT_H

# include "../builtins.h"

/*export_urils.c*/
int		ft_strchrp(const char *s, int c);
/*export.c*/
char	**sort(char **sorting);
void	ft_export(t_shell *shell);

#endif
