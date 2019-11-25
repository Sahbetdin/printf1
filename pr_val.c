#include "header.h"

// void pr_val(char *fmt, ...)
// {
// 	va_list ap;
// 	int i;

// 	va_start(ap, fmt);
// 	i = 0;
// 	while (i < 1)
// 	{
// 		printf("%s\n", va_arg(ap, const char *));
// 		i++;
// 	}

// 	va_end(ap);
// }

 
// void varstrings(char *fmt, ...)   /* the ellipsis indicates variable arguments */
// {
//     va_list args;
//     int i;

//     va_start(args, fmt);
//     printf("%s\n", fmt);
    
//     i = 0;
//     while (i < 2)
//     {
//         printf("%s\n", va_arg(args, const char *));
//         i++;
//     }
//     va_end(args);
// }

// void putcf( float f )
// {
//     char buf[10] = {0};
//     size_t x;
 
//     for( x = 0, sprintf( buf, "%f", f ); x < strlen( buf ); x++ )
//         putchar( buf[ x ] );
// }


int ft_printf(char *fmt, ...)
{
	va_list ap;
	char *p;
	int c;
	int ret;

	va_start(ap, fmt);
	p = fmt;
	ret = 0;
	while (*p)
	{
		if (*p == '%')
		{
			p++;
			if (*p == 'd')
				ret = ft_putnbr(va_arg(ap, int));
			else if (*p == 'c')
				ret = ft_putchar(va_arg(ap, int));
			else if (*p == 's')
				ret = ft_putstr(va_arg(ap, char *));
		}
		else
			ft_putchar(*p);
		p++;
	}
	

	va_end(ap);
	return (ret);
}

/*returns # of digits before . */
int pref_digits(double a)
{
	int i;

	i = 0;
	while (a > 1)
	{
		a /= 10;
		i++;
	}
	return (i);
}

/*returns # of digits after . */
int suf_digits(double a)
{
	int i;
//return int
	return ((int)a);
	// i = 0;
	// while (1)
	// {
	// 	if (a)
	// 	a *= 10;
	// 	i++;
	// }
}

void ft_putdouble(double a, int prec)
{
	long d;

	if (a < 0)
	{
		ft_putchar('-');
		a = -a;
	}
	d = a;
	ft_putlong(d);
	ft_putchar('.');
 	while (prec)
 	{
 		a = (a - d) * 10;
 		d = a;
 		if (prec == 1)
 		{
			if ((a - (long)a) * 10 > 4)
				d += 1;
 		}
		ft_putchar(d + '0');
 		prec--;
 	}
}


int main()
{
	double x;

	x = 3.1415678;
//	ft_putdouble(x, 4);
//	printf("%4.2f\n", x);
	printf("%06.4f\n", 6.287);

//	ft_putlong(4);
//	ft_putlong(0);
	// ft_putlong(10);
	 //ft_putlong(-10);
	// ft_putlong(1000);
	// ft_putlong(3003);

	//implement va_start and va_arg
// it means that in function print_param(char *fmt, ...)
// you need to putstr fmt , etc.
//	func("goinz", 3);
	

	// double x;
	// int c;

	// x = 23.9999999999999984;
	// c = suf_digits(x);
	// printf("%d\n", c);


//	 printf("%f\n", c);
//	ft_printf("%s\n", g);
//	printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
//	printf ("floats:%7.4f \n", 3.1416);

//	varstrings("Mary", 423, "a", "little", "lamb");
//	pr_val("Hello", "2", "4");
	return (0);
}


/*

//сделать массив указателей на функцию
int add(int a, int b)
{
	return (a + b);
}

int substr(int a, int b)
{
	return (a - b);
}

int multiply(int a, int b)
{
	return (a * b);
}


int operation(int a, int b, int (*f)(int, int))
{
	return (f(a, b));
}


*/