#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int	l;

	l = 0;
	while (s[l] != '\0')
		l++;
	return (l);
}

int	is_separator(char c)
{
	if (c == '\0')
		return (1);
	else if (c == '|')
		return (2);
	else if (c == '>')
		return (3);
	else if (c == '<')
		return (4);
	else if (c == '\0')
		return (1);
	return (0);
}

int	check_pipe(char *string)
{
	size_t i;
	i = ft_strlen(string);
	if(i > 1)
	{
		printf("double pipe is not alowed");
		return(1);
	}
	return (0);
}

int	check_redirection(char *string)
{
	size_t i;
	i = ft_strlen(string);
	if(i > 2)
	{
		printf("no more then 2 redirection");
		return(1);
	}
	if(i > 1 && (string[0] == '>' && string[0] != string[1]))
	{
		printf("redirection >< is not alowed");
		return(1);
	}
	return (0);
}

int check_quote(char *string, char c)
{
	size_t i;
	i = ft_strlen(string);
	if (i == 2)
	{
		printf("command not found");
		return(1);
	}
	if((string[0] == 34 && string[i - 1] != 34) && (string[0] == 39 && string[i - 1] != 39))
	{
		printf("quote not closed");
		return(1);
	}
	return(0);
}

int	check_parameter(char *string, char c)
{
	if(c == '|')
		if(check_pipe(string))
			return (1);
	if(c == '<' || c == '>')
		if(check_redirection(string))
			return(1);
	if(c == 34 || c == 39)
		if(check_quote(string, c))
			return(1);
	return (0);
}

int	parse(char **string)
{
	int i;

	if(string[1][0] == '|')
	{
		printf("il carattere | non può essere all'inizio dell'array");
		return 1;
	}
	i = 1;
	while (string[i])
	{
		if(string[i][0] == '|' || string[i][0] == '<' || string[i][0] == '>' || string[i][0] == 34 || string[i][0] == 39)
			if(check_parameter(string[i], string[i][0]))
				return(1); 
		i++;
	}
	return 0;
}

int main (int ac, char **av)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if(parse(av))
		return 1;
}
