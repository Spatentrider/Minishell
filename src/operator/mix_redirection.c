#include "operator.h"

#include <string.h>

char *ft_strtok(char *str, const char *delim) 
{
    static char *next_token = NULL; 
    if (str != NULL) 
        next_token = str;
	else if (next_token == NULL) 
        return NULL;
    char *result = next_token; 
    size_t delim_len = strlen(delim);
    while (*next_token != '\0') 
	{
        int match = 1;
        for (size_t i = 0; i < delim_len; i++) 
		{
            if (*next_token == delim[i]) 
			{
                match = 0;
                break;
            }
        }
        if (match) 
            next_token++;
		else 
		{
            *next_token = '\0';
            next_token++;
            return result;
        }
    }
    next_token = NULL;
    return result;
}

void	mix_redirection(t_shell *shell)
{
	char *token;
	int fd;

	token = ft_strtok(shell->lst.input, " ");
	while (token != NULL) 
		{
        	if (strcmp(token, "<") == 0) 
			{
            token = ft_strtok(NULL, " ");
            // Apre il file in input e lo associa allo stdin
            int fd = open(token, O_RDONLY);
            if (fd < 0) 
			{
                perror("Errore nell'apertura del file");
            }
            dup2(fd, STDIN_FILENO);
            close(fd);
        } 
		else if (strcmp(token, ">") == 0) 
		{
            token = ft_strtok(NULL, " ");
            // Apre il file in output e lo associa allo stdout
            fd = open(token, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd < 0) 
			{
                perror("Errore nell'apertura del file");
            }
            dup2(fd, STDOUT_FILENO);
            close(fd);
        }
		else if (strcmp(token, ">>") == 0) 
		{
            token = ft_strtok(NULL, " ");
            int fd = open(token, O_WRONLY | O_CREAT | O_APPEND, 0644);
            if (fd < 0) 
			{
                perror("Errore nell'apertura del file");
            }
            dup2(fd, STDOUT_FILENO);
            close(fd);
    	}
		token = ft_strtok(NULL, " ");
		}
	executor(shell);
}