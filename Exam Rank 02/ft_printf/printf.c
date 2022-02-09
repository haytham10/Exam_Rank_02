#include <stdarg.h>
#include <unistd.h>

void	ft_putchar(int c, int *len)
{
	*len += write(1, &c, 1);
}

void	ft_putstr(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
		ft_putstr("(null)", len);
	else
	{
		while (str[i])
			ft_putchar(str[i++], len);
	}
}

static unsigned int	ft_va(int n)
{
	if (n < 0)
		return (n * (-1));
	else
		return (n);
}

void	ft_putnbr(int n, int *len)
{
	unsigned int	num;

	if (n < 0)
		ft_putchar('-', len);
	num = ft_va(n);
	if (num >= 10)
	{
		ft_putnbr((num / 10), len);
		ft_putnbr((num % 10), len);
	}
	else
		ft_putchar((num + '0'), len);
}

void	ft_puthexa(unsigned long nb, int *len)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 16)
	{
		ft_puthexa(nb / 16, len);
		ft_puthexa(nb % 16, len);
	}
	else
		ft_putchar(base[nb], len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	arg;

	i = 0;
	len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
				ft_putstr(va_arg(arg, char *), &len);
			else if (str[i] == 'd')
				ft_putnbr(va_arg(arg, int), &len);
			else if (str[i] == 'x')
				ft_puthexa(va_arg(arg, unsigned long), &len);
		}
		else
			ft_putchar(str[i], &len);
		i++;
	}
	va_end(arg);
	return (len);
}

int main()
{
	ft_printf("%d");
}