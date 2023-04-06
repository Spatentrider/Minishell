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
    int flag;

    input = ft_strdup(shell->lst.input);
    flag = 0;
	token = ft_strtok(input, " ");
    if (ft_strncmp(token, "cat", 4) == 0)
        flag = 1;
    shell->lst.delete_str = (char **)malloc(sizeof(char *) * 40000);
    i = 0;
	while (token != NULL) 
	{
        if (strcmp(token, "<") == 0) 
        {
            token = ft_strtok(NULL, " ");
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
            token = ft_strtok(NULL, " ");
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
            }
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
            if (flag == 2)
            {
                printf("%d ao ao\n", flag);
                here_doc(token, shell);
            }
            else
            {
                printf("%d cat cat\n", flag);
                here_doc_cat(token, shell);
                flag = 3;
            }
            i++;
		}
        token = ft_strtok(NULL, " ");
        if (token != NULL)
        {
            if (ft_strncmp(token, ">", 1) != 0 && \
                ft_strncmp(token, "<", 1) != 0 && \
                ft_strncmp(token, ">>", 2) != 0 && \
                ft_strncmp(token, "<< ", 2) != 0)
                {
                    printf("token = %s\n", token);
                    flag = 2;
                }
        }
    }
    shell->lst.delete_str[i] = NULL;
    delete_op(shell);
    if (flag != 3)
    {
        printf("%d sdasds\n", flag);
	    executor(shell);
    }
}
