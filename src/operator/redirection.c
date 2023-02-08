/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:32:54 by mich              #+#    #+#             */
/*   Updated: 2023/02/08 15:51:58 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

void	red_out(char **redirection)
{
	int	i;

	i = open(redirection[1], O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	dup2(i, STDOUT_FILENO);
}

void	red_inp(char	**redirection)
{
	int	i;

	i = open(redirection[1], O_RDONLY);
	dup2(i, STDIN_FILENO);
}

void	append(char **redirection)
{
	int	i;

	i = open(redirection[1], O_WRONLY | O_CREAT | O_APPEND,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	dup2(i, STDOUT_FILENO);
}

void	here_doc(char **redirection, t_shell *shell)
{
	int		i;
	char	*str;

	while (1)
	{
		shell->lst.doc = readline("> ");
		i = -1;
		str = *split_executor(redirection[1]);
		while (str[++i])
			;
		if (ft_strncmp(str, shell->lst.doc, i + 1) == 0)
		
			break ;
	}
}
