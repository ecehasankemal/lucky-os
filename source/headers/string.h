/*GNU GENERAL PUBLIC LICENSE

Version 3, 29 June 2007

Copyright © 2007 Free Software Foundation, Inc. <https://fsf.org/>

Everyone is permitted to copy and distribute verbatim copies of this license document, but changing it is not allowed.*/

#ifndef	STRING_H
#define	STRING_H
#include <stdlib.h>
#include <stddef.h>

extern "C"
{
#endif

	void	*ft_memcpy(void *dest, const void *src, size_t n);
	int	ft_memcmp(const void *s1, const void *s2, size_t n);
	void	*ft_memmove(void *dest, const void *src, size_t len);
	void	*ft_memset(void *ptr, int value, size_t bytelenght);
	size_t	ft_strlen(const char *str);
	int	ft_atoi(char *str);
	int	ft_get_size(int x);
	static void	ft_fill_res(int size, int offset, int n, char *result);
	char	*ft_itoa(int x);
}
#endif
