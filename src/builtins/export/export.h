/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:54 by mich              #+#    #+#             */
/*   Updated: 2023/02/02 14:48:41 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_H
# define EXPORT_H

# include "../builtins.h"

/*export.c*/
int		ft_strchrp(const char *s, int c);
char	**sort(char **sorting);
void	ft_export(t_shell *shell);

#endif
