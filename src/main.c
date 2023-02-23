/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:15:53 by mvolpi            #+#    #+#             */
/*   Updated: 2023/02/15 15:36:29 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

int	check_error_cod(t_shell *shell)
{
	int	i;

	i = -1;
	shell->lst.error = ft_split(shell->lst.input, ' ');
	while (shell->lst.error[++i])
	{
		g_exit = parse(shell->lst.split);
	}
	return (g_exit);
}

void	ctrl_d(t_shell *shell)
{
	if (!shell->lst.input)
	{
		printf("Exiting...\n");
		exit(0);
	}
}

int	loop(t_shell *shell, int i, int j)
{
	int k;
	int p;

	k = -1;
	p = 0;
	while (1)
	{	
		shell->lst.input = readline("minishell: ");
		ctrl_d(shell);
		while(shell->lst.input[++k])
		{
			if (shell->lst.input[k] == ' ')
				p = 1;
			else
			{
				p = 0;
				break;
			}
		}
		if (p == 0)
		{
			shell->lst.split = split_cmd(shell->lst.input);
			shell->lst.redirection = NULL;
			if (ft_strncmp(shell->lst.input, "", 1))
				add_history(shell->lst.input);
			g_exit = check_error_cod(shell);
			if (g_exit == 0 && ft_strncmp(shell->lst.input, "", 1) != 0)
			{
					check_operator(shell);
			}
			dup2(i, STDOUT_FILENO);
			dup2(j, STDIN_FILENO);
			shell->old_g_exit = g_exit;
			g_exit = 0;
		}
		p = 0;
		k = -1;
	}
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


	(void)argv;
	g_exit = 0;
	if (argc > 1)
		exit(printf("Error, there are too many argument!!"));
	get_env(envp, &shell);
	shell.stdout = dup(STDOUT_FILENO);
	shell.stdin = dup(STDIN_FILENO);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, signal_handler);
	loop(&shell, shell.stdout, shell.stdin);
	return (0);
}
