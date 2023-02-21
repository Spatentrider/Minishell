/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:53:12 by mich              #+#    #+#             */
/*   Updated: 2023/02/21 15:34:11 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int	ft_fork(t_shell *shell)
{
	int	pid;
	int	status;

	pid = fork();
	signal(SIGINT, signal_handler2);
	if (pid == 0)
	{
		if (execve(ft_strjoin("/bin/", shell->lst.executor[0]), \
			shell->lst.executor, NULL) == -1)
		{
			perror("execve failed");
			exit(EXIT_FAILURE);
		}
		if (g_exit == 500)
			exit(0);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			return (0);
	}
	else
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	signal(SIGINT, signal_handler);
	return (0);
}

int	ab_path(t_shell	*shell)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(shell->lst.executor[0], shell->lst.executor, NULL) == -1)
		{
			perror("execve failed");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			return (0);
	}
	else
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	change_shlvl(t_shell *shell)
{
	int		i;
	int		j;
	int		k;
	char	*save;

	i = -1;
	j = 0;
	k = 5;
	save = (char *)malloc(sizeof(char) * 10);
	while (shell->env.current[++i])
	{
		if (ft_strncmp("SHLVL=", shell->env.current[i], 6) == 0)
		{
			while (shell->env.current[i][++k])
			{
				save[j] = shell->env.current[i][k];
				j++;
			}
			save[j] = '\0';
			break ;
		}
	}
	if (save[1] == '\0')
		save[0]++;
	shell->env.current[i] = ft_strjoin("SHLVL=", save);
}

int	commands(t_shell *shell)
{
	int		c;

	c = -1;
	if (ft_strncmp("./minishell", shell->lst.executor[0], 12) == 0)
	{
		change_shlvl(shell);
		return (1);
	}
	if (ft_strncmp("/bin/", shell->lst.executor[0], 5) == 0)
	{
		ab_path(shell);
		return (1);
	}
	while (shell->env.current[++c])
	{
		if (ft_strncmp(shell->env.save, shell->env.current[c], \
			shell->env.i) == 0 || ft_strncmp("PATH=/bin/", \
			shell->env.current[c], shell->env.i) == 0 \
			|| ft_strncmp("PATH=/bin", shell->env.current[c], \
			shell->env.i) == 0)
			ft_fork(shell);
	}
	return (1);
}
