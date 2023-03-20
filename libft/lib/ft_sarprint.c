#include "../h_file/libft.h"

int	ft_sarprint(char **sar)
{
	int	i;
	int	ret;

	i = -1;
	ret = 0;
	if (!sar || !sar[0])
		return (0);
	ft_printf("---SPLITTED ARGS---\n");
	while (sar[++i] && sar[i] != 0)
	{
		ret += ft_printf("\"%s\"\n", sar[i]);
	}
	ft_printf("-----########-----\n");
	return (ret);
}