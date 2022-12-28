#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int	is_conv(char c);
void	print_decide(int *put, char const c, va_list args);
void	ft_put_c(int *put, va_list arg);

int	ft_printf(const char *print, ...)
{
	int			*put;
	va_list			args;
	int			len;
	int			i;

	i = 0;
	len = 0;
	put = &len;

	va_start(args, print);
	while (print[++i])
	{
		if (print[i] == '%')
		{
			if (is_conv(print[i + 1] == 1)
			{
				i++;
				print_decide(put, print[i], args);
			}
		}
		else
			len += write(1, &print[i], 1);
	}

	va_end(args);
	printf("%d\n", len);
	return (len);
}

int	is_conv(char const c)
{
	if (c == 'c')
		return (1);
	return (0);

}


void	ft_put_c(int *put, va_list args)
{
	char	a;

	a = va_args(args, int);
	put += write(1, &a, 1);
}


void	print_decide(int *put, char const c, va_list args)
{
	if (c == 'c')
		ft_put_c(put, args);
	else if (c = '%')
		put += write(1, "%", 1);
}

