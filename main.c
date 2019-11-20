/* 20 nov 14:23  */
/* delivery planned 8th dec or earlier */
/*
1. разобрать variadic fucntions,
1.1. попробовать распечатать кол-во аргументов
1.2

2. передача в качестве аргумента разные типы данных 

*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
void	ft_putstr(char const *s);
size_t	ft_strlen(const char *s);

void    minprintf(char *fmt, ...)
{
    va_list ap;
    char    *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt);
    for (p = fmt; *p; p++)
    {
        if (*p != '%')
        {
            putchar(*p);
            continue;
        }
        switch (*++p)
        {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                    write(1, sval, 1);
                break;
            default:
                write(1, p, 1);
                break;
        }
    }
    va_end(ap);
}

int summing(int n, ...)
{
    va_list ap;
    int     i;
    int     summ;

    va_start(ap, n);
    summ = 0;
    i = 0;
    while (i < n)
    {
        summ += va_arg(ap, int);
        i++;
    }
    va_end(ap);
    return (summ);
}

int main()
{
    int c;
    
    ft_putstr("gggg");
    minprintf("%d\n", ft_strlen("s"));
    c = summing(3,1,2,3,4,5);
    printf("%d\n", c);

    return EXIT_SUCCESS;
}