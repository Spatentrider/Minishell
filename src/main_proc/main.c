/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:15:53 by mvolpi            #+#    #+#             */
/*   Updated: 2023/01/09 14:36:57 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_proc.h"

int	search(const char *s, const char *c)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	printf ("%c\n", c[0]);
	while (s[++i])
		cnt++;
	i = 0;
	while (cnt != 0)
	{
		if (s[i] == c[0])
		{
			c = 0;
			return (0);
		}
		i++;
		cnt--;
	}
	return (1);
}

/**
 * @brief the start of the program that checks for errors,
 * saves the enviroment in a list and sets up a new prompt
 * waiting for a command and for now if in input there is
 * exit the program exit with no errors
 * 
 * @param argc number of argument in input from the teminal with which
 * we check that to start the programm only ./minishell is given in input
 * @param argv counter of argument in input from the terminal that
 * we set up at void because it is not needed within the program but
 * we need to call the force to have envp
 * @param envp an array where we have all the enviroment variables and we
 * need to save in a list where we can modify each variable to our liking
 * @return int return a 0 for now
 */
int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	int		i;

	i = -1;
	if (argc > 1)
		exit(printf("Error, there are too many argument!!"));
	(void)argv;
	get_env(envp, &shell);
	while (1)
	{
		shell.lst.input = readline("minishell: ");
		shell.lst.split = ft_split(shell.lst.input, '|');
		i = -1;
		if (!shell.lst.input)
			exit(0);
		while (shell.lst.split[++i])
			printf("%s\n", shell.lst.split[i]);
	}
	return (0);
}
