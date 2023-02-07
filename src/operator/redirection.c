#include "operator.h"

void	red_out(char **redirection)
{
	int i;

	printf("cwcewceecew");
	i = open(redirection[1],O_WRONLY | O_CREAT | O_TRUNC,
            S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	dup2(i,STDOUT_FILENO);
	
}
