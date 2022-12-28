#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

int	ft_putchar(char c);
int	ft_putnbr(int nbr);
int	ft_putstr(char *str);
int	print_u(unsigned int nbr);
int	ft_pointer(unsigned long long n, char *base);
int	print_hex(unsigned int n, char *base);
int	ft_printf(const char	*str, ...);

#endif
