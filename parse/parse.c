#include <stdio.h>
#include <stdlib.h>

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

void check_pipe(char *string)
{
	printf("La pipe è presente come primo carattere nella stringa stringa");
}

void check_redirection(char *string)
{
	printf("La redirection è presente come primo carattere in una stringa");
}

void	parse(char **string)
{
	int i;
	int j;

	if(string[1][0] == '|')
		printf("il carattere | non può essere all'inizio dell'array");
	i = 0;
	while (string[i])
	{
		printf("%s\n",string[i]);
		i++;
	}
}

int main (int ac, char **av)
{
	int i;

	i = 1;
	parse(av);
}
