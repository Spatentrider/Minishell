/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:57:40 by mich              #+#    #+#             */
/*   Updated: 2023/02/02 16:06:45 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

void	ft_cd(t_shell *shell)
{
	shell->cd.i = -1;
	shell->cd.oldpwd = ft_pwd();
	shell->cd.s = chdir(shell->lst.executor[1]);
	while (shell->env.current[++shell->cd.i])
	{
		if (strncmp(shell->env.current[shell->cd.i], "OLDPWD", 6) == 0)
		{
				shell->cd.pwd = ft_strjoin("OLDPWD=", shell->cd.oldpwd);
				shell->env.current[shell->cd.i] = shell->cd.pwd;
		}
		if (strncmp(shell->env.current[shell->cd.i], "PWD", 3) == 0)
		{
			shell->cd.pwd2 = ft_strjoin("PWD=", ft_pwd());
			shell->env.current[shell->cd.i] = shell->cd.pwd2;
		}
	}
}
