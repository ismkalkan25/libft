/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalkan <ikalkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:58:51 by ikalkan           #+#    #+#             */
/*   Updated: 2025/06/19 17:16:22 by ikalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	size_t			i;
	size_t			total;
	unsigned char	*byte_ptr;

	total = nmemb * size;
	if (nmemb != 0 && total / nmemb != size)
		return (NULL);
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	byte_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < total)
		byte_ptr[i++] = 0;
	return (ptr);
}
