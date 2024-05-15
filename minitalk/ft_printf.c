/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyildir <ahyildir@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:20:45 by ahyildir          #+#    #+#             */
/*   Updated: 2023/12/25 14:20:46 by ahyildir         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *str)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	if (!str)
	{
		len += ft_putstr("(null)");
		return (len);
	}
	while (str[++i])
		len += ft_putchar(str[i]);
	return (len);
}

int	ft_convertbase(unsigned long long nb, int base, char *str, int mod)
{
	int	len;
	int	i;
	int	tmp_lst[100];

	len = 0;
	i = 0;
	if (mod == 1 && (long)nb < 0)
	{
		nb *= -1;
		len += ft_putchar('-');
	}
	if (mod == 2)
		len += ft_putstr("0x");
	if (nb == 0)
		len += ft_putchar('0');
	while (nb > 0)
	{
		tmp_lst[i++] = nb % base;
		nb /= base;
	}
	while (i-- > 0)
		len += ft_putchar(str[tmp_lst[i]]);
	return (len);
}

int	ft_checkformat(va_list ap, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (format == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (format == 'p')
		len += ft_convertbase(va_arg(ap, unsigned long long), 16,
				"0123456789abcdef", 2);
	else if (format == 'd' || format == 'i')
		len += ft_convertbase(va_arg(ap, int), 10, "0123456789", 1);
	else if (format == 'u')
		len += ft_convertbase(va_arg(ap, unsigned int), 10, "0123456789", 1);
	else if (format == 'x')
		len += ft_convertbase(va_arg(ap, unsigned int), 16, "0123456789abcdef",
				1);
	else if (format == 'X')
		len += ft_convertbase(va_arg(ap, unsigned int), 16, "0123456789ABCDEF",
				1);
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int	len;

	va_list(ap);
	i = -1;
	len = 0;
	va_start(ap, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_checkformat(ap, str[i]);
		}
		else
			len += ft_putchar(str[i]);
	}
	va_end(ap);
	return (len);
}
