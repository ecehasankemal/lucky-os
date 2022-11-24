/*GNU GENERAL PUBLIC LICENSE

Version 3, 29 June 2007

Copyright © 2007 Free Software Foundation, Inc. <https://fsf.org/>

Everyone is permitted to copy and distribute verbatim copies of this license document, but changing it is not allowed.*/


#include "string.h"

// ############################################################

// Dizinin türü farketmeksizin n kadar cpy işlemi yapmamı sağlar

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*str;
	char	*str2;
	size_t	index;

	index = 0;
	str = (char *)dest;
	str2 = (char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (index < n)
	{
		str[index] = str2[index];
		index++;
	}
	return (dest);
}

/*#include <string.h>
#include <stdio.h>
int	main(void)
{
	char		*ds1 = malloc(sizeof(char) * 5);
	char		*ds2 = malloc(sizeof(char) * 5);
	const char	*sr = "hece";
	printf("mine : %s, ", ft_memcpy(ds2, sr, 5));
	printf("org : %s, ", memcpy(ds1, sr, 5));
}*/

// #################################################################

// #################################################################

// Tıpkı strncmp gibi tepki verir lakin tek farkı stringin türü önemsizdir
// vesselam...

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	index;

	index = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	while ((str1[index] == str2[index]) && (str1[index] != '\0')
		&& (str2[index] != '\0') && (index < n))
		index++;
	return ((unsigned char)str1[index] - (unsigned char)str2[index]);
}

/*#include <string.h>
#include <stdio.h>
int	main(void)
{
	char		*ds1 = malloc(sizeof(char) * 5);
	char		*ds2 = malloc(sizeof(char) * 5);
	const char	*sr = "hece";
	printf("mine : %s, ", ft_memcpy(ds2, sr, 5));
	printf("org : %s, ", memcpy(ds1, sr, 5));
}*/

// ###########################################################

// ###########################################################

// Eğer src destten byük olursa cpy işlemi yapar
// ama kçük olursa len değerinin belirtigi indexten
// başlayıp geriye doğru indexleri src den deste eşitler
// void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*str;
	char	*str2;
	size_t	index;

	index = 0;
	str = (char *)dest;
	str2 = (char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (str2 < str)
		while (++index <= len)
			str[len - index] = str2[len - index];
	else
		return (ft_memcpy(dest, src, len));
	return (dest);
}
/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	*a = malloc(sizeof(char) * 5);
	char	*b = malloc(sizeof(char) * 5);
	char	*src = "ahmet";
	printf("org : %s, ", memmove(a, src, 4));
	printf("ft_ : %s", ft_memmove(b ,src , 4));
}*/

// ###########################################################

// ###########################################################

// ptr dizisinin bytelenght' ye kadar value byte' i doldurur

void	*ft_memset(void *ptr, int value, size_t bytelenght)
{
	char	*str;
	size_t	index;

	index = 0;
	str = (char *)ptr;
	while (index < bytelenght)
	{
		str[index] = value;
		index++;
	}
	return (ptr);
}

/*void	ft_putstr(char *str)
{
	int	index;
	index = 0;
	while (index < sizeof(str))
	{
		if (str[index] == '\0')
			index++;
		write(1, &str[index], 1);
		index++;
	}
}*/
/*
int	main(void)
{
	char	a[] = "hece\n";
	char	mete[] = "hece";
	ft_putstr(a);
	ft_bzero(a, 3);
	ft_putstr(a);
	//ft_memset(mete, 'b', 3);
	//ft_putstr(mete);
}*/

// ###########################################################

// ###########################################################
// Girilen stringin uzunlugu ölçmemize yarar

// size_t ise stdlib kütüphanesinde kullanılan
// unsigned int tanımlamak için olusturulmuş bir yapıdır

size_t	ft_strlen(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

/*#include <stdio.h>
int	main(void)
{
	char	a[] = "hece";
	int	b;
	b = ft_strlen(a);
	printf("%d", b);
}*/

// #############################################################

// #############################################################

// Girilen char bir stringin sayı olan kısmını
// int bir değere dönüştürme işlemi yapar
// örnek vermek gerekirse eğer
// "     -213dsfıjsdf" olan stringimden int -213
// sonucunu alırım vesselam...

int	ft_atoi(char *str)
{
	int	iter;
	int	dop;
	long	result;

	iter = 0;
	dop = 1;
	result = 0;
	while ((str[iter] >= '\t' && str[iter] <= '\r') || str[iter] == ' ')
		iter++;
	if (str[iter] == '+' || str[iter] == '-')
	{
		if (str[iter] == '-')
			dop *= -1;
		iter++;
	}
	while (str[iter] >= '0' && str[iter] <= '9' && str[iter] != '\0' && result <= 2147483648)
	{
		result = ((str[iter] - '0') + (result * 10));
		iter++;
	}
	result = result * dop;
	if (result < -2147483648)
		return (-2147483648);
	if (result > 2147483647)
		return (2147483647);
	return (result);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%d", myAtoi("2000"));
}*/

// ###############################################################

// ###############################################################

// Bu fonksiyonda girilen int değerinin önce basamak sayısını hesaplıyoruz
// ft_get_size fonksiyonunu bunun için olusturduk daha sonra
// mallocla yer açıp null mu döndrüyor diye kontrol ediyoruz
// ben int n değerini long bir degere eşitlemeyi tercih ettim bu sekilde
// moulinette den kaçmış oluyoruz sj
// neyse değer eksi ise res imize - karakterini
// ekleyip geri kalan sayıyı pozitife dönştürüp
//  ft_fill_res fonksiyonumuza atıyoruz
// ki orda % alıp + '0' yaparak son karaktetri sondan başlayarak resimize
// atıyoruz
// ve en sonunda sonuna null ekleyip döndrüyoruz vesselam...

int	ft_get_size(int x)
{
	int	result;

	result = 0;
	if (x < 0)
		result++;
	while (x)
	{
		x = x / 10;
		result++;
	}
	return (result);
}

static void	ft_fill_res(int size, int offset, int n, char *result)
{
	while (size > offset)
	{
		result[size - 1] = n % 10 + '0';
		n = n / 10;
		size--;
	}
}

char	*ft_itoa(int x)
{
	int	offset;
	int	size;
	char	*result;

	offset = 0;
	size = ft_get_size(x);
	result = ((char *)malloc(sizeof(char) * size + 1));
	if (result == NULL)
		return (NULL);
	if (x == -2147483648)
	{
		result[0] = '-';
		result[1] = '2';
		x = 147483648;
		offset += 2;
	}
	else if (x < 0)
	{
		result[0] = '-';
		x *= -1;
		offset += 1;
	}
	ft_fill_res(size, offset, x, result);
	result[size] = '\0';
	return (result);
}

/*#include <stdio.h>
int	main(void)
{
	int	a = -2147483648;
	printf("org value is :'-456', my value is :'%s'", ft_itoa(a));
}*/

// ##################################################################
