/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalkan <ikalkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:15:52 by ikalkan           #+#    #+#             */
/*   Updated: 2025/09/04 11:41:46 by ikalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_format(const char *format, va_list args, int *count)
{
	int	ret;

	ret = 0;
	if (*format == 'c')
		ret = ft_putchar(va_arg(args, int), count);
	else if (*format == 's')
		ret = ft_putstr(va_arg(args, char *), count);
	else if (*format == 'p')
		ret = ft_putptr(va_arg(args, void *), count);
	else if (*format == 'd' || *format == 'i')
		ret = ft_putnbr(va_arg(args, int), count);
	else if (*format == 'u')
		ret = ft_putunsigned(va_arg(args, unsigned int), count);
	else if (*format == 'x')
		ret = ft_puthex(va_arg(args, unsigned int), 0, count);
	else if (*format == 'X')
		ret = ft_puthex(va_arg(args, unsigned int), 1, count);
	else if (*format == '%')
		ret = ft_putchar('%', count);
	else
		return (-1);
	return (ret);
}

static int	handle_percent(const char **format, va_list args, int *count)
{
	int	ret;

	(*format)++;
	if (!**format)
		return (-1);
	ret = handle_format(*format, args, count);
	if (ret == -1)
		return (-1);
	(*format)++;
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (handle_percent(&format, args, &count) == -1)
			{
				va_end(args);
				return (-1);
			}
		}
		else if (ft_putchar(*format++, &count) == -1)
		{
			va_end(args);
			return (-1);
		}
	}
	va_end(args);
	return (count);
}
