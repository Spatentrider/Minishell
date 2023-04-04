#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024

int	ft_sarprint(char **sar)
{
	int	i;
	int	ret;

	i = -1;
	ret = 0;
	if (!sar || !sar[0])
		return (0);
	printf("---SPLITTED ARGS---\n");
	while (sar[++i] && sar[i] != 0)
	{
		ret += printf("\"%s\"\n", sar[i]);
	}
	printf("-----########-----\n");
	return (ret);
}

int	ft_sarsize(char **tocount)
{
	int	j;

	j = -1;
	if (!tocount)
		return (0);
	while (tocount[++j])
		;
	return (j);
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char *token;

    printf("Inserisci il comando: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    printf("input è %s\n", input);
    // Rimuove il carattere di nuova linea dal comando inserito
    input[strcspn(input, "\n")] = 0;

    // Divide il comando inserito in token separati dallo spazio
    token = strtok(input, " ");
    // Crea un array di stringhe per gli argomenti del comando
    char *args[MAX_INPUT_LENGTH];
    int i = 0;

    while (token != NULL) {
        if (strcmp(token, "<") == 0) {
            token = strtok(NULL, " ");
            // Apre il file in input e lo associa allo stdin
            freopen(token, "r", stdin);
        } else if (strcmp(token, ">") == 0) {
            token = strtok(NULL, " ");
            // Apre il file in output e lo associa allo stdout
            freopen(token, "w", stdout);
        } else {
            args[i] = token;
            i++;
        }
        token = strtok(NULL, " ");
    }
    args[i] = NULL; // Aggiunge un elemento NULL alla fine dell'array di stringhe

    ft_sarprint(args);
    
    // Esegue il comando con gli eventuali operatori '<' e '>'


    return 0;
}
