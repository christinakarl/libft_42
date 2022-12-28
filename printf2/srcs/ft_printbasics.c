#include "../include/ft_printf.h"

int     ft_put_c(int i)
{
        char    a;

        a = (char)i;
        write(1, &a, 1);
        return (1);
}

int     ft_put_s(char *str)
{
        int     i;

        i = 0;
        while (str[i])
        {
                write(1, &str[i], 1);
                i++;
        }
        return (i);
}
