/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:57:40 by mich              #+#    #+#             */
/*   Updated: 2023/03/23 13:56:56 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

void	cd_home(t_shell *shell)
{
	int		i;
	char	*str;

	i = -1;
	while (shell->env.current[++i])
	{
		if (ft_strncmp(shell->env.current[i], "HOME=", 5) == 0)
			str = ft_strdup(shell->env.current[i] + 5);
	}
	chdir(str);
	free(str);
}

void	change_pwd(t_shell *shell)
{
	while (shell->env.current[++shell->cd.i])
	{
		if (strncmp(shell->env.current[shell->cd.i], "OLDPWD", 6) == 0)
		{
			shell->cd.pwd = ft_strjoin("OLDPWD=", shell->cd.oldpwd);
			free(shell->env.current[shell->cd.i]);
			shell->env.current[shell->cd.i] = shell->cd.pwd;
		}
		if (strncmp(shell->env.current[shell->cd.i], "PWD", 3) == 0)
		{
			shell->cd.pwd2 = ft_strjoinfree(ft_strdup("PWD="), ft_pwd());
			free(shell->env.current[shell->cd.i]);
			shell->env.current[shell->cd.i] = shell->cd.pwd2;
		}
	}
}

void	ft_cd(t_shell *shell)
{
	if (shell->lst.executor[1] == NULL)
		cd_home(shell);
	else
	{
		shell->cd.i = -1;
		shell->cd.oldpwd = ft_pwd();
		if (chdir(shell->lst.executor[1]) == 0)
			change_pwd(shell);
		else
		{
			g_exit = 1;
			printf("cd: %s: No such file or directory\n", \
				shell->lst.executor[1]);
		}
		free(shell->cd.oldpwd);
	}
}
