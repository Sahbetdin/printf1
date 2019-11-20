#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*ft_itoa_base(int value, int base);
size_t	ft_strlen(const char *s);
void	ft_putstr(char const *s);
int		digits(int value, int base);
int		abs_v(int num);

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char const *s)
{
	if (s)
        write(1, s, ft_strlen(s));
}

int digits(int value, int base)
{
	int i;

	i = 0;
	while (value)
	{
		value /= base;
		i++;
	}
	return (i);
}

int abs_v(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	char	*p;
	size_t	i;
	size_t	n;

	i = 0;
	p = (char *)s1;
	while (p[++i])
		;
	n = i;
	if (!(tmp = (char *)malloc(sizeof(char ) * (n + 1))))
		return (NULL);
	i = 0;
	while (i < n)
	{
		tmp[i] = p[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_itoa_base(int value, int base)
{
    char	*s;
	int		n;
	int		i;
	char	*letters;

	n = digits(abs(value), base);
	letters = ft_strdup("0123456789ABCDEF");


//	printf("in f: %d", n);

	if (value < 0)
		n += 1;
    s = (char *)malloc(sizeof(char) * (n + 1));

	if (value < 0)
	{
		s[0] = '-';
		value = -value;
	}
	s[n] = '\0';
	i = n - 1;
	while (value)
	{
		s[i] = letters[value % base];
		value /= base;
		i--;
	}
    return (s);
}

int main(void)
{
    char *str;

    str = ft_itoa_base(100000, 12);
	
	ft_putstr(str);
	free(str);
    return (0);
}
