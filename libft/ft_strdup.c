#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	void	*p2;

	size = ft_strlen(s);
	p2 = malloc((size + 1) * sizeof(char));
	if (p2)
		ft_memcpy(p2, s, size + 1);
	else
		errors("うーんシェル: fatal error mallocing in strdub: exiting\n");
	return (p2);
}
