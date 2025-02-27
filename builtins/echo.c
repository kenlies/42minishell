#include "../minishell.h"

int	echo_do(char ***args)
{
	int	j;

	j = 2;
	while ((**args)[j] && (**args)[j] == 'n')
		j++;
	if ((**args)[j] == '\0')
	{
		(*args)++;
		return (0);
	}
	return (1);
}

int	echo(char **args)
{
	int	nl;

	nl = 1;
	if (!args[1] || (args[1][0] == '\0' && !args[2]))
	{
		ft_printf("\n");
		return (0);
	}
	if (++args && !ft_strncmp(*args, "-n", 2))
		nl = echo_do(&args);
	while (*args)
	{
		ft_printf("%s", *args);
		if (*args && **args)
			ft_printf(" ");
		args++;
	}
	if (nl)
		ft_printf("\n");
	return (0);
}
