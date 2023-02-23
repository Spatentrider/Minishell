/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:21:13 by mich              #+#    #+#             */
/*   Updated: 2023/02/02 16:16:46 by mvolpi           ###   ########.fr       */
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

void print_export(t_shell *shell, char **str_save)
{
	int i;
	int j;
	int k;

	i = -1;
	k = 0;
	while (shell->env.current[++i])
	{
		j = ft_strchrp(shell->env.current[i], '=');
		while (j >= 0)
		{
			str_save[0][k] = shell->env.current[i][k];
			j--;
			k++;
		}
		j = ft_strchrp(shell->env.current[i], '=');
		k = 0;
		while (shell->env.current[i][++j])
		{
			str_save[1][k] = shell->env.current[i][j];
			k++;
		}
		printf("declare -x %s%c", str_save[0], 34);
		printf("%s%c\n", str_save[1], 34);
	}
	(void)str_save;
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

void	ft_export(t_shell *shell)
{
	char **str_save;

	shell->exp.i = -1;
	shell->exp.j = -1;
	str_save = (char **)malloc(sizeof(char *) * (3));
	if (!shell->lst.executor[1])
	{
		shell->exp.sort_env = sort(shell->env.current);
		shell->exp.i = -1;
		print_export(shell,str_save);
	}
	else
	{
		while (shell->env.current[++shell->exp.i])
		{
			shell->exp.pos = ft_strchrp(shell->env.current[shell->exp.i], '=');
			if (ft_strncmp(shell->env.current[shell->exp.i], \
						shell->lst.executor[1], shell->exp.pos + 1) == 0)
			{
				shell->env.current[shell->exp.i] = shell->lst.executor[1];
				shell->exp.j = 0;
			}
		}
		if (shell->exp.j == -1)
		{
			shell->env.current[shell->exp.i] = shell->lst.executor[1];
			shell->env.current[shell->exp.i + 1] = NULL;
		}
	}
	return ;
}
