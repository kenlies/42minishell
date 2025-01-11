#include "libft.h"

char	*ft_strnjoin(int n, ...)
{
	int		i;
	size_t	len;
	char	*str;
	va_list	arg;
	va_list	argcpy;

	i = 0;
	len = 1;
	str = NULL;
	va_start(arg, n);
	va_copy(argcpy, arg);
	while (i++ < n)
		len += ft_strlen(va_arg(arg, char *));
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	ft_bzero(str, len);
	while (--i > 0)
		ft_strlcat(str, va_arg(argcpy, char *), len);
	va_end(arg);
	va_end(argcpy);
	return (str);
}
