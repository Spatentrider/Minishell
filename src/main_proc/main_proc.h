/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_proc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:22:42 by mvolpi            #+#    #+#             */
/*   Updated: 2023/01/09 13:59:51 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_PROC_H
# define MAIN_PROC_H

# include "../../h_file/minishell.h"

char	**split_cmd(char const *s, char c);
/*free_list*/
// void	lstclear_env(t_shell **lst, void (*del)(void *));
// void	lstclear(t_lst **lst, void (*del)(void *));
/*init_env.c*/
void	get_env(char **envp, t_shell *env_list);
/*init_list.c*/
// size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
// t_shell	*lstlast(t_shell *lst);
// t_shell	*lstnew(void *content);
// void	lstadd_back(t_shell **lst, t_shell *new);
/*main.c*/
int		main(int argc, char **argv, char **envp);
// int	ft_lstsize(t_shell *lst);

#endif
