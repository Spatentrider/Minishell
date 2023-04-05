#include "operator.h"
#include <string.h>

void redirect_heredoc(char *delimiter, char *filename) {
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
    char *input;
    int i;

    input = ft_strdup(shell->lst.input);
	token = ft_strtok(input, " ");
    shell->lst.delete_str = (char **)malloc(sizeof(char *) * 40000);
    i = 0;
	while (token != NULL) 
		{
        	if (strcmp(token, "<") == 0) 
			{
            token = ft_strtok(NULL, " ");
            printf("%s\n", token);
            shell->lst.delete_str[i] = ft_strdup(token);
            // Apre il file in input e lo associa allo stdin
            fd = open(token, O_RDONLY);
            if (fd < 0) 
                perror("Errore nell'apertura del file");
            dup2(fd, STDIN_FILENO);
            close(fd);
            i++;
        } 
		else if (strcmp(token, ">") == 0) 
		{
            token = ft_strtok(NULL, " ");
            printf("%s\n", token);
            shell->lst.delete_str[i] = ft_strdup(token);
            fd = open(token, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd < 0) 
                perror("Errore nell'apertura del file");
            dup2(fd, STDOUT_FILENO);
            shell->redirection_out = dup(STDOUT_FILENO);
            close(fd);
            i++;
        }
		else if (strcmp(token, ">>") == 0) 
		{
            token = ft_strtok(NULL, " ");
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
            token = ft_strtok(NULL, " ");
            shell->lst.delete_str[i] = ft_strdup(token);
            here_doc(token, shell);
            i++;
		}
        token = ft_strtok(NULL, " ");
    }
    shell->lst.delete_str[i] = NULL;
    delete_op(shell);
	executor(shell);
}