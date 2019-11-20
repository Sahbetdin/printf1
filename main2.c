#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

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

void	give_len(char *fmt, ...)
{
	// va_list ap;
	 char *p;

	// va_start(ap, fmt);
	// p = ap;
	// while (*p)
	// {
	// 	printf("%s ", p);
	// 	p++;
	// }

	va_list arg; 
	va_start(arg, fmt); 
	
	for(p = fmt; *p != '\0'; p++) 
	{ 
		printf("%s ", p);		
	}
	va_end(arg);
}


int main()
{
	int c;

	give_len("hello", "world", "\n", "\t", "  ");
	
	return (0);
}

