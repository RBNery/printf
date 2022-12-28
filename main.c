#include <stdio.h>
#include "ft_printf.h"

int main()
{
	printf(" %p %p ", 0, 0);
	printf("\n");
	ft_printf(" %p %p ", 0, 0);
	return (0);
}

