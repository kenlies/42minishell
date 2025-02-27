#include "libft.h"

static int	check_overflow(int n, int res)
{
	if (res < 0)
	{
		if (n == 1)
			return (0);
		else
			return (-1);
	}
	if (n == 1)
		return (res * -1);
	return (res);
}

int	ft_atoi(const char *str)
{
	int			i;
	long int	res;
	int			n;

	i = 0;
	res = 0;
	n = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = 1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (check_overflow(n, res));
}
