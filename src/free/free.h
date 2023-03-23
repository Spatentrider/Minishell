/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:57:25 by mich              #+#    #+#             */
/*   Updated: 2023/03/23 13:57:25 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "../src.h"

/*free.c*/
void	free_struct(t_shell *shell);
void	ft_sarfree(char **sar, int y);
int		ft_sarsize(char **tocount);
#endif
