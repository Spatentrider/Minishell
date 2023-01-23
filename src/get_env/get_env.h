/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:33:11 by mvolpi            #+#    #+#             */
/*   Updated: 2023/01/20 10:35:08 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_ENV_H
# define GET_ENV_H

# include "../../h_file/minishell.h"

/*init_env.c*/
void	get_env(char **envp, t_shell *env_list);

#endif
