/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalkan <ikalkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:29:13 by ikalkan           #+#    #+#             */
/*   Updated: 2025/06/18 13:38:39 by ikalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_nulen(int c)
{
	int	len;

	if (c <= 0)
		len = 1;
	else
		len = 0;
	while (c != 0)
	{
		c = c / 10;
		len ++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nb;
	char	*arr;

	nb = n;
	len = ft_nulen(n);
	arr = malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	arr[len--] = '\0';
	if (nb == 0)
	{
		arr[0] = '0';
	}
	if (nb < 0)
	{
		arr[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		arr[len--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (arr);
}
