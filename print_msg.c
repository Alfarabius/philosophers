#include "philosophers.h"

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static	int	ft_symamount(int n)
{
	size_t	symb_amount;

	symb_amount = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		symb_amount += 1;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		symb_amount++;
	}
	return (symb_amount);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (!d && !s)
		return (NULL);
	while (n--)
		*(d++) = *(s++);
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	dest_size;

	dest_size = ft_strlen(s1) + 1;
	dest = (char *)malloc(dest_size * sizeof(char));
	if (NULL == dest)
		return (NULL);
	ft_memcpy(dest, s1, dest_size);
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*n_str;
	int		size;
	int		i;

	i = 0;
	size = ft_symamount(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n_str = (char *)malloc(size + 1);
	if (!n_str)
		return (NULL);
	if (n < 0)
	{
		n_str[0] = '-';
		n *= -1;
		i += 1;
	}
	n_str[size] = '\0';
	while (size-- > i)
	{
		n_str[size] = (char)(n % 10 + '0');
		n /= 10;
	}
	return (n_str);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	i;

	dst_len = 0;
	i = 0;
	while (dst[dst_len] && dst_len < dstsize)
		dst_len++;
	if (dst_len < dstsize)
	{
		while (src[i] && (dst_len + i) < dstsize - 1)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[i + dst_len] = '\0';
	}
	return (dst_len + ft_strlen(src));
}

char	*ft_strrejoin(char const *s1, char const *s2)
{
	char	*joined_string;
	size_t	length;

	if (!s1 || !s2)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined_string = (char *)malloc(length);
	if (!joined_string)
		return (NULL);
	ft_memcpy(joined_string, s1, length);
	ft_strlcat(joined_string, s2, length);
	return (joined_string);
}

void	print_msg(time_t time, uint64_t number, STRING msg)
{
	STRING	str1;
	STRING	str2;
	STRING	str;

	str1 = ft_itoa((int)time);
	str = ft_strrejoin(str1, " ");
	free(str1);
	str1 = ft_itoa((int)number);
	str2 = ft_strrejoin(str, str1);
	free(str);
	free(str1);
	str = ft_strrejoin(str2, " ");
	free (str2);
	str1 = ft_strrejoin(str, msg);
	free(str);
	write(1, str1, ft_strlen(str1));
	free(str1);
}
