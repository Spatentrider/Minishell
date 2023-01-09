/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:15:53 by mvolpi            #+#    #+#             */
/*   Updated: 2023/01/05 15:56:40 by mvolpi           ###   ########.fr       */
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
	t_env	env_list;
	t_lst	input;

	if (argc > 1)
		exit(printf("Error, there are too many argument!!"));
	(void)argv;
	get_env(envp, &env_list);
	while (1)
	{
		input.input = readline("minishell: ");
		input.split = ft_split(input.input, ' ');
		if (!input.input)
			exit(0);
	}
	return (0);
}
