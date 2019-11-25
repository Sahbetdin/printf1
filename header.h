# ifndef __HEADER_H__
# define __HEADER_H__

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

int		ft_putchar(char c);
size_t	ft_strlen(const char *s);
int		ft_putstr(char const *s);
int		ft_putnbr(int n);
int		ft_putlong(long n);
char	*ft_strchr(const char *s, int c);
#endif