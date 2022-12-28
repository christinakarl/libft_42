#include "../include/ft_printf.h"

int     ft_xlen(unsigned int n)
{
        int     len;

        len = 0;
        while (n > 0)
        {
                len++;
                n = n / 16;
        }
        return (len);
}

void    ft_nbr_hex(unsigned int n, char minmaj)
{
        if (n >= 16)
        {
                ft_nbr_hex(n / 16, minmaj);
                ft_nbr_hex(n % 16, minmaj);
        }
        else
        {
                if (n <= 9)
                        ft_put_c((int)n + 48);
                else
                {
                        if (minmaj == 'x')
                                ft_put_c((int)n + 87);
                        else
                                ft_put_c((int)n + 55);
                }
        }
}

int     ft_put_hex(unsigned int n, char minmaj)
{
        int     len;

        len = 0;
        ft_nbr_hex(n, minmaj);
        len = ft_xlen(n);
        return (len);
}

