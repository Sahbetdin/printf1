#include "header.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(char const *s)
{
	int n;

	if (s)
	{
		n = (int)ft_strlen(s);
		write(1, s, n);
		return (n);
	}
	else
		return (-1);
}

int	ft_putnbr(int n)
{
	unsigned int	m;
	int i;

	m = (n < 0) ? (unsigned int)-n : (unsigned int)n;
	if (n < 0)
		ft_putchar('-');
	if (m > 9)
		ft_putnbr(m / 10);
	ft_putchar(m % 10 + '0');
	return (i);
}

int        ft_putlong(long n)
{
	int     i;
	long    max_d;
	long    digit;

	i = 0;
	if (n < 0)
	{
	    ft_putchar('-');
	    n = -n;
	    i++;
	}
	max_d = 1;
	while (max_d <= n/10)
	    max_d *= 10;
	// printf("%ld\n", max_d);
	while (max_d)
	{
	    digit = n / max_d;
	    ft_putchar(digit + '0');
	    n -= max_d * digit;
	    max_d /= 10;
	    i++;
    }
    return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (*s == ch)
		return ((char *)s);
	return (NULL);
}
