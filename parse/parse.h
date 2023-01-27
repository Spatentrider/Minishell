#ifndef PARSE_H
# define PARSE_H

# include "../h_file/minishell.h"

size_t	ft_strlen(const char *s);
int	is_separator(char c);
int	check_pipe(char *string);
int	check_redirection(char *string);
int check_quote(char *string);
int	check_parameter(char *string, char c);
int	parse(char **string);

#endif