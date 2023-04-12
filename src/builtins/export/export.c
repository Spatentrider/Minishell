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

void	change_var(t_shell *shell, int c)
{
	if (ft_strncmp(shell->lst.executor[c], "=", 1) == 0)
		printf("minishell: export: '=': not a valid identifier\n");
	shell->echo.j = 0;
	while (shell->env.current[++shell->exp.i])
	{
		shell->exp.pos = ft_strchrp(shell->env.current[shell->exp.i], '=');
		if (shell->exp.pos == 1)
		{
			while (shell->env.current[shell->exp.i][++shell->echo.j])
				;
			if (ft_strncmp(shell->env.current[shell->exp.i], \
					shell->lst.executor[c], shell->echo.j) == 0)
			{
				free(shell->env.current[shell->exp.i]);
				shell->env.current[shell->exp.i] = \
					ft_strdup(shell->lst.executor[c]);
				shell->exp.j = 0;
			}
		}
		else if (ft_strncmp(shell->env.current[shell->exp.i], \
					shell->lst.executor[c], shell->exp.pos + 1) == 0)
		{
			free(shell->env.current[shell->exp.i]);
			shell->env.current[shell->exp.i] = \
				ft_strdup(shell->lst.executor[c]);
			shell->exp.j = 0;
		}
	}
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
			change_var(shell, c);
			if (shell->exp.j == -1)
			{
				shell->env.current[shell->exp.i] = \
					ft_strdup(shell->lst.executor[c]);
				shell->env.current[shell->exp.i + 1] = NULL;
			}
		}
	}
}
