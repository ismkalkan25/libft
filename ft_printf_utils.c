/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalkan <ikalkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:18:19 by ikalkan           #+#    #+#             */
/*   Updated: 2025/09/04 11:41:39 by ikalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s, int *count)
{
	if (!s)
		s = "(null)";
	while (*s)
	{
		if (ft_putchar(*s++, count) == -1)
			return (-1);
	}
	return (0);
}

int	ft_putnbr(long n, int *count)
{
	if (n < 0)
	{
		if (ft_putchar('-', count) == -1)
			return (-1);
		n = -n;
	}
	if (n >= 10)
	{
		if (ft_putnbr(n / 10, count) == -1)
			return (-1);
	}
	if (ft_putchar((n % 10) + '0', count) == -1)
		return (-1);
	return (0);
}

int	ft_puthex(unsigned long n, int upper, int *count)
{
	char	*base;

	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
	{
		if (ft_puthex(n / 16, upper, count) == -1)
			return (-1);
	}
	if (ft_putchar(base[n % 16], count) == -1)
		return (-1);
	return (0);
}

int	ft_putptr(void *ptr, int *count)
{
	if (!ptr)
		return (ft_putstr("(nil)", count));
	if (ft_putstr("0x", count) == -1)
		return (-1);
	if (ft_puthex((unsigned long)ptr, 0, count) == -1)
		return (-1);
	return (0);
}

int	ft_putunsigned(unsigned int n, int *count)
{
	if (n >= 10)
	{
		if (ft_putunsigned(n / 10, count) == -1)
			return (-1);
	}
	if (ft_putchar((n % 10) + '0', count) == -1)
		return (-1);
	return (0);
}
