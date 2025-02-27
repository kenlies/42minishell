#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*sub;
	int		i;

	if (len >= ft_strlen(s))
		len = ft_strlen(s);
	if (!s)
		return (NULL);
	i = 0;
	sub = (char *)(malloc(sizeof(char) * len + 1));
	if (!sub)
		errors("うーんシェル: fatal error mallocing in substr: exiting\n");
	if ((int)start >= ft_strlen(s))
	{
		sub[i] = '\0';
		return (sub);
	}
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
