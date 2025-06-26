/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalkan <ikalkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:21:51 by ikalkan           #+#    #+#             */
/*   Updated: 2025/06/18 13:06:07 by ikalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	d;
	char	*ptr;
	size_t	i;

	d = ft_strlen(s);
	ptr = (char *)malloc(d + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < d)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
