/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:19:54 by mich              #+#    #+#             */
/*   Updated: 2023/02/01 15:22:24 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_H
# define EXPORT_H

# include "../builtins.h"

/*export.c*/
char	**sort(char **sorting);
void	ft_export(int argc, char **argv, t_shell shell);

#endif
