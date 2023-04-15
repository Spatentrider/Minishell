/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:16:13 by mich              #+#    #+#             */
/*   Updated: 2023/04/15 17:35:57 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"
#include <string.h>

int ft_strtok_loop(char *next_token,const char *delim, t_shell *shell)
{
    int match;
    match = 1;
    while(++shell->strtok.i < shell->strtok.delim_len) 
    {
        if (*next_token == delim[shell->strtok.i]) 
        {
            match = 0;
            break ;
        }
    }
    return(match);
}

void redirect_heredoc(char *delimiter, char *filename) 
{
    char *line = NULL;
    size_t len = 0;
    FILE *fp = fopen(filename, "w");

    if (!fp) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    while (1) {
        printf("> ");
        if (getline(&line, &len, stdin) < 0) {
            perror("getline");
            exit(EXIT_FAILURE);
        }
        if (strcmp(line, delimiter) == 0) {
            break;
        }
        fputs(line, fp);
    }
    free(line);
    fclose(fp);
}

char *ft_strtok(char *str, const char *delim, t_shell *shell) 
{
    static char *next_token = NULL;

    if (str != NULL) 
        next_token = str;
	else if (next_token == NULL) 
        return NULL;
    shell->strtok.result = next_token; 
    shell->strtok.delim_len = strlen(delim);
    while (*next_token != '\0') 
	{
        shell->strtok.i = -1;
        shell->strtok.match = ft_strtok_loop(next_token, delim, shell);
        if (shell->strtok.match) 
            next_token++;
		else 
		{
            *next_token = '\0';
            next_token++;
            return shell->strtok.result;
        }
    }
    next_token = NULL;
    return shell->strtok.result;
}

void	mix_redirection(t_shell *shell)
{
	char *token;
	int fd;
    char *input;
    int i;
    int flag;

    input = ft_strdup(shell->lst.input);
    flag = 0;
	token = ft_strtok(input, " ", shell);
    if (ft_strncmp(token, "cat", 4) == 0)
        flag = 1;
    shell->lst.delete_str = (char **)malloc(sizeof(char *) * 40000);
    i = 0;
	while (token != NULL) 
	{
        if (strcmp(token, "<") == 0) 
        {
            token = ft_strtok(NULL, " ", shell);
            shell->lst.delete_str[i] = ft_strdup(token);
            fd = open(token, O_RDONLY);
            if (fd < 0) 
                perror("Errore nell'apertura del file");
            dup2(fd, STDIN_FILENO);
            close(fd);
            i++;
        } 
		else if (strcmp(token, ">") == 0) 
		{
            token = ft_strtok(NULL, " ", shell);
            shell->lst.delete_str[i] = ft_strdup(token);
            fd = open(token, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd < 0) 
                perror("Errore nell'apertura del file");
            dup2(fd, STDOUT_FILENO);
            if (shell->here_cat == 1)
            {
                shell->echo.i = -1;
                while (shell->lst.cat_array[++shell->echo.i])
                    printf("%s\n", shell->lst.cat_array[shell->echo.i]);
                ft_sarfree(shell->lst.cat_array, ft_sarsize(shell->lst.cat_array));
            }
            shell->redirection_out = dup(STDOUT_FILENO);
            close(fd);
            i++;
        }
		else if (strcmp(token, ">>") == 0) 
		{
            token = ft_strtok(NULL, " ", shell);
            shell->lst.delete_str[i] = ft_strdup(token);
            fd = open(token, O_WRONLY | O_CREAT | O_APPEND, 0644);
            if (fd < 0) 
			{
                perror("Errore nell'apertura del file");
            }
            dup2(fd, STDOUT_FILENO);
            shell->redirection_out = dup(STDOUT_FILENO);
            close(fd);
            i++;
    	}
        else if (strcmp(token, "<<") == 0) 
        {
            token = ft_strtok(NULL, " ", shell);
            shell->lst.delete_str[i] = ft_strdup(token);
            if (flag == 2)
            {
                here_doc(token, shell);
            }
            else
            {
                here_doc_cat(token, shell);
                flag = 3;
            }
            i++;
		}
        token = ft_strtok(NULL, " ", shell);
        if (token != NULL)
        {
            if (ft_strncmp(token, ">", 1) != 0 && \
                ft_strncmp(token, "<", 1) != 0 && \
                ft_strncmp(token, ">>", 2) != 0 && \
                ft_strncmp(token, "<< ", 2) != 0)
                    flag = 2;
        }
    }
    shell->lst.delete_str[i] = NULL;
    free(input);
    delete_op(shell);
    if (flag != 3)
        executor(shell);
}
