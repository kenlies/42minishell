#include "../minishell.h"

int	pwd(void)
{
	char	cwd[PATH_LEN];

	if (getcwd(cwd, PATH_LEN))
	{
		printf("%s\n", cwd);
		return (0);
	}
	else
		return (1);
}
