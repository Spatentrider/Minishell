/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzodimascia <lorenzodimascia@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:21:13 by mich              #+#    #+#             */
/*   Updated: 2023/03/15 16:28:48 by lorenzodima      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

int	ft_strchrp(const char *s, int c)
{
	char	find;
	int		i;

	find = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == find)
			return (i);
		i++;
	}
	if (s[i] == find)
		return (i);
	return (1);
}

void	print_export(t_shell *shell, char **str_save)
{
	int	i;

	i = -1;
	while (shell->exp.sort_env[++i])
	{
		str_save = ft_split(shell->exp.sort_env[i], '=');
		if (str_save[1] == NULL)
			printf("declare -x %s\n", str_save[0]);
		else
		{
			printf("declare -x %s=%c", str_save[0], 34);
			printf("%s%c\n", str_save[1], 34);	
		}
	}
}

char	**sort(char **sorting)
{
	int		i;
	int		j;
	int		c;
	char	**sort_env;

	i = 0;
	while (sorting[i])
		++i;
	sort_env = malloc(sizeof(char *) * (i + 1));
	sort_env[i] = NULL;
	i = -1;
	while (sorting[++i])
	{
		j = -1;
		c = 0;
		while (sorting[++j])
			if (ft_strncmp(sorting[i], sorting[j], ft_strlen(sorting[i])) > 0)
				c++;
		sort_env[c] = sorting[i];
	}
	return (sort_env);
}

void	change_var(t_shell *shell, int c)
{
	while (shell->env.current[++shell->exp.i])
	{
		shell->exp.pos = ft_strchrp(shell->env.current[shell->exp.i], '=');
		if (ft_strncmp(shell->env.current[shell->exp.i], \
					shell->lst.executor[c], shell->exp.pos + 1) == 0)
		{
			shell->env.current[shell->exp.i] = shell->lst.executor[c];
			shell->exp.j = 0;
		}
	}
}

void	ft_export(t_shell *shell)
{
	char	**str_save;
	int		c;

	c = 0;
	str_save = (char **)malloc(sizeof(char *) * 100);
	if (shell->lst.executor[1] == NULL)
	{
		shell->exp.sort_env = sort(shell->env.current);
		print_export(shell, str_save);
	}
	else
	{
		while (shell->lst.executor[++c])
		{
			shell->exp.j = -1;
			shell->exp.i = -1;
			change_var(shell, c);
			if (shell->exp.j == -1)
			{
				shell->env.current[shell->exp.i] = shell->lst.executor[c];
				shell->env.current[shell->exp.i + 1] = NULL;
			}
		}
	}
	return ;
}
