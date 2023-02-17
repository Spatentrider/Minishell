#include "../h_file/libft.h"

int ft_count_arraystr(char **count)
{
	int i;
	i = -1;
	if(!count)
		return (0);
	while (count[++i])
		;
	return(i);
}