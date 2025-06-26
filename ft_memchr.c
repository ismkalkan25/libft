/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalkan <ikalkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:42:10 by ikalkan           #+#    #+#             */
/*   Updated: 2025/06/18 13:02:41 by ikalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t len)
{
	const unsigned char		*ch;
	size_t					i;

	ch = (const unsigned char *)s;
	i = 0;
	while (i < len)
	{
		if (ch[i] == (unsigned char)c)
			return ((void *)(ch + i));
		else
			i++;
	}
	return (NULL);
}
