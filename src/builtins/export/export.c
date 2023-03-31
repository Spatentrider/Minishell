/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:21:13 by mich              #+#    #+#             */
/*   Updated: 2023/03/31 11:24:59 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

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
		ft_sarfree(str_save, ft_sarsize(str_save));
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
		sort_env[c] = ft_strdup(sorting[i]);
	}
	return (sort_env);
}

int	change_var(t_shell *shell, int c)
{
	if (ft_strncmp(shell->lst.executor[c], "=", 1) == 0)
		printf("minishell: export: '=': not a valid identifier\n");
	shell->echo.j = 0;
	while (shell->env.current[++shell->exp.i])
	{
		shell->exp.pos = ft_strchrp(shell->env.current[shell->exp.i], '=');
		if (shell->exp.pos == 0)
		{
			while (shell->env.current[shell->exp.i][++shell->echo.j])
				;
			if (ft_strncmp(shell->env.current[shell->exp.i], \
					shell->lst.executor[c], shell->echo.j) == 0)
			{
				free(shell->env.current[shell->exp.i]);
				shell->env.current[shell->exp.i] = \
					ft_strdup(shell->lst.executor[c]);
				return (1);
			}
		}
		else if (ft_strncmp(shell->env.current[shell->exp.i], \
					shell->lst.executor[c], shell->exp.pos + 1) == 0)
		{
			free(shell->env.current[shell->exp.i]);
			shell->env.current[shell->exp.i] = \
				ft_strdup(shell->lst.executor[c]);
			return (1);
		}
	}
	return (0);
}

void	add_var(t_shell *shell, int c)
{
	int	i;
	int	j;

	i = -1;
	j = ft_sarsize(shell->env.current);
	shell->env.save = (char **)malloc(sizeof(char *) * j + 1);
	while (shell->env.current[++i])
		shell->env.save[i] = ft_strdup(shell->env.current[i]);
	shell->env.save[i] = NULL;
	ft_sarfree(shell->env.current, ft_sarsize(shell->env.current));
	shell->env.current = (char **)malloc(sizeof(char *) * j + 1);
	i = -1;
	while (shell->env.save[++i])
		shell->env.current[i] = ft_strdup(shell->env.save[i]);
	shell->env.current[i] = ft_strdup(shell->lst.executor[c]);
	shell->env.current[i + 1] = NULL;
	ft_sarfree(shell->env.save, ft_sarsize(shell->env.save));
}

void	ft_export(t_shell *shell)
{
	char	**str_save;
	int		c;

	c = 0;
	str_save = NULL;
	if (shell->lst.executor[1] == NULL)
	{
		shell->exp.sort_env = sort(shell->env.current);
		print_export(shell, str_save);
		ft_sarfree(shell->exp.sort_env, ft_sarsize(shell->exp.sort_env));
	}
	else
	{
		while (shell->lst.executor[++c])
		{
			shell->exp.j = -1;
			shell->exp.i = -1;
			if (!change_var(shell, c))
				add_var(shell, c);
		}
	}
}
